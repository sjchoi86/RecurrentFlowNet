/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * occflow_initialize.c
 *
 * Code generation for function 'occflow_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "occflow.h"
#include "occflow_initialize.h"
#include "occflow_data.h"

/* Function Definitions */
void occflow_initialize(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (occflow_initialize.c) */
