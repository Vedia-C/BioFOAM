

 {   fvScalarMatrix Ccaco3Eqn//构造体积矢量场矩阵
    (
	//Inertial Terms
        fvm::ddt(Ccaco3)
      // + fvm::div(phi,Ccaco3) 

	//Viscous Terms
      == //fvm::laplacian(eps*Dco3,Cco3)
        // + M*Ku*eps*(Curea/(Km+Curea))*(KNH4/(KNH4+CNH4))
          Kp*min(Cca,Cco3)*MWCaCO3*eps*b
    );

 //   Ccaco3Eqn.solve();
/*forAll(eps,celli) 
   {
  	if(eps[celli] > 0.1) 
         {Ccaco3Eqn.solve(); }


	else
		{
		Ccaco3[celli] = 0;
		}
        
	
   }*?






/*forAll(Ccaco3,celli)
{
    if (Ccaco3[celli] > 1e-29)
    {
        Solid[celli] = 1;
      //  Sattach[celli] = 1;
      //  Solid[celli]=1;
      // U[celli].component(0) = 0;
       //U[celli].y()=0;
       //U[celli].component(2)=0;
    }
    else 
   {
         Solid[celli] = 0;
      //  Sattach[celli] = 0;

   }

} ;  

*/


}


