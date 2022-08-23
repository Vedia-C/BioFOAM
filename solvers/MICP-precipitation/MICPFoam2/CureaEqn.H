//volScalarField av ("av",mag(fvc::grad(eps)));
//volScalarField k1 ("k1", Mmax*(mum/Yxs+ms));
//volScalarField k3 ("k3", Yxs/Mmax);
//volScalarField k4 ("k4", Mmax*ms);

 {   fvScalarMatrix CureaEqn//构造体积矢量场矩阵
    (
	//Inertial Terms
        fvm::ddt(eps, Curea)
       + fvm::div(phi,Curea) 

	//Viscous Terms
      == fvm::laplacian(eps*Durea,Curea)
         -MbbyMmax*Mmax*Ku*eps*(Curea/(Km+Curea))*(KNH4/(KNH4+CNH4))
    );

    CureaEqn.solve();
}


