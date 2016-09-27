/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * set_nei_unit.h
 *
 * Code generation for function 'set_nei_unit'
 *
 */

#ifndef __SET_NEI_UNIT_H__
#define __SET_NEI_UNIT_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "set_nei_unit_types.h"

/* Function Declarations */
extern void set_nei_unit(emxArray_real_T *nei_nei_idx, emxArray_real_T
  *nei_nei_weight, real_T g_n, const emxArray_real_T *g_xyidx, real_T
  nei_filter_n, const emxArray_real_T *nei_filter_shift_xyi, real_T g_nx, real_T
  g_ny, const emxArray_real_T *nei_filter_weight);

#endif

/* End of code generation (set_nei_unit.h) */
