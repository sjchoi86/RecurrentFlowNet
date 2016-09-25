/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_occflow_float_mex_api.c
 *
 * Code generation for function '_coder_occflow_float_mex_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forcePushIntoCloud.h"
#include "occflow.h"
#include "_coder_occflow_float_mex_api.h"
#include "occflow_float_mex_emxutil.h"
#include "occflow_float_mex_data.h"

/* Variable Definitions */
static emlrtRTEInfo b_emlrtRTEI = { 1, 1, "_coder_occflow_float_mex_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *context,
  const char_T *identifier, emxArray_real_T *y);
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void d_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *nei_filter_n, const char_T *identifier);
static void e_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *cgridvec,
  const char_T *identifier, emxArray_real_T *y);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *context,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(context), &thisId, y);
  emlrtDestroyArray(&context);
}

static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv0[1] = { 0 };

  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)u->data);
  emlrtSetDimensions((mxArray *)m2, u->size, 1);
  emlrtAssign(&y, m2);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 1);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *nei_filter_n, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(nei_filter_n), &thisId);
  emlrtDestroyArray(&nei_filter_n);
  return y;
}

static void e_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *cgridvec,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(cgridvec), &thisId, y);
  emlrtDestroyArray(&cgridvec);
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv1[1];
  boolean_T bv0[1] = { true };

  static const int32_T dims[1] = { -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv0[0],
    iv1);
  ret->size[0] = iv1[0];
  ret->allocatedSize = ret->size[0];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv2[2];
  boolean_T bv1[2] = { true, true };

  static const int32_T dims[2] = { -1, -1 };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv1[0],
    iv2);
  ret->size[0] = iv2[0];
  ret->size[1] = iv2[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void forcePushIntoCloud_api(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Invoke the target function */
  forcePushIntoCloud(&st);
}

void occflow_api(const mxArray *prhs[17], const mxArray *plhs[4])
{
  emxArray_real_T *cgridvec;
  emxArray_real_T *cgridvecprev;
  emxArray_real_T *context;
  emxArray_real_T *nei_idx;
  emxArray_real_T *nei_weight;
  emxArray_real_T *nei4u_idx;
  emxArray_real_T *nei4u_weight;
  emxArray_real_T *predvec;
  emxArray_real_T *maxvec;
  real_T nei_filter_n;
  real_T nei4u_filter_n;
  real_T occval;
  real_T minthreshold;
  real_T maxthreshold;
  real_T reinitval;
  real_T intensifyrate;
  real_T nocc_attenuaterate;
  real_T unknown_attenuaterate;
  real_T sigm_coef;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &cgridvec, 1, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &cgridvecprev, 1, &b_emlrtRTEI, true);
  emxInit_real_T1(&st, &context, 2, &b_emlrtRTEI, true);
  emxInit_real_T1(&st, &nei_idx, 2, &b_emlrtRTEI, true);
  emxInit_real_T1(&st, &nei_weight, 2, &b_emlrtRTEI, true);
  emxInit_real_T1(&st, &nei4u_idx, 2, &b_emlrtRTEI, true);
  emxInit_real_T1(&st, &nei4u_weight, 2, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &predvec, 1, &b_emlrtRTEI, true);
  emxInit_real_T(&st, &maxvec, 1, &b_emlrtRTEI, true);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, true, -1);
  prhs[2] = emlrtProtectR2012b(prhs[2], 2, true, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "cgridvec", cgridvec);
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "cgridvecprev", cgridvecprev);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "context", context);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "nei_idx", nei_idx);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "nei_weight", nei_weight);
  nei_filter_n = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "nei_filter_n");
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "nei4u_idx", nei4u_idx);
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "nei4u_weight", nei4u_weight);
  nei4u_filter_n = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]),
    "nei4u_filter_n");
  occval = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "occval");
  minthreshold = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "minthreshold");
  maxthreshold = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "maxthreshold");
  reinitval = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "reinitval");
  intensifyrate = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "intensifyrate");
  nocc_attenuaterate = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]),
    "nocc_attenuaterate");
  unknown_attenuaterate = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[15]),
    "unknown_attenuaterate");
  sigm_coef = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "sigm_coef");

  /* Invoke the target function */
  occflow(&st, cgridvec, cgridvecprev, context, nei_idx, nei_weight,
          nei_filter_n, nei4u_idx, nei4u_weight, nei4u_filter_n, occval,
          minthreshold, maxthreshold, reinitval, intensifyrate,
          nocc_attenuaterate, unknown_attenuaterate, sigm_coef, predvec, maxvec);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(predvec);
  d_emlrt_marshallOut(cgridvecprev, prhs[1]);
  plhs[1] = prhs[1];
  e_emlrt_marshallOut(context, prhs[2]);
  plhs[2] = prhs[2];
  plhs[3] = c_emlrt_marshallOut(maxvec);
  maxvec->canFreeData = false;
  emxFree_real_T(&maxvec);
  predvec->canFreeData = false;
  emxFree_real_T(&predvec);
  nei4u_weight->canFreeData = false;
  emxFree_real_T(&nei4u_weight);
  nei4u_idx->canFreeData = false;
  emxFree_real_T(&nei4u_idx);
  nei_weight->canFreeData = false;
  emxFree_real_T(&nei_weight);
  nei_idx->canFreeData = false;
  emxFree_real_T(&nei_idx);
  context->canFreeData = false;
  emxFree_real_T(&context);
  cgridvecprev->canFreeData = false;
  emxFree_real_T(&cgridvecprev);
  cgridvec->canFreeData = false;
  emxFree_real_T(&cgridvec);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_occflow_float_mex_api.c) */
