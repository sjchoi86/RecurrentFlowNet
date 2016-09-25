/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * occflow.c
 *
 * Code generation for function 'occflow'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "occflow.h"
#include "occflow_emxutil.h"
#include "occflow_data.h"

/* Function Definitions */
void occflow(const emxArray_real_T *cgridvec, emxArray_real_T *cgridvecprev,
             emxArray_real_T *context, const emxArray_real_T *nei_idx, const
             emxArray_real_T *nei_weight, real_T nei_filter_n, const
             emxArray_real_T *nei4u_idx, const emxArray_real_T *nei4u_weight,
             real_T nei4u_filter_n, real_T occval, real_T minthreshold, real_T
             maxthreshold, real_T reinitval, real_T intensifyrate, real_T
             nocc_attenuaterate, real_T unknown_attenuaterate, real_T sigm_coef,
             emxArray_real_T *predvec, emxArray_real_T *maxvec)
{
  emxArray_boolean_T *x;
  int32_T ix;
  int32_T b_ix;
  emxArray_int32_T *ii;
  int32_T nx;
  int32_T idx;
  int32_T iy;
  boolean_T exitg5;
  boolean_T guard3 = false;
  emxArray_real_T *newlyoccidx;
  boolean_T exitg4;
  boolean_T guard2 = false;
  emxArray_real_T *occidx;
  boolean_T exitg3;
  boolean_T guard1 = false;
  emxArray_real_T *noccidx;
  int32_T j;
  emxArray_real_T *curr_col;
  emxArray_real_T *b_x;
  int32_T coccidx;
  int32_T n;
  real_T mtmp;
  boolean_T exitg2;
  int32_T outsz[2];
  emxArray_real_T *b_context;
  int32_T c_ix;
  emxArray_real_T *tempcontext;
  real_T sumval;
  emxArray_real_T *varargin_1;
  boolean_T exitg1;
  (void)unknown_attenuaterate;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_boolean_T(&x, 1, true);

  /*  */
  /*  Occupancy flow with vector input */
  /*  */
  /*  coder.extrinsic('clock') */
  /*  Compute indices first */
  ix = x->size[0];
  x->size[0] = cgridvec->size[0];
  emxEnsureCapacity((emxArray__common *)x, ix, (int32_T)sizeof(boolean_T));
  b_ix = cgridvec->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    x->data[ix] = ((cgridvec->data[ix] == occval) && (cgridvecprev->data[ix] !=
      occval));
  }

  emxInit_int32_T(&ii, 1, true);
  nx = x->size[0];
  idx = 0;
  ix = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, ix, (int32_T)sizeof(int32_T));
  iy = 1;
  exitg5 = false;
  while ((!exitg5) && (iy <= nx)) {
    guard3 = false;
    if (x->data[iy - 1]) {
      idx++;
      ii->data[idx - 1] = iy;
      if (idx >= nx) {
        exitg5 = true;
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3) {
      iy++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ix = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, ix, (int32_T)sizeof(int32_T));
    }
  } else {
    ix = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, ix, (int32_T)sizeof(int32_T));
  }

  emxInit_real_T(&newlyoccidx, 1, true);
  ix = newlyoccidx->size[0];
  newlyoccidx->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)newlyoccidx, ix, (int32_T)sizeof(real_T));
  b_ix = ii->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    newlyoccidx->data[ix] = ii->data[ix];
  }

  ix = x->size[0];
  x->size[0] = cgridvec->size[0];
  emxEnsureCapacity((emxArray__common *)x, ix, (int32_T)sizeof(boolean_T));
  b_ix = cgridvec->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    x->data[ix] = (cgridvec->data[ix] == occval);
  }

  nx = x->size[0];
  idx = 0;
  ix = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, ix, (int32_T)sizeof(int32_T));
  iy = 1;
  exitg4 = false;
  while ((!exitg4) && (iy <= nx)) {
    guard2 = false;
    if (x->data[iy - 1]) {
      idx++;
      ii->data[idx - 1] = iy;
      if (idx >= nx) {
        exitg4 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
      iy++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ix = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, ix, (int32_T)sizeof(int32_T));
    }
  } else {
    ix = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, ix, (int32_T)sizeof(int32_T));
  }

  emxInit_real_T(&occidx, 1, true);
  ix = occidx->size[0];
  occidx->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)occidx, ix, (int32_T)sizeof(real_T));
  b_ix = ii->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    occidx->data[ix] = ii->data[ix];
  }

  ix = x->size[0];
  x->size[0] = cgridvec->size[0];
  emxEnsureCapacity((emxArray__common *)x, ix, (int32_T)sizeof(boolean_T));
  b_ix = cgridvec->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    x->data[ix] = (cgridvec->data[ix] != occval);
  }

  nx = x->size[0];
  idx = 0;
  ix = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)ii, ix, (int32_T)sizeof(int32_T));
  iy = 1;
  exitg3 = false;
  while ((!exitg3) && (iy <= nx)) {
    guard1 = false;
    if (x->data[iy - 1]) {
      idx++;
      ii->data[idx - 1] = iy;
      if (idx >= nx) {
        exitg3 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      iy++;
    }
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ix = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity((emxArray__common *)ii, ix, (int32_T)sizeof(int32_T));
    }
  } else {
    ix = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, ix, (int32_T)sizeof(int32_T));
  }

  emxFree_boolean_T(&x);
  emxInit_real_T(&noccidx, 1, true);
  ix = noccidx->size[0];
  noccidx->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)noccidx, ix, (int32_T)sizeof(real_T));
  b_ix = ii->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    noccidx->data[ix] = ii->data[ix];
  }

  emxFree_int32_T(&ii);

  /*  1 Intensify newly occupied cells */
  /*  iclk = clock; */
  j = 0;
  b_emxInit_real_T(&curr_col, 2, true);
  b_emxInit_real_T(&b_x, 2, true);
  while (j <= newlyoccidx->size[0] - 1) {
    /*  For newly occupied cells */
    coccidx = (int32_T)newlyoccidx->data[j] - 1;
    nx = 1;
    n = context->size[1];
    idx = (int32_T)newlyoccidx->data[j];
    mtmp = context->data[idx - 1];
    ix = context->size[1];
    if (ix > 1) {
      if (muDoubleScalarIsNaN(mtmp)) {
        ix = 2;
        exitg2 = false;
        while ((!exitg2) && (ix <= n)) {
          nx = ix;
          if (!muDoubleScalarIsNaN(context->data[coccidx + context->size[0] *
               (ix - 1)])) {
            mtmp = context->data[coccidx + context->size[0] * (ix - 1)];
            exitg2 = true;
          } else {
            ix++;
          }
        }
      }

      ix = context->size[1];
      if (nx < ix) {
        while (nx + 1 <= n) {
          if (context->data[coccidx + context->size[0] * nx] > mtmp) {
            mtmp = context->data[coccidx + context->size[0] * nx];
          }

          nx++;
        }
      }
    }

    if (mtmp < minthreshold) {
      b_ix = context->size[1];
      idx = (int32_T)newlyoccidx->data[j];
      for (ix = 0; ix < b_ix; ix++) {
        context->data[(idx + context->size[0] * ix) - 1] = reinitval;
      }

      /*  Reinitialize */
    } else {
      b_ix = context->size[1];
      idx = (int32_T)newlyoccidx->data[j];
      ix = curr_col->size[0] * curr_col->size[1];
      curr_col->size[0] = 1;
      curr_col->size[1] = b_ix;
      emxEnsureCapacity((emxArray__common *)curr_col, ix, (int32_T)sizeof(real_T));
      for (ix = 0; ix < b_ix; ix++) {
        curr_col->data[curr_col->size[0] * ix] = intensifyrate * context->data
          [(idx + context->size[0] * ix) - 1];
      }

      /*  Intensify */
      ix = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 1;
      b_x->size[1] = curr_col->size[1];
      emxEnsureCapacity((emxArray__common *)b_x, ix, (int32_T)sizeof(real_T));
      b_ix = curr_col->size[0] * curr_col->size[1];
      for (ix = 0; ix < b_ix; ix++) {
        b_x->data[ix] = curr_col->data[ix];
      }

      for (ix = 0; ix < 2; ix++) {
        outsz[ix] = curr_col->size[ix];
      }

      ix = curr_col->size[0] * curr_col->size[1];
      curr_col->size[0] = 1;
      curr_col->size[1] = outsz[1];
      emxEnsureCapacity((emxArray__common *)curr_col, ix, (int32_T)sizeof(real_T));
      for (idx = 0; idx + 1 <= outsz[1]; idx++) {
        curr_col->data[idx] = muDoubleScalarMin(b_x->data[idx], maxthreshold);
      }

      /*  Max-thesholding */
      idx = (int32_T)newlyoccidx->data[j];
      b_ix = curr_col->size[1];
      for (ix = 0; ix < b_ix; ix++) {
        context->data[(idx + context->size[0] * ix) - 1] = curr_col->
          data[curr_col->size[0] * ix];
      }
    }

    j++;
  }

  emxFree_real_T(&b_x);

  /*  ems_intensify = etime(clock, iclk)*1000; */
  /*  2 Attenuate unoccupied cells */
  /*  iclk = clock; */
  j = 0;
  b_emxInit_real_T(&b_context, 2, true);
  while (j <= noccidx->size[0] - 1) {
    /*  For unoccupied cells */
    /*  Attenuate */
    idx = (int32_T)noccidx->data[j];
    iy = context->size[1];
    nx = (int32_T)noccidx->data[j];
    ix = b_context->size[0] * b_context->size[1];
    b_context->size[0] = 1;
    b_context->size[1] = iy;
    emxEnsureCapacity((emxArray__common *)b_context, ix, (int32_T)sizeof(real_T));
    for (ix = 0; ix < iy; ix++) {
      b_context->data[b_context->size[0] * ix] = context->data[(nx +
        context->size[0] * ix) - 1] * nocc_attenuaterate;
    }

    b_ix = b_context->size[1];
    for (ix = 0; ix < b_ix; ix++) {
      context->data[(idx + context->size[0] * ix) - 1] = b_context->
        data[b_context->size[0] * ix];
    }

    j++;
  }

  emxFree_real_T(&b_context);
  emxFree_real_T(&noccidx);

  /*  ems_attenuate = etime(clock, iclk)*1000; */
  /*  3 Propagation */
  /*  iclk = clock; */
  for (j = 0; j < occidx->size[0]; j++) {
    /*  For occupied cells */
    b_ix = context->size[1];
    c_ix = (int32_T)occidx->data[j];
    ix = curr_col->size[0] * curr_col->size[1];
    curr_col->size[0] = 1;
    curr_col->size[1] = b_ix;
    emxEnsureCapacity((emxArray__common *)curr_col, ix, (int32_T)sizeof(real_T));
    for (ix = 0; ix < b_ix; ix++) {
      curr_col->data[curr_col->size[0] * ix] = context->data[(c_ix +
        context->size[0] * ix) - 1];
    }

    for (idx = 0; idx < (int32_T)nei_filter_n; idx++) {
      /*  For all neighbor cells */
      c_ix = (int32_T)occidx->data[j];
      if (nei_idx->data[(c_ix + nei_idx->size[0] * idx) - 1] != 0.0) {
        /*  If properly connected, propagate */
        /*  Maximum value thresholding */
        c_ix = (int32_T)occidx->data[j];
        iy = (int32_T)occidx->data[j];
        nx = (int32_T)occidx->data[j];
        context->data[((int32_T)nei_idx->data[(c_ix + nei_idx->size[0] * idx) -
                       1] + context->size[0] * idx) - 1] = muDoubleScalarMax
          (context->data[((int32_T)nei_idx->data[(iy + nei_idx->size[0] * idx) -
                          1] + context->size[0] * idx) - 1], muDoubleScalarMin
           (nei_weight->data[(nx + nei_weight->size[0] * idx) - 1] *
            curr_col->data[idx], maxthreshold));

        /*  Make sure current context propagation does not weaken the flow information */
      }
    }
  }

  /*  ems_propagate = etime(clock, iclk)*1000; */
  /*  4 Uncertainty in acceleration */
  /*  iclk = clock; */
  for (ix = 0; ix < 2; ix++) {
    outsz[ix] = context->size[ix];
  }

  b_emxInit_real_T(&tempcontext, 2, true);
  ix = tempcontext->size[0] * tempcontext->size[1];
  tempcontext->size[0] = outsz[0];
  emxEnsureCapacity((emxArray__common *)tempcontext, ix, (int32_T)sizeof(real_T));
  ix = tempcontext->size[0] * tempcontext->size[1];
  tempcontext->size[1] = outsz[1];
  emxEnsureCapacity((emxArray__common *)tempcontext, ix, (int32_T)sizeof(real_T));
  b_ix = outsz[0] * outsz[1];
  for (ix = 0; ix < b_ix; ix++) {
    tempcontext->data[ix] = 0.0;
  }

  for (idx = 0; idx < nei_idx->size[0]; idx++) {
    /*  For all cells */
    for (j = 0; j < (int32_T)nei_filter_n; j++) {
      /*  For all context level */
      sumval = 0.0;
      for (iy = 0; iy < (int32_T)nei4u_filter_n; iy++) {
        sumval += nei4u_weight->data[idx + nei4u_weight->size[0] * iy] *
          context->data[((int32_T)nei4u_idx->data[idx + nei4u_idx->size[0] * iy]
                         + context->size[0] * j) - 1];
      }

      tempcontext->data[idx + tempcontext->size[0] * j] = sumval;
    }
  }

  ix = context->size[0] * context->size[1];
  context->size[0] = tempcontext->size[0];
  context->size[1] = tempcontext->size[1];
  emxEnsureCapacity((emxArray__common *)context, ix, (int32_T)sizeof(real_T));
  b_ix = tempcontext->size[1];
  for (ix = 0; ix < b_ix; ix++) {
    iy = tempcontext->size[0];
    for (nx = 0; nx < iy; nx++) {
      context->data[nx + context->size[0] * ix] = tempcontext->data[nx +
        tempcontext->size[0] * ix];
    }
  }

  b_emxInit_real_T(&varargin_1, 2, true);

  /*  ems_uia = etime(clock, iclk)*1000; */
  /*  5 Prediction */
  /*  iclk = clock; */
  ix = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = tempcontext->size[1];
  varargin_1->size[1] = tempcontext->size[0];
  emxEnsureCapacity((emxArray__common *)varargin_1, ix, (int32_T)sizeof(real_T));
  b_ix = tempcontext->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    iy = tempcontext->size[1];
    for (nx = 0; nx < iy; nx++) {
      varargin_1->data[nx + varargin_1->size[0] * ix] = tempcontext->data[ix +
        tempcontext->size[0] * nx];
    }
  }

  emxFree_real_T(&tempcontext);
  for (ix = 0; ix < 2; ix++) {
    outsz[ix] = varargin_1->size[ix];
  }

  ix = curr_col->size[0] * curr_col->size[1];
  curr_col->size[0] = 1;
  curr_col->size[1] = outsz[1];
  emxEnsureCapacity((emxArray__common *)curr_col, ix, (int32_T)sizeof(real_T));
  n = varargin_1->size[0];
  ix = 1;
  iy = -1;
  for (nx = 1; nx <= varargin_1->size[1]; nx++) {
    b_ix = ix;
    idx = (ix + n) - 1;
    mtmp = varargin_1->data[ix - 1];
    if (n > 1) {
      if (muDoubleScalarIsNaN(varargin_1->data[ix - 1])) {
        c_ix = ix;
        exitg1 = false;
        while ((!exitg1) && (c_ix + 1 <= idx)) {
          b_ix = c_ix + 1;
          if (!muDoubleScalarIsNaN(varargin_1->data[c_ix])) {
            mtmp = varargin_1->data[c_ix];
            exitg1 = true;
          } else {
            c_ix++;
          }
        }
      }

      if (b_ix < idx) {
        while (b_ix + 1 <= idx) {
          if (varargin_1->data[b_ix] > mtmp) {
            mtmp = varargin_1->data[b_ix];
          }

          b_ix++;
        }
      }
    }

    iy++;
    curr_col->data[iy] = mtmp;
    ix += n;
  }

  emxFree_real_T(&varargin_1);
  ix = maxvec->size[0];
  maxvec->size[0] = curr_col->size[1];
  emxEnsureCapacity((emxArray__common *)maxvec, ix, (int32_T)sizeof(real_T));
  b_ix = curr_col->size[1];
  for (ix = 0; ix < b_ix; ix++) {
    maxvec->data[ix] = curr_col->data[curr_col->size[0] * ix];
  }

  emxFree_real_T(&curr_col);

  /*  sigm_a  <= if we increase the value, than the sigm function gets peaky! */
  ix = newlyoccidx->size[0];
  newlyoccidx->size[0] = maxvec->size[0];
  emxEnsureCapacity((emxArray__common *)newlyoccidx, ix, (int32_T)sizeof(real_T));
  b_ix = maxvec->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    newlyoccidx->data[ix] = -sigm_coef * maxvec->data[ix];
  }

  ix = predvec->size[0];
  predvec->size[0] = newlyoccidx->size[0];
  emxEnsureCapacity((emxArray__common *)predvec, ix, (int32_T)sizeof(real_T));
  b_ix = newlyoccidx->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    predvec->data[ix] = newlyoccidx->data[ix];
  }

  for (idx = 0; idx < newlyoccidx->size[0]; idx++) {
    predvec->data[idx] = muDoubleScalarExp(predvec->data[idx]);
  }

  ix = newlyoccidx->size[0];
  newlyoccidx->size[0] = maxvec->size[0];
  emxEnsureCapacity((emxArray__common *)newlyoccidx, ix, (int32_T)sizeof(real_T));
  b_ix = maxvec->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    newlyoccidx->data[ix] = -sigm_coef * maxvec->data[ix];
  }

  ix = occidx->size[0];
  occidx->size[0] = newlyoccidx->size[0];
  emxEnsureCapacity((emxArray__common *)occidx, ix, (int32_T)sizeof(real_T));
  b_ix = newlyoccidx->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    occidx->data[ix] = newlyoccidx->data[ix];
  }

  for (idx = 0; idx < newlyoccidx->size[0]; idx++) {
    occidx->data[idx] = muDoubleScalarExp(occidx->data[idx]);
  }

  emxFree_real_T(&newlyoccidx);
  ix = predvec->size[0];
  emxEnsureCapacity((emxArray__common *)predvec, ix, (int32_T)sizeof(real_T));
  b_ix = predvec->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    predvec->data[ix] = (1.0 - predvec->data[ix]) / (1.0 + occidx->data[ix]);
  }

  emxFree_real_T(&occidx);

  /*  ems_predict = etime(clock, iclk)*1000; */
  /*  6 Save previous grid */
  ix = cgridvecprev->size[0];
  cgridvecprev->size[0] = cgridvec->size[0];
  emxEnsureCapacity((emxArray__common *)cgridvecprev, ix, (int32_T)sizeof(real_T));
  b_ix = cgridvec->size[0];
  for (ix = 0; ix < b_ix; ix++) {
    cgridvecprev->data[ix] = cgridvec->data[ix];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (occflow.c) */
