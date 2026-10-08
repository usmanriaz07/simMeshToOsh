cmake_minimum_required(VERSION 3.9...3.27)
project(SimToOsh VERSION 1.0.0 LANGUAGES C CXX)

include(GNUInstallDirs)

# Let CMake know where to find custom FindFoo.cmake files
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

# Find the common packages needed.
find_package(MPI COMPONENTS CXX REQUIRED)
find_package(OpenMP COMPONENTS CXX REQUIRED)

find_package(SimModSuite) #modify to take argForDebug and internal flags
find_package(Omega_h REQUIRED)

add_executable(simMesh2Osh simMesh2Osh.cc)

target_include_directories(simMesh2Osh PUBLIC 
  ${SIMMODSUITE_INCLUDE_DIR}
)

target_link_libraries(simMesh2Osh PUBLIC 
   MPI::MPI_CXX OpenMP::OpenMP_CXX
   ${SIMMODSUITE_LIBS}
   Omega_h::omega_h
)

install(TARGETS simMesh2Osh 
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
