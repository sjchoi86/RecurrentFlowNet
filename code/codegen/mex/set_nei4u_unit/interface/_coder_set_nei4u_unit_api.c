/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_set_nei4u_unit_api.c
 *
 * Code generation for function '_coder_set_nei4u_unit_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "set_nei4u_unit.h"
#include "_coder_set_nei4u_unit_api.h"
#include "set_nei4u_unit_emxutil.h"
#include "set_nei4u_unit_data.h"

/* Function Declarations */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static real_T c_emlrt_marshallIn(const mxArray *g_n, const char_T *identifier);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void e_emlrt_marshallIn(const mxArray *g_xyidx, const char_T *identifier,
  emxArray_real_T *y);
static void emlrt_marshallIn(const mxArray *nei_nei_idx, const char_T
  *identifier, emxArray_real_T *y);
static void emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y);
static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static void g_emlrt_marshallIn(const mxArray *nei_filter_weight, const char_T
  *identifier, emxArray_real_T *y);
static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y);
static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);
static real_T j_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);
static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret);

/* Function Definitions */
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  i_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const mxArray *g_n, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(emlrtAlias(g_n), &thisId);
  emlrtDestroyArray(&g_n);
  return y;
}

static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const mxArray *g_xyidx, const char_T *identifier,
  emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  f_emlrt_marshallIn(emlrtAlias(g_xyidx), &thisId, y);
  emlrtDestroyArray(&g_xyidx);
}

static void emlrt_marshallIn(const mxArray *nei_nei_idx, const char_T
  *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(emlrtAlias(nei_nei_idx), &thisId, y);
  emlrtDestroyArray(&nei_nei_idx);
}

static void emlrt_marshallOut(const emxArray_real_T *u, const mxArray *y)
{
  mxSetData((mxArray *)y, (void *)u->data);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

static void f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  k_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const mxArray *nei_filter_weight, const char_T
  *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  h_emlrt_marshallIn(emlrtAlias(nei_filter_weight), &thisId, y);
  emlrtDestroyArray(&nei_filter_weight);
}

static void h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, emxArray_real_T *y)
{
  l_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv0[2];
  int32_T i;
  int32_T iv1[2];
  boolean_T bv0[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv0[i] = -1;
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    iv0, &bv0[0], iv1);
  ret->size[0] = iv1[0];
  ret->size[1] = iv1[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T j_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv2[2];
  int32_T i0;
  int32_T iv3[2];
  boolean_T bv1[2] = { true, false };

  for (i0 = 0; i0 < 2; i0++) {
    iv2[i0] = 3 * i0 - 1;
  }

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    iv2, &bv1[0], iv3);
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
  ret->allocatedSize = ret->size[0] * ret->size[1];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, emxArray_real_T *ret)
{
  int32_T iv4[1];
  boolean_T bv2[1] = { true };

  static const int32_T iv5[1] = { -1 };

  emlrtCheckVsBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
    iv5, &bv2[0], iv4);
  ret->size[0] = iv4[0];
  ret->allocatedSize = ret->size[0];
  ret->data = (real_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

void set_nei4u_unit_api(const mxArray *prhs[9], const mxArray *plhs[2])
{
  emxArray_real_T *nei_nei_idx;
  emxArray_real_T *nei_nei_weight;
  emxArray_real_T *g_xyidx;
  emxArray_real_T *nei_filter_shift_xyi;
  emxArray_real_T *nei_filter_weight;
  real_T g_n;
  real_T nei_filter_n;
  real_T g_nx;
  real_T g_ny;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&nei_nei_idx, 2, true);
  emxInit_real_T(&nei_nei_weight, 2, true);
  emxInit_real_T(&g_xyidx, 2, true);
  emxInit_real_T(&nei_filter_shift_xyi, 2, true);
  b_emxInit_real_T(&nei_filter_weight, 1, true);
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, true, -1);
  prhs[1] = emlrtProtectR2012b(prhs[1], 1, true, -1);

  /* Marshall function inputs */
  emlrt_marshallIn(emlrtAlias(prhs[0]), "nei_nei_idx", nei_nei_idx);
  emlrt_marshallIn(emlrtAlias(prhs[1]), "nei_nei_weight", nei_nei_weight);
  g_n = c_emlrt_marshallIn(emlrtAliasP(prhs[2]), "g_n");
  e_emlrt_marshallIn(emlrtAlias(prhs[3]), "g_xyidx", g_xyidx);
  nei_filter_n = c_emlrt_marshallIn(emlrtAliasP(prhs[4]), "nei_filter_n");
  e_emlrt_marshallIn(emlrtAlias(prhs[5]), "nei_filter_shift_xyi",
                     nei_filter_shift_xyi);
  g_nx = c_emlrt_marshallIn(emlrtAliasP(prhs[6]), "g_nx");
  g_ny = c_emlrt_marshallIn(emlrtAliasP(prhs[7]), "g_ny");
  g_emlrt_marshallIn(emlrtAlias(prhs[8]), "nei_filter_weight", nei_filter_weight);

  /* Invoke the target function */
  set_nei4u_unit(nei_nei_idx, nei_nei_weight, g_n, g_xyidx, nei_filter_n,
                 nei_filter_shift_xyi, g_nx, g_ny, nei_filter_weight);

  /* Marshall function outputs */
  emlrt_marshallOut(nei_nei_idx, prhs[0]);
  plhs[0] = prhs[0];
  emlrt_marshallOut(nei_nei_weight, prhs[1]);
  plhs[1] = prhs[1];
  nei_filter_weight->canFreeData = false;
  emxFree_real_T(&nei_filter_weight);
  nei_filter_shift_xyi->canFreeData = false;
  emxFree_real_T(&nei_filter_shift_xyi);
  g_xyidx->canFreeData = false;
  emxFree_real_T(&g_xyidx);
  nei_nei_weight->canFreeData = false;
  emxFree_real_T(&nei_nei_weight);
  nei_nei_idx->canFreeData = false;
  emxFree_real_T(&nei_nei_idx);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (_coder_set_nei4u_unit_api.c) */
