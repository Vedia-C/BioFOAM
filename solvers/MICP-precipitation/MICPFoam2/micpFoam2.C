/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    hybridPorousInterFoam

Description
    Solver for two-phase flow in hybrid-scale porous media containing porous 
    and solid-free regions. 
    
    In porous regions fluid flow is governed by two-phase Darcy's law
     
    In solid-free regions flow is modeled through the volume of fluid
    phase-fraction based interface capturing approach.

    The momentum and other fluid properties are of the "mixture" and a single
    momentum equation is solved.

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "CMULES.H"
#include "EulerDdtScheme.H"
#include "localEulerDdtScheme.H"
#include "CrankNicolsonDdtScheme.H"
#include "subCycle.H"
//#include "porousImmiscibleIncompressibleTwoPhaseMixture.H"
//#include "pimpleControl.H"
#include "localEulerDdtScheme.H"
#include "fvcSmooth.H"
#include "pisoControl.H"
//#include "turbulentTransportModel.H"
//#include "capillarityModel.H"
//#include "relativePermeabilityModel.H"
#include "singlePhaseTransportModel.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    #include "postProcess.H"
    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createControl.H"
    #include "createTimeControls.H"
    #include "createRDeltaT.H"
    #include "initContinuityErrs.H"
    #include "createFields.H"

   

    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

    Info<< "\nStarting time loop\n" << endl;

    while (runTime.loop())
    {
        Info<< "Time = " << runTime.timeName() << nl << endl;

        #include "CourantNo.H"
        volScalarField  mt ("mt",fvc::ddt(Ccaco3));
        // --- Pressure-velocity PIMPLE corrector loop
       
        {
	  //  #include "updateVariables.H"
           // #include "epsEqn.H"
            #include "UEqn.H"
       	    
             //--- Pressure corrector loop
            while (piso.correct())
            {
                #include "pEqn.H"
                
            }
            #include "CEqn.H"
              //  #include "epsEqn.H"
               #include "CureaEqn.H"
              #include "CNH4Eqn.H"
              #include "CcaEqn.H"
              #include "Cco3Eqn.H"
             // #include "Ccaco3Eqn.H"
            Ccaco3=Ccaco3+ b*Kp*min(Cca,Cco3)*MWCaCO3*eps*mesh.time().deltaTValue(); 
            mt=fvc::ddt(Ccaco3);
             eps= eps - a*(1./rhoCaCO3)*mt*eps.oldTime(); 
           //   #include "MEqn.H"
             // #include "epsEqn.H"

 #include "updateVariables.H"
        }

        

        runTime.write();

        Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
            << "  ClockTime = " << runTime.elapsedClockTime() << " s"
            << nl << endl;

    };
     
    ; Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
