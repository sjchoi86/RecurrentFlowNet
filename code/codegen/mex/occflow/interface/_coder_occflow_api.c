/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_occflow_api.c
 *
 * Code generation for function '_coder_occflow_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "occflow.h"
#include "_coder_occflow_api.h"
#include "occflow_emxutil.h"
#include "occflow_data.h"

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static void b_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);
static void c_emlrt_marshallIn(const mxArray *context, const char_T *identifier,
  emxArray_real_T *y);
static void c_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static real_T e_emlrt_marshallIn(const mxArray *nei_filter_n, const char_T
  *identifier);
static void emlrt_marshallIn(const mxArray *cgridvec, const char_T *identifier,
  emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);
static void h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);
static real_T i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  g_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 1);
}

static void c_emlrt_marshallIn(const mxArray *context, const char_T *identifier,
  emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(emlrtAlias(context), &thisId, y);
  emlrtDestroyArray(&context);
}

static void c_emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  h_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const mxArray *nei_filter_n, const char_T
  *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(emlrtAlias(nei_filter_n), &thisId);
  emlrtDestroyArray(&nei_filter_n);
  return y;
}

static void emlrt_marshallIn(const mxArray *cgridvec, const char_T *identifier,
  emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(emlrtAlias(cgridvec), &thisId, y);
  emlrtDestroyArray(&cgridvec);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv0[1] = { 0 };

  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u->data);
  emlrtSetDimensions((mxArray *)m0, u->size, 1);
  emlrtAssign(&y, m0);
  return y;
}

static real_T f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv1[1];
  boolean_T bv0[1] = { true };

  static const int32_T iv2[1] = { -1 };

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
    iv2, &bv0[0], iv1);
  ret->size[0] = iv1[0];
  ret->allocatedSize = ret->size[0];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv3[2];
  int32_T i;
  int32_T iv4[2];
  boolean_T bv1[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv3[i] = -1;
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    iv3, &bv1[0], iv4);
  ret->size[0] = iv4[0];
  ret->size[1] = iv4[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
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
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&cgridvec, 1, true);
  emxInit_real_T(&cgridvecprev, 1, true);
  b_emxInit_real_T(&context, 2, true);
  b_emxInit_real_T(&nei_idx, 2, true);
  b_emxInit_real_T(&nei_weight, 2, true);
  b_emxInit_real_T(&nei4u_idx, 2, true);
  b_emxInit_real_T(&nei4u_weight, 2, true);
  emxInit_real_T(&predvec, 1, true);
  emxInit_real_T(&maxvec, 1, true);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, true, -1);
  prhs[2] = emlrtProtectR2012b(prhs[2], 2, true, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(emlrtAlias(prhs[0]), "cgridvec", cgridvec);
  emlrt_marshallIn(emlrtAlias(prhs[1]), "cgridvecprev", cgridvecprev);
  c_emlrt_marshallIn(emlrtAlias(prhs[2]), "context", context);
  c_emlrt_marshallIn(emlrtAlias(prhs[3]), "nei_idx", nei_idx);
  c_emlrt_marshallIn(emlrtAlias(prhs[4]), "nei_weight", nei_weight);
  nei_filter_n = e_emlrt_marshallIn(emlrtAliasP(prhs[5]), "nei_filter_n");
  c_emlrt_marshallIn(emlrtAlias(prhs[6]), "nei4u_idx", nei4u_idx);
  c_emlrt_marshallIn(emlrtAlias(prhs[7]), "nei4u_weight", nei4u_weight);
  nei4u_filter_n = e_emlrt_marshallIn(emlrtAliasP(prhs[8]), "nei4u_filter_n");
  occval = e_emlrt_marshallIn(emlrtAliasP(prhs[9]), "occval");
  minthreshold = e_emlrt_marshallIn(emlrtAliasP(prhs[10]), "minthreshold");
  maxthreshold = e_emlrt_marshallIn(emlrtAliasP(prhs[11]), "maxthreshold");
  reinitval = e_emlrt_marshallIn(emlrtAliasP(prhs[12]), "reinitval");
  intensifyrate = e_emlrt_marshallIn(emlrtAliasP(prhs[13]), "intensifyrate");
  nocc_attenuaterate = e_emlrt_marshallIn(emlrtAliasP(prhs[14]),
    "nocc_attenuaterate");
  unknown_attenuaterate = e_emlrt_marshallIn(emlrtAliasP(prhs[15]),
    "unknown_attenuaterate");
  sigm_coef = e_emlrt_marshallIn(emlrtAliasP(prhs[16]), "sigm_coef");

  /* Invoke the target function */
  occflow(cgridvec, cgridvecprev, context, nei_idx, nei_weight, nei_filter_n,
          nei4u_idx, nei4u_weight, nei4u_filter_n, occval, minthreshold,
          maxthreshold, reinitval, intensifyrate, nocc_attenuaterate,
          unknown_attenuaterate, sigm_coef, predvec, maxvec);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(predvec);
  b_emlrt_marshallOut(cgridvecprev, prhs[1]);
  plhs[1] = prhs[1];
  c_emlrt_marshallOut(context, prhs[2]);
  plhs[2] = prhs[2];
  plhs[3] = emlrt_marshallOut(maxvec);
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
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (_coder_occflow_api.c) */
