/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_occflow_mex.c
 *
 * Code generation for function '_coder_occflow_mex'
 *
 */

/* Include files */
#include "occflow.h"
#include "_coder_occflow_mex.h"
#include "occflow_terminate.h"
#include "_coder_occflow_api.h"
#include "occflow_initialize.h"
#include "occflow_data.h"

/* Function Declarations */
static void occflow_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
  const mxArray *prhs[17]);

/* Function Definitions */
static void occflow_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
  const mxArray *prhs[17])
{
  int32_T n;
  const mxArray *inputs[17];
  const mxArray *outputs[4];
  int32_T b_nlhs;

  /* Check for proper number of arguments. */
  if (nrhs != 17) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 17, 4, 7, "occflow");
  }

  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "occflow");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
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
  occflow_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(occflow_atexit);

  /* Module initialization. */
  occflow_initialize();

  /* Dispatch the entry-point. */
  occflow_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_occflow_mex.c) */
