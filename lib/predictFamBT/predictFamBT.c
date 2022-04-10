/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictFamBT.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

/* Include Files */
#include "predictFamBT.h"
#include "aggregatePredict.h"
#include "predictFamBT_data.h"
#include "predictFamBT_emxutil.h"
#include "predictFamBT_initialize.h"
#include "predictFamBT_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_cell_wrap_0 *label
 * Return Type  : void
 */
void predictFamBT(const emxArray_real_T *X, emxArray_cell_wrap_0 *label)
{
  cell_wrap_0 r1;
  emxArray_boolean_T *b;
  emxArray_boolean_T *notNaN;
  emxArray_boolean_T *r;
  emxArray_real_T *classnum;
  emxArray_real_T *scoreIn;
  double d;
  int i1;
  int i2;
  int ix;
  int j;
  int outsize_idx_0;
  unsigned int u;
  boolean_T bv[30];
  boolean_T bv1[30];
  boolean_T exitg1;
  if (!isInitialized_predictFamBT) {
    predictFamBT_initialize();
  }
  if (X->size[0] == 0) {
    label->size[0] = 0;
  } else {
    emxInit_real_T(&scoreIn, 2);
    ix = scoreIn->size[0] * scoreIn->size[1];
    scoreIn->size[0] = X->size[0];
    scoreIn->size[1] = 2;
    emxEnsureCapacity_real_T(scoreIn, ix);
    outsize_idx_0 = X->size[0] << 1;
    for (ix = 0; ix < outsize_idx_0; ix++) {
      scoreIn->data[ix] = 0.0;
    }
    for (ix = 0; ix < 30; ix++) {
      bv[ix] = false;
      bv1[ix] = true;
    }
    emxInit_boolean_T(&r, 2);
    ix = r->size[0] * r->size[1];
    r->size[0] = X->size[0];
    r->size[1] = 30;
    emxEnsureCapacity_boolean_T(r, ix);
    outsize_idx_0 = X->size[0] * 30;
    for (ix = 0; ix < outsize_idx_0; ix++) {
      r->data[ix] = true;
    }
    emxInit_boolean_T(&b, 2);
    aggregatePredict(X, scoreIn, bv, cv, bv1, r);
    ix = b->size[0] * b->size[1];
    b->size[0] = scoreIn->size[0];
    b->size[1] = 2;
    emxEnsureCapacity_boolean_T(b, ix);
    outsize_idx_0 = scoreIn->size[0] * 2;
    emxFree_boolean_T(&r);
    for (ix = 0; ix < outsize_idx_0; ix++) {
      b->data[ix] = rtIsNaN(scoreIn->data[ix]);
    }
    emxInit_boolean_T(&notNaN, 1);
    outsize_idx_0 = b->size[0];
    ix = notNaN->size[0];
    notNaN->size[0] = b->size[0];
    emxEnsureCapacity_boolean_T(notNaN, ix);
    for (ix = 0; ix < outsize_idx_0; ix++) {
      notNaN->data[ix] = true;
    }
    outsize_idx_0 = b->size[0];
    i2 = b->size[0];
    i1 = 0;
    for (j = 0; j < outsize_idx_0; j++) {
      i1++;
      i2++;
      ix = i1;
      exitg1 = false;
      while ((!exitg1) && ((outsize_idx_0 > 0) && (ix <= i2))) {
        if (!b->data[ix - 1]) {
          notNaN->data[j] = false;
          exitg1 = true;
        } else {
          ix += outsize_idx_0;
        }
      }
    }
    emxFree_boolean_T(&b);
    outsize_idx_0 = notNaN->size[0];
    for (ix = 0; ix < outsize_idx_0; ix++) {
      notNaN->data[ix] = !notNaN->data[ix];
    }
    emxInit_real_T(&classnum, 1);
    ix = classnum->size[0];
    classnum->size[0] = scoreIn->size[0];
    emxEnsureCapacity_real_T(classnum, ix);
    outsize_idx_0 = scoreIn->size[0];
    for (ix = 0; ix < outsize_idx_0; ix++) {
      classnum->data[ix] = rtNaN;
    }
    ix = notNaN->size[0];
    for (i1 = 0; i1 < ix; i1++) {
      if (notNaN->data[i1]) {
        if ((scoreIn->data[i1] < scoreIn->data[i1 + scoreIn->size[0]]) ||
            (rtIsNaN(scoreIn->data[i1]) &&
             (!rtIsNaN(scoreIn->data[i1 + scoreIn->size[0]])))) {
          outsize_idx_0 = 2;
        } else {
          outsize_idx_0 = 1;
        }
        classnum->data[i1] = outsize_idx_0;
      }
    }
    for (ix = 0; ix < 3; ix++) {
      r1.f1.data[ix] = cv[ix << 1];
    }
    ix = label->size[0];
    label->size[0] = scoreIn->size[0];
    emxEnsureCapacity_cell_wrap_0(label, ix);
    if (scoreIn->size[0] != 0) {
      outsize_idx_0 = scoreIn->size[0];
      for (i2 = 0; i2 < outsize_idx_0; i2++) {
        label->data[i2].f1.size[0] = 1;
        label->data[i2].f1.size[1] = 3;
        for (ix = 0; ix < 3; ix++) {
          label->data[i2].f1.data[ix] = r1.f1.data[ix];
        }
      }
    }
    emxFree_real_T(&scoreIn);
    ix = notNaN->size[0];
    for (i1 = 0; i1 < ix; i1++) {
      if (notNaN->data[i1]) {
        d = classnum->data[i1];
        if (d < 4.294967296E+9) {
          u = (unsigned int)d;
        } else {
          u = 0U;
        }
        outsize_idx_0 = (((int)u - 1) << 2) + 2;
        d = classnum->data[i1];
        if (d < 4.294967296E+9) {
          u = (unsigned int)d;
        } else {
          u = 0U;
        }
        label->data[i1].f1.size[0] = 1;
        label->data[i1].f1.size[1] = outsize_idx_0 + 1;
        for (i2 = 0; i2 <= outsize_idx_0; i2++) {
          label->data[i1].f1.data[i2] = cv[((int)u + (i2 << 1)) - 1];
        }
      }
    }
    emxFree_real_T(&classnum);
    emxFree_boolean_T(&notNaN);
  }
}

/*
 * File trailer for predictFamBT.c
 *
 * [EOF]
 */
