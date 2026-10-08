SIM_VER=simmetrix-simmodsuite-2025.1-250602dev-yv5oiomk2sdcru5cn5vqjxprycytc4ow
SIM_ARCHOS=x64_rhel9_gcc11
OMEGAH_DIR=/users/riazu2/lore.scorec.rpi.edu/Tools/install/OmegaH/gcc12.3.0
PREFIX=/users/riazu2/lore.scorec.rpi.edu/Tools/install/simMesh2Osh/install
CMAKETYPE=Debug
cmake .. \
  -DCMAKE_C_COMPILER=mpicc \
  -DCMAKE_CXX_COMPILER=mpicxx \
  -DCMAKE_C_FLAGS="-g -O0" \
  -DCMAKE_CXX_FLAGS="-g -O0" \
  -DSIM_MPI=mpich4.1.1 \
  -DSIMMETRIX_INCLUDE_DIR=/opt/scorec/spack/rhel9/v0201_4/install/linux-rhel9-x86_64/gcc-12.3.0/$SIM_VER/include \
  -DSIMMETRIX_LIB_DIR=/opt/scorec/spack/rhel9/v0201_4/install/linux-rhel9-x86_64/gcc-12.3.0/$SIM_VER/lib/$SIM_ARCHOS \
  -DOmega_h_DIR=$OMEGAH_DIR/lib64/cmake/Omega_h \
  -DSIM_PARASOLID=ON \
  -DCMAKE_INSTALL_PREFIX="$PREFIX" \
  -DCMAKE_BUILD_TYPE=$CMAKETYPE
