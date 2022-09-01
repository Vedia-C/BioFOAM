# BioFOAM
### Author: Yurong Yang, Xueying Li, Xiaofan Yang*
### Address: Faculty of Geographical Science, Beijing Normal University

The model, BioFOAM, is developed based on OpenFOAM software. This code includes three types of solvers that deal with flow and solute transport (DBS equation), Microbial-Induced Calcite Precipitation (MICP), and biofilm growth processes in porous media.

1. DBS flow model (OpenFOAM, version 8)

Two solvers named FlowDBSFoam and FlowDBSCFoam (in the folder solvers/DBS) were developed to solve flow and solute transport processes. Three verification cases were demonstrated in the folder cases/Flow. The DBSFlowCase solves fluid flow in a square with no solute. The DBSFlowCCase solves solute transport in a square. The DBSFlowCase-Pore-Darcy solves fluid flow transport from a Darcy (REV) scale region into a pore scale region.

2. MICP model (OpenFOAM, version 7)

Two solvers named epsDBSCPFoam3 (in the folder solvers/MICP-dissolution) and MICPFoam2 (in the folder solvers/MICP-precipitation) were developed to solve the dissolution and precipitation processes that were induced by microbial activity. Validation cases were demonstrated in the folder cases/MICP. We set up a series of tested by varying the initial concentration in the folder cases/MICP/dissolution and cases/MICP/precipitation.

3. Biofilm Growth model (OpenFOAM, version 7)

The solver, epsFlowDBSCMFoam4 (in the folder solvers/bioFoam), was able to simulate biofilm growth for single pore (cases/Biofilm_growth/single_pore), multi pores (cases/Biofilm_growth/multi_pores) and 3D box (cases/Biofilm_growth/3D) cases. Validation cases were demonstrated in the folder cases/Biofilm_growth.


