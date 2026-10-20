# Rhel 9
module use /opt/scorec/spack/rhel9/v0222_2/lmod/linux-rhel9-x86_64/Core/
module load gcc/13.2.0-4eahhas
module load mpich/4.2.3-62uy3hd
module load pumi/develop-simmodsuite-2026.1-261010-int32-shared-urusglz
module load cmake
export LD_LIBRARY_PATH=/users/riazu2/lore.scorec.rpi.edu/Tools/install/OmegaH/gcc13.2.0/lib64:$LD_LIBRARY_PATH
