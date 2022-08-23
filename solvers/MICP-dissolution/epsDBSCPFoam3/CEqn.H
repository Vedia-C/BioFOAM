//volScalarField av ("av",mag(fvc::grad(eps)));
//volScalarField k1 ("k1", Mmax*(mum/Yxs+ms));
//volScalarField k3 ("k3", Yxs/Mmax);
//volScalarField k4 ("k4", Mmax*ms);

 {   fvScalarMatrix CEqn//构造体积矢量场矩阵
    (
	//Inertial Terms
        fvm::ddt(eps, C)
       + fvm::div(phi,C) 

	//Viscous Terms
      == fvm::laplacian(eps*D,C)
     - Madot
  );

    CEqn.solve();
}


