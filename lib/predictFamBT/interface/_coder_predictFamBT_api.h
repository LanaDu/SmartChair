/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_predictFamBT_api.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

#ifndef _CODER_PREDICTFAMBT_API_H
#define _CODER_PREDICTFAMBT_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_char_T_1x7
#define struct_emxArray_char_T_1x7
struct emxArray_char_T_1x7 {
  char_T data[7];
  int32_T size[2];
};
#endif /* struct_emxArray_char_T_1x7 */
#ifndef typedef_emxArray_char_T_1x7
#define typedef_emxArray_char_T_1x7
typedef struct emxArray_char_T_1x7 emxArray_char_T_1x7;
#endif /* typedef_emxArray_char_T_1x7 */

#ifndef typedef_cell_wrap_0
#define typedef_cell_wrap_0
typedef struct {
  emxArray_char_T_1x7 f1;
} cell_wrap_0;
#endif /* typedef_cell_wrap_0 */

#ifndef typedef_emxArray_cell_wrap_0
#define typedef_emxArray_cell_wrap_0
typedef struct {
  cell_wrap_0 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_0;
#endif /* typedef_emxArray_cell_wrap_0 */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void predictFamBT(emxArray_real_T *X, emxArray_cell_wrap_0 *label);

void predictFamBT_api(const mxArray *prhs, const mxArray **plhs);

void predictFamBT_atexit(void);

void predictFamBT_initialize(void);

void predictFamBT_terminate(void);

void predictFamBT_xil_shutdown(void);

void predictFamBT_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_predictFamBT_api.h
 *
 * [EOF]
 */
