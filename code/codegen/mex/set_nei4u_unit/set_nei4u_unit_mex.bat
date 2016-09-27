@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=set_nei4u_unit_mex
set MEX_NAME=set_nei4u_unit_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for set_nei4u_unit > set_nei4u_unit_mex.mki
echo COMPILER=%COMPILER%>> set_nei4u_unit_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> set_nei4u_unit_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> set_nei4u_unit_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> set_nei4u_unit_mex.mki
echo LINKER=%LINKER%>> set_nei4u_unit_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> set_nei4u_unit_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> set_nei4u_unit_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> set_nei4u_unit_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> set_nei4u_unit_mex.mki
echo BORLAND=%BORLAND%>> set_nei4u_unit_mex.mki
echo OMPFLAGS= >> set_nei4u_unit_mex.mki
echo OMPLINKFLAGS= >> set_nei4u_unit_mex.mki
echo EMC_COMPILER=msvc120>> set_nei4u_unit_mex.mki
echo EMC_CONFIG=optim>> set_nei4u_unit_mex.mki
"C:\Program Files\MATLAB\R2015a\bin\win64\gmake" -B -f set_nei4u_unit_mex.mk
