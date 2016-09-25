/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_int_forloop_overflow_check.c
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forcePushIntoCloud.h"
#include "occflow.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = { 87, 9, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

/* Function Definitions */
void check_forloop_overflow_error(const emlrtStack *sp)
{
  static const char_T cv0[5] = { 'i', 'n', 't', '3', '2' };

  emlrtErrorWithMessageIdR2012b(sp, &n_emlrtRTEI,
    "Coder:toolbox:int_forloop_overflow", 3, 4, 5, cv0);
}

/* End of code generation (eml_int_forloop_overflow_check.c) */
