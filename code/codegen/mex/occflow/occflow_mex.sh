MATLAB="/Applications/MATLAB_R2015b.app"
Arch=maci64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/Users/human/.matlab/R2015b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for occflow" > occflow_mex.mki
echo "CC=$CC" >> occflow_mex.mki
echo "CFLAGS=$CFLAGS" >> occflow_mex.mki
echo "CLIBS=$CLIBS" >> occflow_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> occflow_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> occflow_mex.mki
echo "CXX=$CXX" >> occflow_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> occflow_mex.mki
echo "CXXLIBS=$CXXLIBS" >> occflow_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> occflow_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> occflow_mex.mki
echo "LD=$LD" >> occflow_mex.mki
echo "LDFLAGS=$LDFLAGS" >> occflow_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> occflow_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> occflow_mex.mki
echo "Arch=$Arch" >> occflow_mex.mki
echo OMPFLAGS= >> occflow_mex.mki
echo OMPLINKFLAGS= >> occflow_mex.mki
echo "EMC_COMPILER=Xcode with Clang" >> occflow_mex.mki
echo "EMC_CONFIG=optim" >> occflow_mex.mki
"/Applications/MATLAB_R2015b.app/bin/maci64/gmake" -B -f occflow_mex.mk
