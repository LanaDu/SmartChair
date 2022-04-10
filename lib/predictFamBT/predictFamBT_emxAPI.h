/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictFamBT_emxAPI.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

#ifndef PREDICTFAMBT_EMXAPI_H
#define PREDICTFAMBT_EMXAPI_H

/* Include Files */
#include "predictFamBT_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_cell_wrap_0 *emxCreateND_cell_wrap_0(int numDimensions,
                                                     const int *size);

extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);

extern emxArray_cell_wrap_0 *emxCreateWrapperND_cell_wrap_0(cell_wrap_0 *data,
                                                            int numDimensions,
                                                            const int *size);

extern emxArray_real_T *
emxCreateWrapperND_real_T(double *data, int numDimensions, const int *size);

extern emxArray_cell_wrap_0 *emxCreateWrapper_cell_wrap_0(cell_wrap_0 *data,
                                                          int rows, int cols);

extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows,
                                                int cols);

extern emxArray_cell_wrap_0 *emxCreate_cell_wrap_0(int rows, int cols);

extern emxArray_real_T *emxCreate_real_T(int rows, int cols);

extern void emxDestroyArray_cell_wrap_0(emxArray_cell_wrap_0 *emxArray);

extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);

extern void emxInitArray_cell_wrap_0(emxArray_cell_wrap_0 **pEmxArray,
                                     int numDimensions);

extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for predictFamBT_emxAPI.h
 *
 * [EOF]
 */
