@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=occflow_mex
set MEX_NAME=occflow_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for occflow > occflow_mex.mki
echo COMPILER=%COMPILER%>> occflow_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> occflow_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> occflow_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> occflow_mex.mki
echo LINKER=%LINKER%>> occflow_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> occflow_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> occflow_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> occflow_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> occflow_mex.mki
echo BORLAND=%BORLAND%>> occflow_mex.mki
echo OMPFLAGS= >> occflow_mex.mki
echo OMPLINKFLAGS= >> occflow_mex.mki
echo EMC_COMPILER=msvc120>> occflow_mex.mki
echo EMC_CONFIG=optim>> occflow_mex.mki
"C:\Program Files\MATLAB\R2015a\bin\win64\gmake" -B -f occflow_mex.mk
