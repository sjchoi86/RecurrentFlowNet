/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * set_nei4u_unit_initialize.c
 *
 * Code generation for function 'set_nei4u_unit_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "set_nei4u_unit.h"
#include "set_nei4u_unit_initialize.h"
#include "set_nei4u_unit_data.h"

/* Function Definitions */
void set_nei4u_unit_initialize(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (set_nei4u_unit_initialize.c) */
