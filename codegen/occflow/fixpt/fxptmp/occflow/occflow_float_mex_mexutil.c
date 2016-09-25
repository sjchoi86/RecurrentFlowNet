/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * occflow_float_mex_mexutil.c
 *
 * Code generation for function 'occflow_float_mex_mexutil'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forcePushIntoCloud.h"
#include "occflow.h"
#include "occflow_float_mex_mexutil.h"

/* Function Definitions */
void emlrtInitVarDataTables(emlrtLocationLoggingDataType dataTables[75])
{
  int32_T i;
  for (i = 0; i < 75; i++) {
    dataTables[i].SimMin = rtInf;
    dataTables[i].SimMax = rtMinusInf;
    dataTables[i].OverflowWraps = 0;
    dataTables[i].Saturations = 0;
    dataTables[i].IsAlwaysInteger = true;
    dataTables[i].HistogramTable = (emlrtLocationLoggingHistogramType *)NULL;
  }
}

/* End of code generation (occflow_float_mex_mexutil.c) */
