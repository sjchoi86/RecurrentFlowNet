/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_set_nei_unit_mex.c
 *
 * Code generation for function '_coder_set_nei_unit_mex'
 *
 */

/* Include files */
#include "set_nei_unit.h"
#include "_coder_set_nei_unit_mex.h"
#include "set_nei_unit_terminate.h"
#include "_coder_set_nei_unit_api.h"
#include "set_nei_unit_initialize.h"
#include "set_nei_unit_data.h"

/* Function Declarations */
static void set_nei_unit_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T
  nrhs, const mxArray *prhs[9]);

/* Function Definitions */
static void set_nei_unit_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T
  nrhs, const mxArray *prhs[9])
{
  int32_T n;
  const mxArray *inputs[9];
  const mxArray *outputs[2];
  int32_T b_nlhs;

  /* Check for proper number of arguments. */
  if (nrhs != 9) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 9, 4, 12, "set_nei_unit");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "set_nei_unit");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
  }

  /* Call the function. */
  set_nei_unit_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  set_nei_unit_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(set_nei_unit_atexit);

  /* Module initialization. */
  set_nei_unit_initialize();

  /* Dispatch the entry-point. */
  set_nei_unit_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_set_nei_unit_mex.c) */
