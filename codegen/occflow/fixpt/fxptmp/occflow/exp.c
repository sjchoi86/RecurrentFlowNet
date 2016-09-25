/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * exp.c
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forcePushIntoCloud.h"
#include "occflow.h"
#include "exp.h"
#include "eml_int_forloop_overflow_check.h"
#include "occflow_float_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 9, "exp",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elfun/exp.m" };

static emlrtRSInfo ab_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"
};

/* Function Definitions */
void b_exp(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &y_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[0];
  b_st.site = &ab_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muDoubleScalarExp(x->data[k]);
  }
}

/* End of code generation (exp.c) */
