/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * occflow_float_mex_initialize.c
 *
 * Code generation for function 'occflow_float_mex_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "forcePushIntoCloud.h"
#include "occflow.h"
#include "occflow_float_mex_initialize.h"
#include "_coder_occflow_float_mex_mex.h"
#include "occflow_float_mex_data.h"

/* Function Declarations */
static void occflow_float_mex_once(void);

/* Function Definitions */
static void occflow_float_mex_once(void)
{
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "/Users/human/Dropbox/Research/Implementation in papers/2017_IJRR_RecurrentFlowNet/occflow.m",
                  0, 2, 15, 4, 0, 0, 0, 7, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0, 0, "occflow", 0, -1, 3212);
  covrtFcnInit(&emlrtCoverageInstance, 0, 1, "sigm", 3212, -1, 3363);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 13, 2814, -1, 3055);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 12, 2774, -1, 2800);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 11, 2658, -1, 2736);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 10, 2554, -1, 2615);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 9, 2497, -1, 2507);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 8, 2372, -1, 2393);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 7, 1928, -1, 2177);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 6, 1763, -1, 1856);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 5, 1559, -1, 1701);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 4, 1283, -1, 1435);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 3, 977, -1, 1133);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 2, 905, -1, 936);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 1, 798, -1, 859);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 0, 447, -1, 692);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 14, 3241, -1, 3359);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0, 0, 865, 896, 964, 1142);
  covrtIfInit(&emlrtCoverageInstance, 0, 1, 1866, 1880, -1, 2267);
  covrtIfInit(&emlrtCoverageInstance, 0, 2, 2629, 2641, -1, 2753);
  covrtIfInit(&emlrtCoverageInstance, 0, 3, 3058, 3062, -1, 3210);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0, 0, 746, 767, 1146);
  covrtForInit(&emlrtCoverageInstance, 0, 1, 1239, 1256, 1440);
  covrtForInit(&emlrtCoverageInstance, 0, 2, 1518, 1534, 2279);
  covrtForInit(&emlrtCoverageInstance, 0, 3, 1707, 1730, 2275);
  covrtForInit(&emlrtCoverageInstance, 0, 4, 2395, 2422, 2813);
  covrtForInit(&emlrtCoverageInstance, 0, 5, 2442, 2465, 2809);
  covrtForInit(&emlrtCoverageInstance, 0, 6, 2517, 2542, 2765);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void occflow_float_mex_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    occflow_float_mex_once();
  }
}

/* End of code generation (occflow_float_mex_initialize.c) */
