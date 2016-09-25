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
#include "forcePushIntoCloud.h"
#include "occflow.h"
#include "occflow_float_mex_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "exp.h"
#include "occflow_float_mex_mexutil.h"
#include "occflow_float_mex_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 16, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRSInfo b_emlrtRSI = { 18, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRSInfo c_emlrtRSI = { 20, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRSInfo d_emlrtRSI = { 28, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRSInfo e_emlrtRSI = { 32, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRSInfo f_emlrtRSI = { 93, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRSInfo g_emlrtRSI = { 94, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRSInfo h_emlrtRSI = { 44, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo i_emlrtRSI = { 234, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo j_emlrtRSI = { 253, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRSInfo l_emlrtRSI = { 18, "indexShapeCheck",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"
};

static emlrtRSInfo m_emlrtRSI = { 16, "max",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/max.m" };

static emlrtRSInfo n_emlrtRSI = { 18, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo o_emlrtRSI = { 97, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo p_emlrtRSI = { 308, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo q_emlrtRSI = { 281, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo r_emlrtRSI = { 16, "min",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/datafun/min.m" };

static emlrtRSInfo s_emlrtRSI = { 59, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo t_emlrtRSI = { 182, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo u_emlrtRSI = { 208, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo v_emlrtRSI = { 160, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo w_emlrtRSI = { 163, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRSInfo x_emlrtRSI = { 107, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo emlrtRTEI = { 3, 7, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 253, 13, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo d_emlrtRTEI = { 19, 24, "scalexpAllocNoCheck",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 16, 9, "scalexpAlloc",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

static emlrtRTEInfo f_emlrtRTEI = { 16, 1, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo g_emlrtRTEI = { 18, 1, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo h_emlrtRTEI = { 20, 1, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo i_emlrtRTEI = { 27, 5, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 55, 5, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 56, 5, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo l_emlrtRTEI = { 73, 1, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo m_emlrtRTEI = { 36, 6, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo o_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

static emlrtRTEInfo p_emlrtRTEI = { 81, 19, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 38, 19, "minOrMax",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 13, 15, "rdivide",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/ops/rdivide.m" };

static emlrtRTEInfo s_emlrtRTEI = { 85, 5, "indexShapeCheck",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/eml/+coder/+internal/indexShapeCheck.m"
};

static emlrtRTEInfo t_emlrtRTEI = { 243, 9, "find",
  "/Applications/MATLAB_R2015b.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo u_emlrtRTEI = { 77, 9, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo v_emlrtRTEI = { 75, 5, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtRTEInfo w_emlrtRTEI = { 57, 5, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 56, 29, "nei_weight", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 55, 26, "nei_idx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 54, 26, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtECInfo emlrtECI = { -1, 45, 5, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 45, 13, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 43, 24, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtECInfo b_emlrtECI = { -1, 33, 9, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtBCInfo f_emlrtBCI = { -1, -1, 33, 17, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 29, 17, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 27, 24, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtECInfo c_emlrtECI = { -1, 16, 21, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m"
};

static emlrtBCInfo i_emlrtBCI = { -1, -1, 85, 21, "tempcontext", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 85, 24, "tempcontext", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 78, 30, "nei4u_idx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 78, 33, "nei4u_idx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 79, 33, "nei4u_weight", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 79, 36, "nei4u_weight", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 81, 36, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtDCInfo emlrtDCI = { 81, 36, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  1 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 81, 42, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 53, 18, "occidx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 58, 22, "curr_col", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 59, 22, "cneicon", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 60, 22, "cneiweight", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 62, 38, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtDCInfo b_emlrtDCI = { 62, 38, "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  1 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 62, 46, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 65, 21, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 65, 29, "context", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 42, 16, "noccidx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 26, 16, "newlyoccidx", "occflow",
  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
  0 };

/* Function Declarations */
static void b_emlrt_update_log_1(const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index);
static void b_emlrt_update_log_2(const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index);
static void emlrt_update_log_1(const emlrtStack *sp, const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index, emxArray_real_T *out);
static void emlrt_update_log_2(const emlrtStack *sp, const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index, emxArray_real_T *out);
static real_T emlrt_update_log_3(real_T in, emlrtLocationLoggingDataType table[],
  int32_T b_index);
static void emlrt_update_log_4(const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index);

/* Function Definitions */
static void b_emlrt_update_log_1(const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T localMin;
  real_T localMax;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    for (i = 0; i < in->size[0]; i++) {
      /* Simulation Min-Max logging. */
      if (in->data[i] < localMin) {
        localMin = in->data[i];
      }

      if (in->data[i] > localMax) {
        localMax = in->data[i];
      }
    }

    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    /* IsAlwaysInteger logging. */
    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < in->size[0])) {
      if (in->data[i] != muDoubleScalarFloor(in->data[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }

      i++;
    }
  }
}

static void b_emlrt_update_log_2(const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T localMin;
  real_T localMax;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    for (i = 0; i < in->size[0] * in->size[1]; i++) {
      /* Simulation Min-Max logging. */
      if (in->data[i] < localMin) {
        localMin = in->data[i];
      }

      if (in->data[i] > localMax) {
        localMax = in->data[i];
      }
    }

    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    /* IsAlwaysInteger logging. */
    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < in->size[0] * in->size[1])) {
      if (in->data[i] != muDoubleScalarFloor(in->data[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }

      i++;
    }
  }
}

static void emlrt_update_log_1(const emlrtStack *sp, const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index, emxArray_real_T *out)
{
  int32_T i0;
  int32_T loop_ub;
  i0 = out->size[0];
  out->size[0] = in->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)out, i0, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  loop_ub = in->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    out->data[i0] = in->data[i0];
  }

  b_emlrt_update_log_1(out, table, b_index);
}

static void emlrt_update_log_2(const emlrtStack *sp, const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index, emxArray_real_T *out)
{
  int32_T i1;
  int32_T loop_ub;
  i1 = out->size[0] * out->size[1];
  out->size[0] = in->size[0];
  out->size[1] = in->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)out, i1, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  loop_ub = in->size[0] * in->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    out->data[i1] = in->data[i1];
  }

  b_emlrt_update_log_2(out, table, b_index);
}

static real_T emlrt_update_log_3(real_T in, emlrtLocationLoggingDataType table[],
  int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T localMin;
  real_T localMax;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;

    /* Simulation Min-Max logging. */
    if (in < localMin) {
      localMin = in;
    }

    if (in > localMax) {
      localMax = in;
    }

    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    /* IsAlwaysInteger logging. */
    if (in != muDoubleScalarFloor(in)) {
      b_table[0U].IsAlwaysInteger = false;
    }
  }

  return in;
}

static void emlrt_update_log_4(const emxArray_real_T *in,
  emlrtLocationLoggingDataType table[], int32_T b_index)
{
  emlrtLocationLoggingDataType *b_table;
  real_T localMin;
  real_T localMax;
  int32_T i;
  if (b_index >= 0) {
    b_table = (emlrtLocationLoggingDataType *)&table[b_index];
    localMin = b_table[0U].SimMin;
    localMax = b_table[0U].SimMax;
    for (i = 0; i < in->size[1]; i++) {
      /* Simulation Min-Max logging. */
      if (in->data[i] < localMin) {
        localMin = in->data[i];
      }

      if (in->data[i] > localMax) {
        localMax = in->data[i];
      }
    }

    b_table[0U].SimMin = localMin;
    b_table[0U].SimMax = localMax;

    /* IsAlwaysInteger logging. */
    i = 0;
    while (b_table[0U].IsAlwaysInteger && (i < in->size[1])) {
      if (in->data[i] != muDoubleScalarFloor(in->data[i])) {
        b_table[0U].IsAlwaysInteger = false;
      }

      i++;
    }
  }
}

void occflow(const emlrtStack *sp, const emxArray_real_T *cgridvec,
             emxArray_real_T *cgridvecprev, emxArray_real_T *context, const
             emxArray_real_T *nei_idx, const emxArray_real_T *nei_weight, real_T
             nei_filter_n, const emxArray_real_T *nei4u_idx, const
             emxArray_real_T *nei4u_weight, real_T nei4u_filter_n, real_T occval,
             real_T minthreshold, real_T maxthreshold, real_T reinitval, real_T
             intensifyrate, real_T nocc_attenuaterate, real_T
             unknown_attenuaterate, real_T sigm_coef, emxArray_real_T *predvec,
             emxArray_real_T *maxvec)
{
  emxArray_real_T *newlyoccidx;
  emxArray_real_T *occidx;
  emxArray_real_T *noccidx;
  emxArray_real_T *curr_col;
  emxArray_real_T *cneicon;
  emxArray_real_T *cneiweight;
  emxArray_real_T *tempcontext;
  emxArray_boolean_T *x;
  emxArray_real_T *b_cgridvec;
  emxArray_real_T *b_cgridvecprev;
  emxArray_real_T *b_context;
  emxArray_real_T *b_nei_idx;
  emxArray_real_T *b_nei_weight;
  emxArray_real_T *b_nei4u_idx;
  emxArray_real_T *b_nei4u_weight;
  int32_T ix;
  int32_T nx;
  emxArray_boolean_T *r0;
  int32_T idx;
  emxArray_int32_T *ii;
  boolean_T overflow;
  int32_T iy;
  boolean_T exitg6;
  boolean_T guard3 = false;
  boolean_T b_guard3 = false;
  real_T nrnewlyocc;
  boolean_T exitg5;
  boolean_T guard2 = false;
  boolean_T b_guard2 = false;
  real_T nrocc;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T b_guard1 = false;
  real_T nrnocc;
  int32_T j;
  real_T b_j;
  real_T coccidx;
  int32_T ixstart;
  int32_T n;
  real_T mtmp;
  int32_T b_ix;
  boolean_T exitg3;
  int32_T k;
  int32_T iv3[2];
  real_T cnoccidx;
  int32_T iv4[2];
  real_T cpropidx;
  real_T b_k;
  real_T contextval;
  real_T neiidx;
  real_T weightval;
  real_T origvontextval;
  real_T updtcontextval;
  real_T sumval;
  int32_T m;
  real_T b_m;
  real_T nidx;
  real_T nwei;
  real_T curr_val;
  boolean_T c_ix;
  boolean_T exitg2;
  boolean_T b_ixstart;
  emxArray_real_T *b_maxvec;
  real_T a;
  int32_T varargin_1[2];
  int32_T varargin_2[2];
  boolean_T p;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &newlyoccidx, 1, &f_emlrtRTEI, true);
  emxInit_real_T(sp, &occidx, 1, &g_emlrtRTEI, true);
  emxInit_real_T(sp, &noccidx, 1, &h_emlrtRTEI, true);
  emxInit_real_T1(sp, &curr_col, 2, &i_emlrtRTEI, true);
  emxInit_real_T1(sp, &cneicon, 2, &j_emlrtRTEI, true);
  emxInit_real_T1(sp, &cneiweight, 2, &k_emlrtRTEI, true);
  emxInit_real_T1(sp, &tempcontext, 2, &l_emlrtRTEI, true);
  emxInit_boolean_T(sp, &x, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_cgridvec, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_cgridvecprev, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_context, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_nei_idx, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_nei_weight, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_nei4u_idx, 2, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_nei4u_weight, 2, &emlrtRTEI, true);
  emlrtInitVarDataTables(emlrtLocationLoggingDataTables);

  /* logging input variable 'cgridvec' for function 'occflow' */
  emlrt_update_log_1(sp, cgridvec, emlrtLocationLoggingDataTables, 0, b_cgridvec);

  /* logging input variable 'cgridvecprev' for function 'occflow' */
  emlrt_update_log_1(sp, cgridvecprev, emlrtLocationLoggingDataTables, 1,
                     b_cgridvecprev);

  /* logging input variable 'context' for function 'occflow' */
  emlrt_update_log_2(sp, context, emlrtLocationLoggingDataTables, 2, b_context);

  /* logging input variable 'nei_idx' for function 'occflow' */
  emlrt_update_log_2(sp, nei_idx, emlrtLocationLoggingDataTables, 3, b_nei_idx);

  /* logging input variable 'nei_weight' for function 'occflow' */
  emlrt_update_log_2(sp, nei_weight, emlrtLocationLoggingDataTables, 4,
                     b_nei_weight);

  /* logging input variable 'nei_filter_n' for function 'occflow' */
  emlrt_update_log_3(nei_filter_n, emlrtLocationLoggingDataTables, 5);

  /* logging input variable 'nei4u_idx' for function 'occflow' */
  emlrt_update_log_2(sp, nei4u_idx, emlrtLocationLoggingDataTables, 6,
                     b_nei4u_idx);

  /* logging input variable 'nei4u_weight' for function 'occflow' */
  emlrt_update_log_2(sp, nei4u_weight, emlrtLocationLoggingDataTables, 7,
                     b_nei4u_weight);

  /* logging input variable 'nei4u_filter_n' for function 'occflow' */
  emlrt_update_log_3(nei4u_filter_n, emlrtLocationLoggingDataTables, 8);

  /* logging input variable 'occval' for function 'occflow' */
  emlrt_update_log_3(occval, emlrtLocationLoggingDataTables, 9);

  /* logging input variable 'minthreshold' for function 'occflow' */
  emlrt_update_log_3(minthreshold, emlrtLocationLoggingDataTables, 10);

  /* logging input variable 'maxthreshold' for function 'occflow' */
  emlrt_update_log_3(maxthreshold, emlrtLocationLoggingDataTables, 11);

  /* logging input variable 'reinitval' for function 'occflow' */
  emlrt_update_log_3(reinitval, emlrtLocationLoggingDataTables, 12);

  /* logging input variable 'intensifyrate' for function 'occflow' */
  emlrt_update_log_3(intensifyrate, emlrtLocationLoggingDataTables, 13);

  /* logging input variable 'nocc_attenuaterate' for function 'occflow' */
  emlrt_update_log_3(nocc_attenuaterate, emlrtLocationLoggingDataTables, 14);

  /* logging input variable 'unknown_attenuaterate' for function 'occflow' */
  emlrt_update_log_3(unknown_attenuaterate, emlrtLocationLoggingDataTables, 15);

  /* logging input variable 'sigm_coef' for function 'occflow' */
  emlrt_update_log_3(sigm_coef, emlrtLocationLoggingDataTables, 16);
  covrtLogFcn(&emlrtCoverageInstance, (uint32_T)0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 0);

  /*  */
  /*  Occupancy flow with vector input */
  /*  */
  /*  coder.extrinsic('clock') */
  /*  Compute indices first */
  ix = x->size[0];
  x->size[0] = cgridvec->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  nx = cgridvec->size[0];
  emxFree_real_T(&b_nei4u_weight);
  emxFree_real_T(&b_nei4u_idx);
  emxFree_real_T(&b_nei_weight);
  emxFree_real_T(&b_nei_idx);
  emxFree_real_T(&b_context);
  emxFree_real_T(&b_cgridvecprev);
  emxFree_real_T(&b_cgridvec);
  for (ix = 0; ix < nx; ix++) {
    x->data[ix] = (cgridvec->data[ix] == occval);
  }

  emxInit_boolean_T(sp, &r0, 1, &emlrtRTEI, true);
  ix = r0->size[0];
  r0->size[0] = cgridvecprev->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  nx = cgridvecprev->size[0];
  for (ix = 0; ix < nx; ix++) {
    r0->data[ix] = (cgridvecprev->data[ix] != occval);
  }

  ix = x->size[0];
  idx = r0->size[0];
  if (ix != idx) {
    emlrtSizeEqCheck1DR2012b(ix, idx, &c_emlrtECI, sp);
  }

  st.site = &emlrtRSI;
  ix = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  nx = x->size[0];
  for (ix = 0; ix < nx; ix++) {
    x->data[ix] = (x->data[ix] && r0->data[ix]);
  }

  emxFree_boolean_T(&r0);
  emxInit_int32_T(&st, &ii, 1, &m_emlrtRTEI, true);
  b_st.site = &h_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  ix = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  c_st.site = &i_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  iy = 1;
  exitg6 = false;
  while ((!exitg6) && (iy <= nx)) {
    guard3 = false;
    if (x->data[iy - 1]) {
      idx++;
      ii->data[idx - 1] = iy;
      if (idx >= nx) {
        exitg6 = true;
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

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &t_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ix = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      ix = 0;
    } else {
      ix = idx;
    }

    c_st.site = &j_emlrtRSI;
    overflow = !(ii->size[0] != 1);
    b_guard3 = false;
    if (overflow) {
      overflow = false;
      if (ix != 1) {
        overflow = true;
      }

      if (overflow) {
        overflow = true;
      } else {
        b_guard3 = true;
      }
    } else {
      b_guard3 = true;
    }

    if (b_guard3) {
      overflow = false;
    }

    d_st.site = &l_emlrtRSI;
    if (!overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &s_emlrtRTEI,
        "Coder:FE:PotentialVectorVector", 0);
    }

    idx = ii->size[0];
    ii->size[0] = ix;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &c_emlrtRTEI);
  }

  ix = newlyoccidx->size[0];
  newlyoccidx->size[0] = ii->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)newlyoccidx, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  nx = ii->size[0];
  for (ix = 0; ix < nx; ix++) {
    newlyoccidx->data[ix] = ii->data[ix];
  }

  b_emlrt_update_log_1(newlyoccidx, emlrtLocationLoggingDataTables, 17);
  nrnewlyocc = emlrt_update_log_3(newlyoccidx->size[0],
    emlrtLocationLoggingDataTables, 18);
  st.site = &b_emlrtRSI;
  ix = x->size[0];
  x->size[0] = cgridvec->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  nx = cgridvec->size[0];
  for (ix = 0; ix < nx; ix++) {
    x->data[ix] = (cgridvec->data[ix] == occval);
  }

  b_st.site = &h_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  ix = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  c_st.site = &i_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  iy = 1;
  exitg5 = false;
  while ((!exitg5) && (iy <= nx)) {
    guard2 = false;
    if (x->data[iy - 1]) {
      idx++;
      ii->data[idx - 1] = iy;
      if (idx >= nx) {
        exitg5 = true;
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

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &t_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ix = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      ix = 0;
    } else {
      ix = idx;
    }

    c_st.site = &j_emlrtRSI;
    overflow = !(ii->size[0] != 1);
    b_guard2 = false;
    if (overflow) {
      overflow = false;
      if (ix != 1) {
        overflow = true;
      }

      if (overflow) {
        overflow = true;
      } else {
        b_guard2 = true;
      }
    } else {
      b_guard2 = true;
    }

    if (b_guard2) {
      overflow = false;
    }

    d_st.site = &l_emlrtRSI;
    if (!overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &s_emlrtRTEI,
        "Coder:FE:PotentialVectorVector", 0);
    }

    idx = ii->size[0];
    ii->size[0] = ix;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &c_emlrtRTEI);
  }

  ix = occidx->size[0];
  occidx->size[0] = ii->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)occidx, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  nx = ii->size[0];
  for (ix = 0; ix < nx; ix++) {
    occidx->data[ix] = ii->data[ix];
  }

  b_emlrt_update_log_1(occidx, emlrtLocationLoggingDataTables, 19);
  nrocc = emlrt_update_log_3(occidx->size[0], emlrtLocationLoggingDataTables, 20);
  st.site = &c_emlrtRSI;
  ix = x->size[0];
  x->size[0] = cgridvec->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x, ix, (int32_T)sizeof(boolean_T),
                    &emlrtRTEI);
  nx = cgridvec->size[0];
  for (ix = 0; ix < nx; ix++) {
    x->data[ix] = (cgridvec->data[ix] != occval);
  }

  b_st.site = &h_emlrtRSI;
  nx = x->size[0];
  idx = 0;
  ix = ii->size[0];
  ii->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  c_st.site = &i_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  iy = 1;
  exitg4 = false;
  while ((!exitg4) && (iy <= nx)) {
    guard1 = false;
    if (x->data[iy - 1]) {
      idx++;
      ii->data[idx - 1] = iy;
      if (idx >= nx) {
        exitg4 = true;
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

  if (idx <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &t_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (x->size[0] == 1) {
    if (idx == 0) {
      ix = ii->size[0];
      ii->size[0] = 0;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, ix, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
    }
  } else {
    if (1 > idx) {
      ix = 0;
    } else {
      ix = idx;
    }

    c_st.site = &j_emlrtRSI;
    overflow = !(ii->size[0] != 1);
    b_guard1 = false;
    if (overflow) {
      overflow = false;
      if (ix != 1) {
        overflow = true;
      }

      if (overflow) {
        overflow = true;
      } else {
        b_guard1 = true;
      }
    } else {
      b_guard1 = true;
    }

    if (b_guard1) {
      overflow = false;
    }

    d_st.site = &l_emlrtRSI;
    if (!overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&d_st, &s_emlrtRTEI,
        "Coder:FE:PotentialVectorVector", 0);
    }

    idx = ii->size[0];
    ii->size[0] = ix;
    emxEnsureCapacity(&b_st, (emxArray__common *)ii, idx, (int32_T)sizeof
                      (int32_T), &c_emlrtRTEI);
  }

  emxFree_boolean_T(&x);
  ix = noccidx->size[0];
  noccidx->size[0] = ii->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)noccidx, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  nx = ii->size[0];
  for (ix = 0; ix < nx; ix++) {
    noccidx->data[ix] = ii->data[ix];
  }

  b_emlrt_update_log_1(noccidx, emlrtLocationLoggingDataTables, 21);
  nrnocc = emlrt_update_log_3(noccidx->size[0], emlrtLocationLoggingDataTables,
    22);

  /*  1 Intensify newly occupied cells */
  /*  iclk = clock; */
  j = 0;
  while (j <= (int32_T)nrnewlyocc - 1) {
    b_j = emlrt_update_log_3(1.0 + (real_T)j, emlrtLocationLoggingDataTables, 58);
    covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 1);

    /*  For newly occupied cells */
    ix = newlyoccidx->size[0];
    idx = (int32_T)b_j;
    if (!((idx >= 1) && (idx <= ix))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &ab_emlrtBCI, sp);
    }

    coccidx = emlrt_update_log_3(newlyoccidx->data[idx - 1],
      emlrtLocationLoggingDataTables, 23);
    nx = context->size[1];
    ix = context->size[0];
    iy = (int32_T)coccidx;
    if (!((iy >= 1) && (iy <= ix))) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &h_emlrtBCI, sp);
    }

    ix = curr_col->size[0] * curr_col->size[1];
    curr_col->size[0] = 1;
    curr_col->size[1] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)curr_col, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < nx; ix++) {
      curr_col->data[curr_col->size[0] * ix] = context->data[(iy + context->
        size[0] * ix) - 1];
    }

    emlrt_update_log_4(curr_col, emlrtLocationLoggingDataTables, 24);
    st.site = &d_emlrtRSI;
    b_st.site = &m_emlrtRSI;
    c_st.site = &n_emlrtRSI;
    if ((curr_col->size[1] == 1) || (curr_col->size[1] != 1)) {
      overflow = true;
    } else {
      overflow = false;
    }

    if (overflow) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI,
        "Coder:toolbox:autoDimIncompatibility", 0);
    }

    if (curr_col->size[1] > 0) {
    } else {
      emlrtErrorWithMessageIdR2012b(&c_st, &p_emlrtRTEI,
        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
    }

    d_st.site = &o_emlrtRSI;
    ixstart = 1;
    n = curr_col->size[1];
    mtmp = curr_col->data[0];
    if (curr_col->size[1] > 1) {
      if (muDoubleScalarIsNaN(curr_col->data[0])) {
        e_st.site = &q_emlrtRSI;
        if (2 > curr_col->size[1]) {
          overflow = false;
        } else {
          overflow = (curr_col->size[1] > 2147483646);
        }

        if (overflow) {
          f_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        b_ix = 2;
        exitg3 = false;
        while ((!exitg3) && (b_ix <= n)) {
          ixstart = b_ix;
          if (!muDoubleScalarIsNaN(curr_col->data[b_ix - 1])) {
            mtmp = curr_col->data[b_ix - 1];
            exitg3 = true;
          } else {
            b_ix++;
          }
        }
      }

      if (ixstart < curr_col->size[1]) {
        e_st.site = &p_emlrtRSI;
        if (ixstart + 1 > curr_col->size[1]) {
          overflow = false;
        } else {
          overflow = (curr_col->size[1] > 2147483646);
        }

        if (overflow) {
          f_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        while (ixstart + 1 <= n) {
          if (curr_col->data[ixstart] > mtmp) {
            mtmp = curr_col->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    if (covrtLogIf(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 0,
                   emlrt_update_log_3(mtmp, emlrtLocationLoggingDataTables, 25) <
                   minthreshold)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 2);
      ix = context->size[0];
      idx = (int32_T)coccidx;
      if (!((idx >= 1) && (idx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &g_emlrtBCI, sp);
      }

      ix = idx - 1;
      nx = context->size[1];
      idx = curr_col->size[0] * curr_col->size[1];
      curr_col->size[0] = 1;
      curr_col->size[1] = nx;
      emxEnsureCapacity(sp, (emxArray__common *)curr_col, idx, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (idx = 0; idx < nx; idx++) {
        curr_col->data[idx] = reinitval;
      }

      emlrt_update_log_4(curr_col, emlrtLocationLoggingDataTables, 26);
      nx = curr_col->size[1];
      for (idx = 0; idx < nx; idx++) {
        context->data[ix + context->size[0] * idx] = curr_col->data
          [curr_col->size[0] * idx];
      }

      /*  Reinitialize */
    } else {
      covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 3);
      ix = curr_col->size[0] * curr_col->size[1];
      curr_col->size[0] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)curr_col, ix, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      iy = curr_col->size[0];
      nx = curr_col->size[1];
      nx *= iy;
      for (ix = 0; ix < nx; ix++) {
        curr_col->data[ix] *= intensifyrate;
      }

      emlrt_update_log_4(curr_col, emlrtLocationLoggingDataTables, 27);

      /*  Intensify */
      st.site = &e_emlrtRSI;
      b_st.site = &r_emlrtRSI;
      c_st.site = &n_emlrtRSI;
      d_st.site = &s_emlrtRSI;
      e_st.site = &t_emlrtRSI;
      ix = cneicon->size[0] * cneicon->size[1];
      cneicon->size[0] = 1;
      cneicon->size[1] = curr_col->size[1];
      emxEnsureCapacity(&e_st, (emxArray__common *)cneicon, ix, (int32_T)sizeof
                        (real_T), &d_emlrtRTEI);
      iy = curr_col->size[1];
      ix = cneiweight->size[0] * cneiweight->size[1];
      cneiweight->size[0] = 1;
      cneiweight->size[1] = curr_col->size[1];
      emxEnsureCapacity(&e_st, (emxArray__common *)cneiweight, ix, (int32_T)
                        sizeof(real_T), &e_emlrtRTEI);
      if (dimagree(cneiweight, curr_col)) {
      } else {
        emlrtErrorWithMessageIdR2012b(&e_st, &o_emlrtRTEI, "MATLAB:dimagree", 0);
      }

      e_st.site = &u_emlrtRSI;
      if (1 > cneicon->size[1]) {
        overflow = false;
      } else {
        overflow = (cneicon->size[1] > 2147483646);
      }

      if (overflow) {
        f_st.site = &k_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (k = 0; k + 1 <= iy; k++) {
        cneiweight->data[k] = muDoubleScalarMin(curr_col->data[k], maxthreshold);
      }

      ix = curr_col->size[0] * curr_col->size[1];
      curr_col->size[0] = 1;
      curr_col->size[1] = cneiweight->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)curr_col, ix, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      nx = cneiweight->size[0] * cneiweight->size[1];
      for (ix = 0; ix < nx; ix++) {
        curr_col->data[ix] = cneiweight->data[ix];
      }

      emlrt_update_log_4(curr_col, emlrtLocationLoggingDataTables, 28);

      /*  Max-thesholding */
      ix = context->size[0];
      idx = (int32_T)coccidx;
      if (!((idx >= 1) && (idx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &f_emlrtBCI, sp);
      }

      nx = context->size[1];
      ix = ii->size[0];
      ii->size[0] = nx;
      emxEnsureCapacity(sp, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      for (ix = 0; ix < nx; ix++) {
        ii->data[ix] = ix;
      }

      iv3[0] = 1;
      iv3[1] = ii->size[0];
      emlrtSubAssignSizeCheckR2012b(iv3, 2, *(int32_T (*)[2])curr_col->size, 2,
        &b_emlrtECI, sp);
      emlrt_update_log_4(curr_col, emlrtLocationLoggingDataTables, 29);
      nx = curr_col->size[1];
      for (ix = 0; ix < nx; ix++) {
        context->data[((int32_T)coccidx + context->size[0] * ii->data[ix]) - 1] =
          curr_col->data[curr_col->size[0] * ix];
      }
    }

    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 0, 0);

  /*  ems_intensify = etime(clock, iclk)*1000; */
  /*  2 Attenuate unoccupied cells */
  /*  iclk = clock; */
  j = 0;
  while (j <= (int32_T)nrnocc - 1) {
    b_j = emlrt_update_log_3(1.0 + (real_T)j, emlrtLocationLoggingDataTables, 59);
    covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 4);

    /*  For unoccupied cells */
    ix = noccidx->size[0];
    idx = (int32_T)b_j;
    if (!((idx >= 1) && (idx <= ix))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &y_emlrtBCI, sp);
    }

    cnoccidx = emlrt_update_log_3(noccidx->data[idx - 1],
      emlrtLocationLoggingDataTables, 30);
    nx = context->size[1];
    ix = context->size[0];
    iy = (int32_T)cnoccidx;
    if (!((iy >= 1) && (iy <= ix))) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &e_emlrtBCI, sp);
    }

    ix = curr_col->size[0] * curr_col->size[1];
    curr_col->size[0] = 1;
    curr_col->size[1] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)curr_col, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < nx; ix++) {
      curr_col->data[curr_col->size[0] * ix] = context->data[(iy + context->
        size[0] * ix) - 1];
    }

    emlrt_update_log_4(curr_col, emlrtLocationLoggingDataTables, 31);
    ix = curr_col->size[0] * curr_col->size[1];
    curr_col->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)curr_col, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    iy = curr_col->size[0];
    nx = curr_col->size[1];
    nx *= iy;
    for (ix = 0; ix < nx; ix++) {
      curr_col->data[ix] *= nocc_attenuaterate;
    }

    emlrt_update_log_4(curr_col, emlrtLocationLoggingDataTables, 32);

    /*  Attenuate */
    ix = context->size[0];
    idx = (int32_T)cnoccidx;
    if (!((idx >= 1) && (idx <= ix))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &d_emlrtBCI, sp);
    }

    nx = context->size[1];
    ix = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)ii, ix, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (ix = 0; ix < nx; ix++) {
      ii->data[ix] = ix;
    }

    iv4[0] = 1;
    iv4[1] = ii->size[0];
    emlrtSubAssignSizeCheckR2012b(iv4, 2, *(int32_T (*)[2])curr_col->size, 2,
      &emlrtECI, sp);
    emlrt_update_log_4(curr_col, emlrtLocationLoggingDataTables, 33);
    nx = curr_col->size[1];
    for (ix = 0; ix < nx; ix++) {
      context->data[((int32_T)cnoccidx + context->size[0] * ii->data[ix]) - 1] =
        curr_col->data[curr_col->size[0] * ix];
    }

    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&ii);
  covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 1, 0);

  /*  ems_attenuate = etime(clock, iclk)*1000; */
  /*  3 Propagation */
  /*  iclk = clock; */
  j = 0;
  while (j <= (int32_T)nrocc - 1) {
    b_j = emlrt_update_log_3(1.0 + (real_T)j, emlrtLocationLoggingDataTables, 60);
    covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 2, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 5);

    /*  For occupied cells */
    ix = occidx->size[0];
    idx = (int32_T)b_j;
    if (!((idx >= 1) && (idx <= ix))) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &q_emlrtBCI, sp);
    }

    cpropidx = emlrt_update_log_3(occidx->data[idx - 1],
      emlrtLocationLoggingDataTables, 34);
    nx = context->size[1];
    ix = context->size[0];
    iy = (int32_T)cpropidx;
    if (!((iy >= 1) && (iy <= ix))) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &c_emlrtBCI, sp);
    }

    ix = curr_col->size[0] * curr_col->size[1];
    curr_col->size[0] = 1;
    curr_col->size[1] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)curr_col, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < nx; ix++) {
      curr_col->data[curr_col->size[0] * ix] = context->data[(iy + context->
        size[0] * ix) - 1];
    }

    emlrt_update_log_4(curr_col, emlrtLocationLoggingDataTables, 35);
    nx = nei_idx->size[1];
    ix = nei_idx->size[0];
    iy = (int32_T)cpropidx;
    if (!((iy >= 1) && (iy <= ix))) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &b_emlrtBCI, sp);
    }

    ix = cneicon->size[0] * cneicon->size[1];
    cneicon->size[0] = 1;
    cneicon->size[1] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)cneicon, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < nx; ix++) {
      cneicon->data[cneicon->size[0] * ix] = nei_idx->data[(iy + nei_idx->size[0]
        * ix) - 1];
    }

    emlrt_update_log_4(cneicon, emlrtLocationLoggingDataTables, 36);
    nx = nei_weight->size[1];
    ix = nei_weight->size[0];
    iy = (int32_T)cpropidx;
    if (!((iy >= 1) && (iy <= ix))) {
      emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &emlrtBCI, sp);
    }

    ix = cneiweight->size[0] * cneiweight->size[1];
    cneiweight->size[0] = 1;
    cneiweight->size[1] = nx;
    emxEnsureCapacity(sp, (emxArray__common *)cneiweight, ix, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (ix = 0; ix < nx; ix++) {
      cneiweight->data[cneiweight->size[0] * ix] = nei_weight->data[(iy +
        nei_weight->size[0] * ix) - 1];
    }

    emlrt_update_log_4(cneiweight, emlrtLocationLoggingDataTables, 37);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nei_filter_n, mxDOUBLE_CLASS,
      (int32_T)nei_filter_n, &w_emlrtRTEI, sp);
    k = 0;
    while (k <= (int32_T)nei_filter_n - 1) {
      b_k = emlrt_update_log_3(1.0 + (real_T)k, emlrtLocationLoggingDataTables,
        62);
      covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 3, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 6);

      /*  For all neighbor cells */
      ix = curr_col->size[1];
      idx = (int32_T)b_k;
      if (!((idx >= 1) && (idx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &r_emlrtBCI, sp);
      }

      contextval = emlrt_update_log_3(curr_col->data[idx - 1],
        emlrtLocationLoggingDataTables, 38);
      ix = cneicon->size[1];
      idx = (int32_T)b_k;
      if (!((idx >= 1) && (idx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &s_emlrtBCI, sp);
      }

      neiidx = emlrt_update_log_3(cneicon->data[idx - 1],
        emlrtLocationLoggingDataTables, 39);
      ix = cneiweight->size[1];
      idx = (int32_T)b_k;
      if (!((idx >= 1) && (idx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &t_emlrtBCI, sp);
      }

      weightval = emlrt_update_log_3(cneiweight->data[idx - 1],
        emlrtLocationLoggingDataTables, 40);
      if (covrtLogIf(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 1, neiidx
                     != 0.0)) {
        covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 7);

        /*  If properly connected, propagate */
        ix = context->size[0];
        if (neiidx != (int32_T)muDoubleScalarFloor(neiidx)) {
          emlrtIntegerCheckR2012b(neiidx, &b_emlrtDCI, sp);
        }

        idx = (int32_T)neiidx;
        if (!((idx >= 1) && (idx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &u_emlrtBCI, sp);
        }

        ix = context->size[1];
        iy = (int32_T)b_k;
        if (!((iy >= 1) && (iy <= ix))) {
          emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &v_emlrtBCI, sp);
        }

        origvontextval = emlrt_update_log_3(context->data[(idx + context->size[0]
          * (iy - 1)) - 1], emlrtLocationLoggingDataTables, 41);
        updtcontextval = emlrt_update_log_3(weightval * contextval,
          emlrtLocationLoggingDataTables, 42);
        updtcontextval = emlrt_update_log_3(muDoubleScalarMin(updtcontextval,
          maxthreshold), emlrtLocationLoggingDataTables, 43);

        /*  Maximum value thresholding */
        ix = context->size[0];
        idx = (int32_T)neiidx;
        if (!((idx >= 1) && (idx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &w_emlrtBCI, sp);
        }

        ix = context->size[1];
        iy = (int32_T)b_k;
        if (!((iy >= 1) && (iy <= ix))) {
          emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &x_emlrtBCI, sp);
        }

        context->data[(idx + context->size[0] * (iy - 1)) - 1] =
          emlrt_update_log_3(muDoubleScalarMax(origvontextval, updtcontextval),
                             emlrtLocationLoggingDataTables, 44);

        /*  Make sure current context propagation does not weaken the flow information */
      }

      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 3, 0);
    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 2, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 8);

  /*  ems_propagate = etime(clock, iclk)*1000; */
  /*  4 Uncertainty in acceleration */
  /*  iclk = clock; */
  ix = tempcontext->size[0] * tempcontext->size[1];
  tempcontext->size[0] = context->size[0];
  tempcontext->size[1] = context->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)tempcontext, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  nx = context->size[0] * context->size[1];
  for (ix = 0; ix < nx; ix++) {
    tempcontext->data[ix] = context->data[ix];
  }

  b_emlrt_update_log_2(tempcontext, emlrtLocationLoggingDataTables, 45);
  k = 0;
  while (k <= nei_idx->size[0] - 1) {
    b_k = emlrt_update_log_3(1.0 + (real_T)k, emlrtLocationLoggingDataTables, 61);
    covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 4, 1);

    /*  For all cells */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, nei_filter_n, mxDOUBLE_CLASS,
      (int32_T)nei_filter_n, &v_emlrtRTEI, sp);
    j = 0;
    while (j <= (int32_T)nei_filter_n - 1) {
      b_j = emlrt_update_log_3(1.0 + (real_T)j, emlrtLocationLoggingDataTables,
        63);
      covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 5, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 9);

      /*  For all context level */
      sumval = emlrt_update_log_3(0.0, emlrtLocationLoggingDataTables, 46);
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, nei4u_filter_n, mxDOUBLE_CLASS,
        (int32_T)nei4u_filter_n, &u_emlrtRTEI, sp);
      m = 0;
      while (m <= (int32_T)nei4u_filter_n - 1) {
        b_m = emlrt_update_log_3(1.0 + (real_T)m, emlrtLocationLoggingDataTables,
          64);
        covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 6, 1);
        covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 10);
        ix = nei4u_idx->size[0];
        idx = (int32_T)b_k;
        if (!((idx >= 1) && (idx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &k_emlrtBCI, sp);
        }

        ix = nei4u_idx->size[1];
        iy = (int32_T)b_m;
        if (!((iy >= 1) && (iy <= ix))) {
          emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &l_emlrtBCI, sp);
        }

        nidx = emlrt_update_log_3(nei4u_idx->data[(idx + nei4u_idx->size[0] *
          (iy - 1)) - 1], emlrtLocationLoggingDataTables, 47);
        ix = nei4u_weight->size[0];
        idx = (int32_T)b_k;
        if (!((idx >= 1) && (idx <= ix))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &m_emlrtBCI, sp);
        }

        ix = nei4u_weight->size[1];
        iy = (int32_T)b_m;
        if (!((iy >= 1) && (iy <= ix))) {
          emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &n_emlrtBCI, sp);
        }

        nwei = emlrt_update_log_3(nei4u_weight->data[(idx + nei4u_weight->size[0]
          * (iy - 1)) - 1], emlrtLocationLoggingDataTables, 48);
        if (covrtLogIf(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 2, nidx
                       != 0.0)) {
          covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 11);
          ix = context->size[0];
          if (nidx != (int32_T)muDoubleScalarFloor(nidx)) {
            emlrtIntegerCheckR2012b(nidx, &emlrtDCI, sp);
          }

          idx = (int32_T)nidx;
          if (!((idx >= 1) && (idx <= ix))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &o_emlrtBCI, sp);
          }

          ix = context->size[1];
          iy = (int32_T)b_j;
          if (!((iy >= 1) && (iy <= ix))) {
            emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &p_emlrtBCI, sp);
          }

          curr_val = emlrt_update_log_3(context->data[(idx + context->size[0] *
            (iy - 1)) - 1], emlrtLocationLoggingDataTables, 49);
          sumval = emlrt_update_log_3(sumval + emlrt_update_log_3(nwei *
            curr_val, emlrtLocationLoggingDataTables, 51),
            emlrtLocationLoggingDataTables, 50);
        }

        m++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 6, 0);
      covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 12);
      ix = tempcontext->size[0];
      idx = (int32_T)b_k;
      if (!((idx >= 1) && (idx <= ix))) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ix, &i_emlrtBCI, sp);
      }

      ix = tempcontext->size[1];
      iy = (int32_T)b_j;
      if (!((iy >= 1) && (iy <= ix))) {
        emlrtDynamicBoundsCheckR2012b(iy, 1, ix, &j_emlrtBCI, sp);
      }

      tempcontext->data[(idx + tempcontext->size[0] * (iy - 1)) - 1] =
        emlrt_update_log_3(sumval, emlrtLocationLoggingDataTables, 52);
      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 5, 0);
    k++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 4, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 13);
  ix = context->size[0] * context->size[1];
  context->size[0] = tempcontext->size[0];
  context->size[1] = tempcontext->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)context, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  nx = tempcontext->size[1];
  for (ix = 0; ix < nx; ix++) {
    iy = tempcontext->size[0];
    for (idx = 0; idx < iy; idx++) {
      context->data[idx + context->size[0] * ix] = tempcontext->data[idx +
        tempcontext->size[0] * ix];
    }
  }

  b_emlrt_update_log_2(context, emlrtLocationLoggingDataTables, 53);

  /*  ems_uia = etime(clock, iclk)*1000; */
  /*  5 Prediction */
  /*  iclk = clock; */
  st.site = &f_emlrtRSI;
  ix = tempcontext->size[0] * tempcontext->size[1];
  tempcontext->size[0] = context->size[1];
  tempcontext->size[1] = context->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)tempcontext, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  nx = context->size[0];
  for (ix = 0; ix < nx; ix++) {
    iy = context->size[1];
    for (idx = 0; idx < iy; idx++) {
      tempcontext->data[idx + tempcontext->size[0] * ix] = context->data[ix +
        context->size[0] * idx];
    }
  }

  b_st.site = &m_emlrtRSI;
  c_st.site = &n_emlrtRSI;
  if (((tempcontext->size[0] == 1) && (tempcontext->size[1] == 1)) ||
      (tempcontext->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (tempcontext->size[0] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &p_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  ix = cneicon->size[0] * cneicon->size[1];
  cneicon->size[0] = 1;
  cneicon->size[1] = tempcontext->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)cneicon, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  n = tempcontext->size[0];
  b_ix = 0;
  iy = -1;
  d_st.site = &v_emlrtRSI;
  if (1 > tempcontext->size[1]) {
    overflow = false;
  } else {
    overflow = (tempcontext->size[1] > 2147483646);
  }

  if (overflow) {
    e_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (nx = 1; nx <= tempcontext->size[1]; nx++) {
    d_st.site = &w_emlrtRSI;
    ixstart = b_ix;
    idx = b_ix + n;
    mtmp = tempcontext->data[b_ix];
    if (n > 1) {
      if (muDoubleScalarIsNaN(tempcontext->data[b_ix])) {
        e_st.site = &q_emlrtRSI;
        if (b_ix + 2 > idx) {
          c_ix = false;
        } else {
          c_ix = (idx > 2147483646);
        }

        if (c_ix) {
          f_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        ix = b_ix + 1;
        exitg2 = false;
        while ((!exitg2) && (ix + 1 <= idx)) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(tempcontext->data[ix])) {
            mtmp = tempcontext->data[ix];
            exitg2 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart + 1 < idx) {
        e_st.site = &p_emlrtRSI;
        if (ixstart + 2 > idx) {
          b_ixstart = false;
        } else {
          b_ixstart = (idx > 2147483646);
        }

        if (b_ixstart) {
          f_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (ix = ixstart + 1; ix + 1 <= idx; ix++) {
          if (tempcontext->data[ix] > mtmp) {
            mtmp = tempcontext->data[ix];
          }
        }
      }
    }

    iy++;
    cneicon->data[iy] = mtmp;
    b_ix += n;
  }

  emlrt_update_log_4(cneicon, emlrtLocationLoggingDataTables, 55);
  ix = maxvec->size[0];
  maxvec->size[0] = cneicon->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)maxvec, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  nx = cneicon->size[1];
  for (ix = 0; ix < nx; ix++) {
    maxvec->data[ix] = cneicon->data[cneicon->size[0] * ix];
  }

  emxInit_real_T(sp, &b_maxvec, 1, &emlrtRTEI, true);
  b_emlrt_update_log_1(maxvec, emlrtLocationLoggingDataTables, 54);
  st.site = &g_emlrtRSI;

  /* logging input variable 'x' for function 'sigm' */
  emlrt_update_log_1(&st, maxvec, emlrtLocationLoggingDataTables, 65, b_maxvec);

  /* logging input variable 'sigm_a' for function 'sigm' */
  emlrt_update_log_3(sigm_coef, emlrtLocationLoggingDataTables, 66);
  covrtLogFcn(&emlrtCoverageInstance, (uint32_T)0, 1);
  covrtLogBasicBlock(&emlrtCoverageInstance, (uint32_T)0, 14);
  a = emlrt_update_log_3(sigm_coef, emlrtLocationLoggingDataTables, 67);

  /*  sigm_a  <= if we increase the value, than the sigm function gets peaky! */
  ix = predvec->size[0];
  predvec->size[0] = maxvec->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)predvec, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  nx = maxvec->size[0];
  emxFree_real_T(&b_maxvec);
  for (ix = 0; ix < nx; ix++) {
    predvec->data[ix] = -a * maxvec->data[ix];
  }

  b_emlrt_update_log_1(predvec, emlrtLocationLoggingDataTables, 71);
  ix = newlyoccidx->size[0];
  newlyoccidx->size[0] = maxvec->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)newlyoccidx, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  nx = maxvec->size[0];
  for (ix = 0; ix < nx; ix++) {
    newlyoccidx->data[ix] = -a * maxvec->data[ix];
  }

  b_emlrt_update_log_1(newlyoccidx, emlrtLocationLoggingDataTables, 74);
  b_st.site = &x_emlrtRSI;
  b_exp(&b_st, predvec);
  b_emlrt_update_log_1(predvec, emlrtLocationLoggingDataTables, 70);
  ix = predvec->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)predvec, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  nx = predvec->size[0];
  for (ix = 0; ix < nx; ix++) {
    predvec->data[ix] = 1.0 - predvec->data[ix];
  }

  b_emlrt_update_log_1(predvec, emlrtLocationLoggingDataTables, 69);
  b_st.site = &x_emlrtRSI;
  b_exp(&b_st, newlyoccidx);
  b_emlrt_update_log_1(newlyoccidx, emlrtLocationLoggingDataTables, 73);
  ix = newlyoccidx->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)newlyoccidx, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  nx = newlyoccidx->size[0];
  for (ix = 0; ix < nx; ix++) {
    newlyoccidx->data[ix]++;
  }

  b_emlrt_update_log_1(newlyoccidx, emlrtLocationLoggingDataTables, 72);
  b_st.site = &x_emlrtRSI;
  varargin_1[0] = predvec->size[0];
  varargin_1[1] = 1;
  varargin_2[0] = newlyoccidx->size[0];
  varargin_2[1] = 1;
  overflow = false;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(varargin_1[k] == varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!p) {
  } else {
    overflow = true;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&b_st, &r_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  ix = predvec->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)predvec, ix, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  nx = predvec->size[0];
  for (ix = 0; ix < nx; ix++) {
    predvec->data[ix] /= newlyoccidx->data[ix];
  }

  b_emlrt_update_log_1(predvec, emlrtLocationLoggingDataTables, 68);
  b_emlrt_update_log_1(predvec, emlrtLocationLoggingDataTables, 56);

  /*  ems_predict = etime(clock, iclk)*1000; */
  /*  6 Save previous grid */
  ix = cgridvecprev->size[0];
  cgridvecprev->size[0] = cgridvec->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)cgridvecprev, ix, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  nx = cgridvec->size[0];
  for (ix = 0; ix < nx; ix++) {
    cgridvecprev->data[ix] = cgridvec->data[ix];
  }

  b_emlrt_update_log_1(cgridvecprev, emlrtLocationLoggingDataTables, 57);
  covrtLogIf(&emlrtCoverageInstance, (uint32_T)0, (uint32_T)0, 3, false);
  emxFree_real_T(&tempcontext);
  emxFree_real_T(&cneiweight);
  emxFree_real_T(&cneicon);
  emxFree_real_T(&curr_col);
  emxFree_real_T(&noccidx);
  emxFree_real_T(&occidx);
  emxFree_real_T(&newlyoccidx);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (occflow.c) */
