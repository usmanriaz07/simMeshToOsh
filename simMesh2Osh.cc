#include <iostream>
#include <fstream>
#include <cstring>
#include <memory>
#include "SimUtil.h"
#include "SimModel.h"
#include "SimAdvModel.h"
#include "SimDiscrete.h"
#include "SimParasolidKrnl.h"
#include "SimPartitionedMesh.h"
#include "Omega_h_build.hpp"
#include "Omega_h_mesh.hpp"
#include "Omega_h_file.hpp"

/******************************************************
 ********************* Structs ***********************/

// Struct to hold input data.
struct Inputs{
  std::string simMeshName;  // input Simmetrix mesh
  std::string outputName = "output.osh";  // output file name
};

/*****************************************************************************
 ************************** Function Definitions ****************************/

/*
 * Function to verify the inputs.
 * Returns the struct Inputs that contains all the inputs.
 */
Inputs verifyInputs(int argc, char** argv);

/********************************************************************************
 ************************************** Main Function **************************/
int main(int argc, char* argv[])
{
  // Step 0: Initialize MPI
  MPI_Init(&argc,&argv);
  {  

    // Step 1: Verify the inputs
    Inputs in = verifyInputs(argc, argv);

    // Step 2: Initialize Simmetrix libraries and read the license.
    Sim_readLicenseFile("/net/common/meshSim/license/license.txt");
    MS_init();

    // Step 3: Load Simmetrix mesh
    std::cout << "Loading Simmetrix mesh (.sms) ...\n";
    pMesh simMesh = M_load(in.simMeshName.c_str(), NULL, NULL);
    std::cout << "Loaded " << in.simMeshName << " successfully\n"; 

    // Step 4: Write Omegah mesh
    auto lib = Omega_h::Library(NULL, NULL);
    auto comm = lib.world();
    auto mesh = Omega_h::meshsim::read(&simMesh, std::string(""), comm); 

    // STep 4.1: Write Omegah mesh to the disk
    Omega_h::binary::write(in.outputName, &mesh);
    std::cout << "Output Mesh File: " << in.outputName << "\n";  
 
    // Step 5: Release Simmetrix objects and stop the libraries.
    M_release(simMesh);
    Sim_unregisterAllKeys();
    MS_exit();

  }
  // Step 6: Terminate the MPI environment.
  MPI_Finalize();
}

// Function to check if a string has given extension
// or not.
bool hasExtension(std::string s, std::string ext) 
{
  if(s.substr(s.find_last_of(".") + 1) == ext) 
    return true;
  else 
    return false;
}

// Function to verify the inputs.
Inputs verifyInputs(int argc, char** argv)
{
  // Step 1: Verify we have the input file
  if (argc < 2)
  {
    std::cout << "Inputs Missing\n";
    std::cout << "Usage: ./simMesh2Osh SimmetrixMesh.sms outputOmegahMesh.osh(optional)\n";
    exit(1);
  }

  // Step 2: Read the input simmetrix mesh file
  Inputs in;
  in.simMeshName = argv[1];
  if (!hasExtension(in.simMeshName, "sms"))
  {
    std::cout << "Simmetrix mesh with extension .sms could not be found\n";
    std::cout << "Check mesh name provided in the argument 2\n";
    exit(1);
  }
    
  // Step 3: Read output file name
  if (argc == 3)
  {
    std::string outputFileName = argv[2];
    if (!hasExtension(outputFileName, "osh"))
      outputFileName = outputFileName + ".osh";  

    in.outputName = outputFileName;
  }
  
  // Step 4: Return verified inputs
  return in;
}
