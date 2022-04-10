/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: aggregatePredict.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

#ifndef AGGREGATEPREDICT_H
#define AGGREGATEPREDICT_H

/* Include Files */
#include "predictFamBT_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void aggregatePredict(const emxArray_real_T *X, emxArray_real_T *score,
                      const boolean_T isCached[30], const char classNames[14],
                      const boolean_T learners[30],
                      const emxArray_boolean_T *useObsForLearner);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for aggregatePredict.h
 *
 * [EOF]
 */
