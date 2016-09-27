/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * set_nei_unit_terminate.c
 *
 * Code generation for function 'set_nei_unit_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "set_nei_unit.h"
#include "set_nei_unit_terminate.h"
#include "set_nei_unit_data.h"

/* Function Definitions */
void set_nei_unit_atexit(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void set_nei_unit_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (set_nei_unit_terminate.c) */
