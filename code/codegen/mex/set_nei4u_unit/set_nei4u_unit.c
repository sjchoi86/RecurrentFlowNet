/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * set_nei4u_unit.c
 *
 * Code generation for function 'set_nei4u_unit'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "set_nei4u_unit.h"
#include "set_nei4u_unit_emxutil.h"
#include "set_nei4u_unit_data.h"

/* Function Definitions */
void set_nei4u_unit(emxArray_real_T *nei_nei_idx, emxArray_real_T
                    *nei_nei_weight, real_T g_n, const emxArray_real_T *g_xyidx,
                    real_T nei_filter_n, const emxArray_real_T
                    *nei_filter_shift_xyi, real_T g_nx, real_T g_ny, const
                    emxArray_real_T *nei_filter_weight)
{
  int32_T i;
  int32_T k;
  real_T nei_xyidx[2];
  int32_T i1;
  emxArray_real_T *b_nei_nei_weight;
  real_T y;
  int32_T exitg1;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  for (i = 0; i < (int32_T)g_n; i++) {
    for (k = 0; k < (int32_T)nei_filter_n; k++) {
      for (i1 = 0; i1 < 2; i1++) {
        nei_xyidx[i1] = g_xyidx->data[i + g_xyidx->size[0] * i1] +
          nei_filter_shift_xyi->data[k + nei_filter_shift_xyi->size[0] * i1];
      }

      if ((nei_xyidx[0] > 0.0) && (nei_xyidx[1] > 0.0) && (nei_xyidx[0] <= g_nx)
          && (nei_xyidx[1] <= g_ny)) {
        nei_nei_idx->data[i + nei_nei_idx->size[0] * k] = g_ny * (nei_xyidx[0] -
          1.0) + nei_xyidx[1];
        nei_nei_weight->data[i + nei_nei_weight->size[0] * k] =
          nei_filter_weight->data[k];
      } else {
        nei_nei_idx->data[i + nei_nei_idx->size[0] * k] = 1.0;
        nei_nei_weight->data[i + nei_nei_weight->size[0] * k] = 0.0;
      }
    }
  }

  /*  MAKE ROW SUM TO ONE */
  i = 0;
  emxInit_real_T(&b_nei_nei_weight, 2, true);
  while (i <= (int32_T)g_n - 1) {
    i1 = nei_nei_weight->size[1];
    if (i1 == 0) {
      y = 0.0;
    } else {
      y = nei_nei_weight->data[i];
      k = 2;
      do {
        exitg1 = 0;
        i1 = nei_nei_weight->size[1];
        if (k <= i1) {
          y += nei_nei_weight->data[i + nei_nei_weight->size[0] * (k - 1)];
          k++;
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }

    k = nei_nei_weight->size[1];
    i1 = b_nei_nei_weight->size[0] * b_nei_nei_weight->size[1];
    b_nei_nei_weight->size[0] = 1;
    b_nei_nei_weight->size[1] = k;
    emxEnsureCapacity((emxArray__common *)b_nei_nei_weight, i1, (int32_T)sizeof
                      (real_T));
    for (i1 = 0; i1 < k; i1++) {
      b_nei_nei_weight->data[b_nei_nei_weight->size[0] * i1] =
        nei_nei_weight->data[i + nei_nei_weight->size[0] * i1] / y;
    }

    k = b_nei_nei_weight->size[1];
    for (i1 = 0; i1 < k; i1++) {
      nei_nei_weight->data[i + nei_nei_weight->size[0] * i1] =
        b_nei_nei_weight->data[b_nei_nei_weight->size[0] * i1];
    }

    i++;
  }

  emxFree_real_T(&b_nei_nei_weight);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (set_nei4u_unit.c) */
