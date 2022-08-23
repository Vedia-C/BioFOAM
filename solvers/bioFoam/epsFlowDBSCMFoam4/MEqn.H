//volScalarField Mmax("Mmax",4);
//volScalarField Db("Db",a*pow(Mb*ops/(Mmax-Mb),4.0));
/*volScalarField k1("k1",k1=Mmax*(mum/Yxs+ms))
volScalarField k3("k3",k3=Yxs/Mmax)
volScalarField k4("k4",k4=Mmax*ms)
*/

 {   fvScalarMatrix MEqn//构造体积矢量场矩阵
    (
	//Inertial Terms
        fvm::ddt(MbbyMmax) 

      ==c*fvm::laplacian(pow(MbbyMmax*ops/(1.0-MbbyMmax),4.),MbbyMmax) + Mmax*(mum/Yxs+ms)*(Yxs/Mmax)*CbyC0*MbbyMmax/(ks/C0+CbyC0)-(Yxs/Mmax)*(ms*Mmax)*MbbyMmax


//Yxs/Mmax*(Mmax*(mum/Yxs+ms)*CbyC0*MbbyMmax/(ks/C0+CbyC0)-Mmax*ms*MbbyMmax)
    );
    MEqn.solve(); 
    
 
	
     

    forAll(eps,celli) 
    {
      if(eps[celli]<0.00011) 
      
                { //MbbyMmax[celli] = 1; 
                MbbyMmax[celli] =0;}
    }
   
   forAll(MbbyMmax,celli) 
    {
      if(MbbyMmax[celli]>0.99) 
      
                { //MbbyMmax[celli] = 1; 
                eps[celli] =0.0002;}
    }


 /*  forAll(MbbyMmax,celli)
   {
       if(MbbyMmax[celli] >= 1)
        {Solid[celli] = 1;
         eps[celli] =0;
        }
        else
        {Solid[celli] = 0;
        eps[celli] = 1;

        }


        forAll(eps,celli) 
   {
    if(eps[celli]>0.1) 
         {
            if(MbbyMmax[celli]<1) 
      
                {MEqn.solve(); }
  }


  else
    {
    MbbyMmax[celli] = 0;
    }
*/



   }
 
 //  MbbyMmax.max(1);
//cout << "BEGIN" << endl;
//cout << "cellCells():" << cellCells() << endl;
//cout << "BEGIN" << endl;


//if ( mesh().lookupObject<volScalarField>("Mb") > 4 )
//{ eps=0.000001; }
/*
forAll(MbbyMmax, celli)
{
    if (MbbyMmax[celli] > 1)
    {
        eps[celli] = 0;
      //  Solid[celli]=1;
       U[celli].component(0) = 0;
       U[celli].y()=0;
       U[celli].component(2)=0;
    }
    forAll(eps,celli) 
    {
  	if(eps[celli]>0.99) 
	{	
	Solid[celli]=0; 
	}
	else
	{
	Solid[celli]=1; 
	}
    }

}

*/



