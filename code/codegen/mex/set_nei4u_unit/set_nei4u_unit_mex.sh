MATLAB="/Applications/MATLAB_R2015b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/human/.matlab/R2015b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for set_nei4u_unit" > set_nei4u_unit_mex.mki
echo "CC=$CC" >> set_nei4u_unit_mex.mki
echo "CFLAGS=$CFLAGS" >> set_nei4u_unit_mex.mki
echo "CLIBS=$CLIBS" >> set_nei4u_unit_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> set_nei4u_unit_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> set_nei4u_unit_mex.mki
echo "CXX=$CXX" >> set_nei4u_unit_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> set_nei4u_unit_mex.mki
echo "CXXLIBS=$CXXLIBS" >> set_nei4u_unit_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> set_nei4u_unit_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> set_nei4u_unit_mex.mki
echo "LD=$LD" >> set_nei4u_unit_mex.mki
echo "LDFLAGS=$LDFLAGS" >> set_nei4u_unit_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> set_nei4u_unit_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> set_nei4u_unit_mex.mki
echo "Arch=$Arch" >> set_nei4u_unit_mex.mki
echo OMPFLAGS= >> set_nei4u_unit_mex.mki
echo OMPLINKFLAGS= >> set_nei4u_unit_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> set_nei4u_unit_mex.mki
echo "EMC_CONFIG=optim" >> set_nei4u_unit_mex.mki
"/Applications/MATLAB_R2015b.app/bin/maci64/gmake" -B -f set_nei4u_unit_mex.mk
