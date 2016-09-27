/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * set_nei_unit.c
 *
 * Code generation for function 'set_nei_unit'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "set_nei_unit.h"

/* Function Definitions */
void set_nei_unit(emxArray_real_T *nei_nei_idx, emxArray_real_T *nei_nei_weight,
                  real_T g_n, const emxArray_real_T *g_xyidx, real_T
                  nei_filter_n, const emxArray_real_T *nei_filter_shift_xyi,
                  real_T g_nx, real_T g_ny, const emxArray_real_T
                  *nei_filter_weight)
{
  int32_T i;
  int32_T j;
  real_T nei_xyidx[2];
  int32_T i1;
  for (i = 0; i < (int32_T)g_n; i++) {
    for (j = 0; j < (int32_T)nei_filter_n; j++) {
      for (i1 = 0; i1 < 2; i1++) {
        nei_xyidx[i1] = g_xyidx->data[i + g_xyidx->size[0] * i1] +
          nei_filter_shift_xyi->data[j + nei_filter_shift_xyi->size[0] * i1];
      }

      if ((nei_xyidx[0] > 0.0) && (nei_xyidx[1] > 0.0) && (nei_xyidx[0] <= g_nx)
          && (nei_xyidx[1] <= g_ny)) {
        nei_nei_idx->data[i + nei_nei_idx->size[0] * j] = g_ny * (nei_xyidx[0] -
          1.0) + nei_xyidx[1];
        nei_nei_weight->data[i + nei_nei_weight->size[0] * j] =
          nei_filter_weight->data[j];
      }
    }
  }
}

/* End of code generation (set_nei_unit.c) */
