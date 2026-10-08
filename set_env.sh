# Rhel 9
module use /opt/scorec/spack/rhel9/v0201_4/lmod/linux-rhel9-x86_64/Core/
module load zlib/1.2.13-mvjz5oi gcc/12.3.0-iil3lno mpich/4.1.1-xpoyz4t cmake
module load simmetrix-simmodsuite/2025.1-250602dev-yv5oiom
export LD_LIBRARY_PATH=/users/riazu2/lore.scorec.rpi.edu/Tools/install/OmegaH/gcc12.3.0/lib64/withoutAdios2:$LD_LIBRARY_PATH
