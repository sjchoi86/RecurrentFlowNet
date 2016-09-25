/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * occflow_emxutil.h
 *
 * Code generation for function 'occflow_emxutil'
 *
 */

#ifndef __OCCFLOW_EMXUTIL_H__
#define __OCCFLOW_EMXUTIL_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "occflow_types.h"

/* Function Declarations */
extern void b_emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions,
  boolean_T doPush);
extern void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int32_T
  numDimensions, boolean_T doPush);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int32_T numDimensions,
  boolean_T doPush);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions,
  boolean_T doPush);

#endif

/* End of code generation (occflow_emxutil.h) */
