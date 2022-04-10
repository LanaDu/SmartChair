/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_predictFamBT_api.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

/* Include Files */
#include "_coder_predictFamBT_api.h"
#include "_coder_predictFamBT_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131610U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "predictFamBT",                                       /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret);

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *X,
                             const char_T *identifier, emxArray_real_T *y);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_cell_wrap_0 *u);

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel);

static void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray);

static void emxFree_real_T(emxArray_real_T **pEmxArray);

static void emxInit_cell_wrap_0(const emlrtStack *sp,
                                emxArray_cell_wrap_0 **pEmxArray,
                                int32_T numDimensions, boolean_T doPush);

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions, boolean_T doPush);

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_real_T *ret)
{
  static const int32_T dims[2] = {-1, 13};
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(ret, i);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *X
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *X,
                             const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(X), &thisId, y);
  emlrtDestroyArray(&X);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const emxArray_cell_wrap_0 *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_cell_wrap_0 *u)
{
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  char_T u_data[7];
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, &u->size[0]));
  for (i = 0; i < u->size[0]; i++) {
    loop_ub = u->data[i].f1.size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      u_data[i1] = u->data[i].f1.data[i1];
    }
    b_y = NULL;
    iv[0] = 1;
    iv[1] = u->data[i].f1.size[1];
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtCTX)sp, u->data[i].f1.size[1], m,
                             &u_data[0]);
    emlrtAssign(&b_y, m);
    emlrtSetCell(y, i, b_y);
  }
  return y;
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray,
                                     int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_cell_wrap_0 **pEmxArray
 * Return Type  : void
 */
static void emxFree_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray)
{
  if (*pEmxArray != (emxArray_cell_wrap_0 *)NULL) {
    if (((*pEmxArray)->data != (cell_wrap_0 *)NULL) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_0 *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_cell_wrap_0 **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_cell_wrap_0(const emlrtStack *sp,
                                emxArray_cell_wrap_0 **pEmxArray,
                                int32_T numDimensions, boolean_T doPush)
{
  emxArray_cell_wrap_0 *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_cell_wrap_0 *)emlrtMallocMex(sizeof(emxArray_cell_wrap_0));
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_0, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_0 *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                           int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, false, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void predictFamBT_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_cell_wrap_0 *label;
  emxArray_real_T *X;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &X, 2, true);
  emxInit_cell_wrap_0(&st, &label, 1, true);
  /* Marshall function inputs */
  X->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs), "X", X);
  /* Invoke the target function */
  predictFamBT(X, label);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, label);
  emxFree_cell_wrap_0(&label);
  emxFree_real_T(&X);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void predictFamBT_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  predictFamBT_xil_terminate();
  predictFamBT_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void predictFamBT_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void predictFamBT_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_predictFamBT_api.c
 *
 * [EOF]
 */
