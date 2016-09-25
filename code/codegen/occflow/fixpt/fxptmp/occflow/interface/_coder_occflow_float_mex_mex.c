/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_occflow_float_mex_mex.c
 *
 * Code generation for function '_coder_occflow_float_mex_mex'
 *
 */

/* Include files */
#include "forcePushIntoCloud.h"
#include "occflow.h"
#include "_coder_occflow_float_mex_mex.h"
#include "occflow_float_mex_terminate.h"
#include "_coder_occflow_float_mex_api.h"
#include "occflow_float_mex_initialize.h"
#include "occflow_float_mex_data.h"

/* Variable Definitions */
static const char * emlrtEntryPoints[2] = { "occflow", "forcePushIntoCloud" };

/* Function Declarations */
static void forcePushIntoCloud_mexFunction(int32_T nlhs, int32_T nrhs);
static void occflow_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
  const mxArray *prhs[17]);

/* Function Definitions */
static void forcePushIntoCloud_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        18, "forcePushIntoCloud");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "forcePushIntoCloud");
  }

  /* Call the function. */
  forcePushIntoCloud_api();

  /* Module termination. */
  occflow_float_mex_terminate();
}

static void occflow_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
  const mxArray *prhs[17])
{
  int32_T n;
  const mxArray *inputs[17];
  const mxArray *outputs[4];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 17) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 17, 4,
                        7, "occflow");
  }

  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "occflow");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  occflow_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  occflow_float_mex_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(occflow_float_mex_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  occflow_float_mex_initialize();

  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndex(nrhs, prhs, emlrtEntryPoints, 2)) {
   case 0:
    occflow_mexFunction(nlhs, plhs, nrhs - 1, &prhs[1]);
    break;

   case 1:
    forcePushIntoCloud_mexFunction(nlhs, nrhs - 1);
    break;
  }
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_occflow_float_mex_mex.c) */
