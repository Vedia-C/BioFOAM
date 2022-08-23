# BioFOAM
### Author: Yurong Yang, Xueying Li, Xiaofan Yang*
### Address: Faculty of Geographical Science, Beijing Normal University

The model, BioFOAM, is developed based on OpenFOAM software. This code includes three types of solvers that deal with flow and solute transport (DBS equation), Microbial-Induced Calcite Precipitation (MICP), and biofilm growth processes in porous media. 

1. DBS flow model (OpenFOAM, version 8)
Two solvers named FlowDBSFoam and FlowDBSCFoam were developed to solve flow and solute transport processes. Three verification cases were demonstrated in the folder cases/Flow.

2. MICP model (OpenFOAM, version 7)
Two solvers named epsDBSCPFoam3 and MICPFoam2 were developed to solve the dissolution and precipitation processes that were induced by microbial activity. Validation cases were demonstrated in the folder cases/MICP.

3. Biofilm Growth model (OpenFOAM, version 7)
The solver, epsFlowDBSCMFoam4, was able to simulate biofilm growth for single pore, multi pores and 3D box cases. Validation cases were demonstrated in the folder cases/Biofilm_growth.
