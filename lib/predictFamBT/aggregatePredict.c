/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: aggregatePredict.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

/* Include Files */
#include "aggregatePredict.h"
#include "CompactClassificationTree.h"
#include "predictFamBT_emxutil.h"
#include "predictFamBT_internal_types.h"
#include "predictFamBT_types.h"
#include "predictOneWithCache.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *X
 *                emxArray_real_T *score
 *                const boolean_T isCached[30]
 *                const char classNames[14]
 *                const boolean_T learners[30]
 *                const emxArray_boolean_T *useObsForLearner
 * Return Type  : void
 */
void aggregatePredict(const emxArray_real_T *X, emxArray_real_T *score,
                      const boolean_T isCached[30], const char classNames[14],
                      const boolean_T learners[30],
                      const emxArray_boolean_T *useObsForLearner)
{
  static const char combiner[15] = {'W', 'e', 'i', 'g', 'h', 't', 'e', 'd',
                                    'A', 'v', 'e', 'r', 'a', 'g', 'e'};
  emxArray_boolean_T *b_useObsForLearner;
  emxArray_real_T *cachedScore;
  emxArray_real_T *cachedWeights;
  double h_weak_learner_Children[198];
  double h_weak_learner_ClassProbability[198];
  double weak_learner_Children[186];
  double weak_learner_ClassProbability[186];
  double f_weak_learner_Children[182];
  double f_weak_learner_ClassProbability[182];
  double o_weak_learner_Children[178];
  double o_weak_learner_ClassProbability[178];
  double e_weak_learner_Children[166];
  double e_weak_learner_ClassProbability[166];
  double c_weak_learner_Children[162];
  double c_weak_learner_ClassProbability[162];
  double j_weak_learner_Children[158];
  double j_weak_learner_ClassProbability[158];
  double b_weak_learner_Children[154];
  double b_weak_learner_ClassProbability[154];
  double p_weak_learner_Children[150];
  double p_weak_learner_ClassProbability[150];
  double l_weak_learner_Children[142];
  double l_weak_learner_ClassProbability[142];
  double k_weak_learner_Children[138];
  double k_weak_learner_ClassProbability[138];
  double g_weak_learner_Children[134];
  double g_weak_learner_ClassProbability[134];
  double i_weak_learner_Children[130];
  double i_weak_learner_ClassProbability[130];
  double d_weak_learner_Children[126];
  double d_weak_learner_ClassProbability[126];
  double m_weak_learner_Children[122];
  double m_weak_learner_ClassProbability[122];
  double n_weak_learner_Children[118];
  double n_weak_learner_ClassProbability[118];
  double h_weak_learner_CutPoint[99];
  double h_weak_learner_CutPredictorInde[99];
  double weak_learner_CutPoint[93];
  double weak_learner_CutPredictorIndex[93];
  double f_weak_learner_CutPoint[91];
  double f_weak_learner_CutPredictorInde[91];
  double o_weak_learner_CutPoint[89];
  double o_weak_learner_CutPredictorInde[89];
  double e_weak_learner_CutPoint[83];
  double e_weak_learner_CutPredictorInde[83];
  double c_weak_learner_CutPoint[81];
  double c_weak_learner_CutPredictorInde[81];
  double j_weak_learner_CutPoint[79];
  double j_weak_learner_CutPredictorInde[79];
  double b_weak_learner_CutPoint[77];
  double b_weak_learner_CutPredictorInde[77];
  double p_weak_learner_CutPoint[75];
  double p_weak_learner_CutPredictorInde[75];
  double l_weak_learner_CutPoint[71];
  double l_weak_learner_CutPredictorInde[71];
  double k_weak_learner_CutPoint[69];
  double k_weak_learner_CutPredictorInde[69];
  double g_weak_learner_CutPoint[67];
  double g_weak_learner_CutPredictorInde[67];
  double i_weak_learner_CutPoint[65];
  double i_weak_learner_CutPredictorInde[65];
  double d_weak_learner_CutPoint[63];
  double d_weak_learner_CutPredictorInde[63];
  double m_weak_learner_CutPoint[61];
  double m_weak_learner_CutPredictorInde[61];
  double n_weak_learner_CutPoint[59];
  double n_weak_learner_CutPredictorInde[59];
  double weak_learner_Cost[4];
  double weak_learner_Prior[2];
  int weak_learner_ClassNamesLength[2];
  int i;
  int loop_ub;
  char weak_learner_ClassNames[14];
  boolean_T h_weak_learner_NanCutPoints[99];
  boolean_T j_expl_temp[99];
  boolean_T expl_temp[93];
  boolean_T weak_learner_NanCutPoints[93];
  boolean_T f_weak_learner_NanCutPoints[91];
  boolean_T h_expl_temp[91];
  boolean_T o_weak_learner_NanCutPoints[89];
  boolean_T q_expl_temp[89];
  boolean_T e_weak_learner_NanCutPoints[83];
  boolean_T g_expl_temp[83];
  boolean_T c_weak_learner_NanCutPoints[81];
  boolean_T e_expl_temp[81];
  boolean_T j_weak_learner_NanCutPoints[79];
  boolean_T l_expl_temp[79];
  boolean_T b_weak_learner_NanCutPoints[77];
  boolean_T d_expl_temp[77];
  boolean_T p_weak_learner_NanCutPoints[75];
  boolean_T r_expl_temp[75];
  boolean_T l_weak_learner_NanCutPoints[71];
  boolean_T n_expl_temp[71];
  boolean_T k_weak_learner_NanCutPoints[69];
  boolean_T m_expl_temp[69];
  boolean_T g_weak_learner_NanCutPoints[67];
  boolean_T i_expl_temp[67];
  boolean_T i_weak_learner_NanCutPoints[65];
  boolean_T k_expl_temp[65];
  boolean_T d_weak_learner_NanCutPoints[63];
  boolean_T f_expl_temp[63];
  boolean_T m_weak_learner_NanCutPoints[61];
  boolean_T o_expl_temp[61];
  boolean_T n_weak_learner_NanCutPoints[59];
  boolean_T p_expl_temp[59];
  boolean_T c_expl_temp[2];
  boolean_T b;
  boolean_T firstCache;
  boolean_T initCache;
  c_classreg_learning_coderutils_ b_expl_temp;
  emxInit_real_T(&cachedScore, 2);
  i = cachedScore->size[0] * cachedScore->size[1];
  cachedScore->size[0] = score->size[0];
  cachedScore->size[1] = 2;
  emxEnsureCapacity_real_T(cachedScore, i);
  loop_ub = score->size[0] * 2;
  for (i = 0; i < loop_ub; i++) {
    cachedScore->data[i] = score->data[i];
  }
  emxInit_real_T(&cachedWeights, 1);
  i = cachedWeights->size[0];
  cachedWeights->size[0] = score->size[0];
  emxEnsureCapacity_real_T(cachedWeights, i);
  loop_ub = score->size[0];
  for (i = 0; i < loop_ub; i++) {
    cachedWeights->data[i] = 0.0;
  }
  firstCache = true;
  emxInit_boolean_T(&b_useObsForLearner, 1);
  if (learners[0]) {
    firstCache = false;
    c_CompactClassificationTree_Com(
        weak_learner_CutPredictorIndex, weak_learner_Children,
        weak_learner_CutPoint, weak_learner_NanCutPoints, expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        weak_learner_ClassProbability);
    b = false;
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] = useObsForLearner->data[i];
    }
    predictOneWithCache(
        X, cachedScore, cachedWeights, combiner, weak_learner_CutPredictorIndex,
        weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
        weak_learner_ClassNames, weak_learner_ClassNamesLength,
        weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability,
        &b, classNames, b_useObsForLearner, true, score);
  }
  if (learners[1]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    d_CompactClassificationTree_Com(
        b_weak_learner_CutPredictorInde, b_weak_learner_Children,
        b_weak_learner_CutPoint, b_weak_learner_NanCutPoints, d_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        b_weak_learner_ClassProbability);
    b = isCached[1];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0]];
    }
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[2]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    e_CompactClassificationTree_Com(
        c_weak_learner_CutPredictorInde, c_weak_learner_Children,
        c_weak_learner_CutPoint, c_weak_learner_NanCutPoints, e_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        c_weak_learner_ClassProbability);
    b = isCached[2];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 2];
    }
    c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          c_weak_learner_CutPredictorInde,
                          c_weak_learner_Children, c_weak_learner_CutPoint,
                          c_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, c_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[3]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    f_CompactClassificationTree_Com(
        d_weak_learner_CutPredictorInde, d_weak_learner_Children,
        d_weak_learner_CutPoint, d_weak_learner_NanCutPoints, f_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        d_weak_learner_ClassProbability);
    b = isCached[3];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 3];
    }
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[4]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    g_CompactClassificationTree_Com(
        e_weak_learner_CutPredictorInde, e_weak_learner_Children,
        e_weak_learner_CutPoint, e_weak_learner_NanCutPoints, g_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        e_weak_learner_ClassProbability);
    b = isCached[4];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 4];
    }
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[5]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    h_CompactClassificationTree_Com(
        e_weak_learner_CutPredictorInde, e_weak_learner_Children,
        e_weak_learner_CutPoint, e_weak_learner_NanCutPoints, g_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        e_weak_learner_ClassProbability);
    b = isCached[5];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 5];
    }
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[6]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    i_CompactClassificationTree_Com(
        f_weak_learner_CutPredictorInde, f_weak_learner_Children,
        f_weak_learner_CutPoint, f_weak_learner_NanCutPoints, h_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        f_weak_learner_ClassProbability);
    b = isCached[6];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 6];
    }
    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutPredictorInde,
                          f_weak_learner_Children, f_weak_learner_CutPoint,
                          f_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, f_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[7]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    j_CompactClassificationTree_Com(
        b_weak_learner_CutPredictorInde, b_weak_learner_Children,
        b_weak_learner_CutPoint, b_weak_learner_NanCutPoints, d_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        b_weak_learner_ClassProbability);
    b = isCached[7];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 7];
    }
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[8]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    k_CompactClassificationTree_Com(
        e_weak_learner_CutPredictorInde, e_weak_learner_Children,
        e_weak_learner_CutPoint, e_weak_learner_NanCutPoints, g_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        e_weak_learner_ClassProbability);
    b = isCached[8];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 8];
    }
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[9]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    l_CompactClassificationTree_Com(
        g_weak_learner_CutPredictorInde, g_weak_learner_Children,
        g_weak_learner_CutPoint, g_weak_learner_NanCutPoints, i_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        g_weak_learner_ClassProbability);
    b = isCached[9];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 9];
    }
    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          g_weak_learner_CutPredictorInde,
                          g_weak_learner_Children, g_weak_learner_CutPoint,
                          g_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, g_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[10]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    m_CompactClassificationTree_Com(
        e_weak_learner_CutPredictorInde, e_weak_learner_Children,
        e_weak_learner_CutPoint, e_weak_learner_NanCutPoints, g_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        e_weak_learner_ClassProbability);
    b = isCached[10];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 10];
    }
    e_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          e_weak_learner_CutPredictorInde,
                          e_weak_learner_Children, e_weak_learner_CutPoint,
                          e_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, e_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[11]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    n_CompactClassificationTree_Com(
        h_weak_learner_CutPredictorInde, h_weak_learner_Children,
        h_weak_learner_CutPoint, h_weak_learner_NanCutPoints, j_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        h_weak_learner_ClassProbability);
    b = isCached[11];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 11];
    }
    h_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          h_weak_learner_CutPredictorInde,
                          h_weak_learner_Children, h_weak_learner_CutPoint,
                          h_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, h_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[12]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    o_CompactClassificationTree_Com(
        c_weak_learner_CutPredictorInde, c_weak_learner_Children,
        c_weak_learner_CutPoint, c_weak_learner_NanCutPoints, e_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        c_weak_learner_ClassProbability);
    b = isCached[12];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 12];
    }
    c_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          c_weak_learner_CutPredictorInde,
                          c_weak_learner_Children, c_weak_learner_CutPoint,
                          c_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, c_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[13]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    p_CompactClassificationTree_Com(
        i_weak_learner_CutPredictorInde, i_weak_learner_Children,
        i_weak_learner_CutPoint, i_weak_learner_NanCutPoints, k_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        i_weak_learner_ClassProbability);
    b = isCached[13];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 13];
    }
    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          i_weak_learner_CutPredictorInde,
                          i_weak_learner_Children, i_weak_learner_CutPoint,
                          i_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, i_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[14]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    q_CompactClassificationTree_Com(
        g_weak_learner_CutPredictorInde, g_weak_learner_Children,
        g_weak_learner_CutPoint, g_weak_learner_NanCutPoints, i_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        g_weak_learner_ClassProbability);
    b = isCached[14];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 14];
    }
    g_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          g_weak_learner_CutPredictorInde,
                          g_weak_learner_Children, g_weak_learner_CutPoint,
                          g_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, g_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[15]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    r_CompactClassificationTree_Com(
        j_weak_learner_CutPredictorInde, j_weak_learner_Children,
        j_weak_learner_CutPoint, j_weak_learner_NanCutPoints, l_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        j_weak_learner_ClassProbability);
    b = isCached[15];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 15];
    }
    j_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          j_weak_learner_CutPredictorInde,
                          j_weak_learner_Children, j_weak_learner_CutPoint,
                          j_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, j_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[16]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    s_CompactClassificationTree_Com(
        weak_learner_CutPredictorIndex, weak_learner_Children,
        weak_learner_CutPoint, weak_learner_NanCutPoints, expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        weak_learner_ClassProbability);
    b = isCached[16];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 16];
    }
    predictOneWithCache(
        X, cachedScore, cachedWeights, combiner, weak_learner_CutPredictorIndex,
        weak_learner_Children, weak_learner_CutPoint, weak_learner_NanCutPoints,
        weak_learner_ClassNames, weak_learner_ClassNamesLength,
        weak_learner_Prior, weak_learner_Cost, weak_learner_ClassProbability,
        &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[17]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    t_CompactClassificationTree_Com(
        f_weak_learner_CutPredictorInde, f_weak_learner_Children,
        f_weak_learner_CutPoint, f_weak_learner_NanCutPoints, h_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        f_weak_learner_ClassProbability);
    b = isCached[17];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 17];
    }
    f_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          f_weak_learner_CutPredictorInde,
                          f_weak_learner_Children, f_weak_learner_CutPoint,
                          f_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, f_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[18]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    u_CompactClassificationTree_Com(
        k_weak_learner_CutPredictorInde, k_weak_learner_Children,
        k_weak_learner_CutPoint, k_weak_learner_NanCutPoints, m_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        k_weak_learner_ClassProbability);
    b = isCached[18];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 18];
    }
    k_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          k_weak_learner_CutPredictorInde,
                          k_weak_learner_Children, k_weak_learner_CutPoint,
                          k_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, k_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[19]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    v_CompactClassificationTree_Com(
        l_weak_learner_CutPredictorInde, l_weak_learner_Children,
        l_weak_learner_CutPoint, l_weak_learner_NanCutPoints, n_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        l_weak_learner_ClassProbability);
    b = isCached[19];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 19];
    }
    l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          l_weak_learner_CutPredictorInde,
                          l_weak_learner_Children, l_weak_learner_CutPoint,
                          l_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, l_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[20]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    w_CompactClassificationTree_Com(
        b_weak_learner_CutPredictorInde, b_weak_learner_Children,
        b_weak_learner_CutPoint, b_weak_learner_NanCutPoints, d_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        b_weak_learner_ClassProbability);
    b = isCached[20];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 20];
    }
    b_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          b_weak_learner_CutPredictorInde,
                          b_weak_learner_Children, b_weak_learner_CutPoint,
                          b_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, b_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[21]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    x_CompactClassificationTree_Com(
        m_weak_learner_CutPredictorInde, m_weak_learner_Children,
        m_weak_learner_CutPoint, m_weak_learner_NanCutPoints, o_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        m_weak_learner_ClassProbability);
    b = isCached[21];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 21];
    }
    m_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          m_weak_learner_CutPredictorInde,
                          m_weak_learner_Children, m_weak_learner_CutPoint,
                          m_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, m_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[22]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    y_CompactClassificationTree_Com(
        d_weak_learner_CutPredictorInde, d_weak_learner_Children,
        d_weak_learner_CutPoint, d_weak_learner_NanCutPoints, f_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        d_weak_learner_ClassProbability);
    b = isCached[22];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 22];
    }
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[23]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    ab_CompactClassificationTree_Co(
        d_weak_learner_CutPredictorInde, d_weak_learner_Children,
        d_weak_learner_CutPoint, d_weak_learner_NanCutPoints, f_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        d_weak_learner_ClassProbability);
    b = isCached[23];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 23];
    }
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[24]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    bb_CompactClassificationTree_Co(
        n_weak_learner_CutPredictorInde, n_weak_learner_Children,
        n_weak_learner_CutPoint, n_weak_learner_NanCutPoints, p_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        n_weak_learner_ClassProbability);
    b = isCached[24];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 24];
    }
    n_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          n_weak_learner_CutPredictorInde,
                          n_weak_learner_Children, n_weak_learner_CutPoint,
                          n_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, n_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[25]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    cb_CompactClassificationTree_Co(
        l_weak_learner_CutPredictorInde, l_weak_learner_Children,
        l_weak_learner_CutPoint, l_weak_learner_NanCutPoints, n_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        l_weak_learner_ClassProbability);
    b = isCached[25];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 25];
    }
    l_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          l_weak_learner_CutPredictorInde,
                          l_weak_learner_Children, l_weak_learner_CutPoint,
                          l_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, l_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[26]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    db_CompactClassificationTree_Co(
        i_weak_learner_CutPredictorInde, i_weak_learner_Children,
        i_weak_learner_CutPoint, i_weak_learner_NanCutPoints, k_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        i_weak_learner_ClassProbability);
    b = isCached[26];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 26];
    }
    i_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          i_weak_learner_CutPredictorInde,
                          i_weak_learner_Children, i_weak_learner_CutPoint,
                          i_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, i_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[27]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    eb_CompactClassificationTree_Co(
        d_weak_learner_CutPredictorInde, d_weak_learner_Children,
        d_weak_learner_CutPoint, d_weak_learner_NanCutPoints, f_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        d_weak_learner_ClassProbability);
    b = isCached[27];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 27];
    }
    d_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          d_weak_learner_CutPredictorInde,
                          d_weak_learner_Children, d_weak_learner_CutPoint,
                          d_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, d_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[28]) {
    if (firstCache) {
      initCache = true;
      firstCache = false;
    } else {
      initCache = false;
    }
    fb_CompactClassificationTree_Co(
        p_weak_learner_CutPredictorInde, p_weak_learner_Children,
        p_weak_learner_CutPoint, p_weak_learner_NanCutPoints, r_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        p_weak_learner_ClassProbability);
    b = isCached[28];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 28];
    }
    o_predictOneWithCache(X, cachedScore, cachedWeights, combiner,
                          p_weak_learner_CutPredictorInde,
                          p_weak_learner_Children, p_weak_learner_CutPoint,
                          p_weak_learner_NanCutPoints, weak_learner_ClassNames,
                          weak_learner_ClassNamesLength, weak_learner_Prior,
                          weak_learner_Cost, p_weak_learner_ClassProbability,
                          &b, classNames, b_useObsForLearner, initCache, score);
  }
  if (learners[29]) {
    gb_CompactClassificationTree_Co(
        o_weak_learner_CutPredictorInde, o_weak_learner_Children,
        o_weak_learner_CutPoint, o_weak_learner_NanCutPoints, q_expl_temp,
        weak_learner_ClassNames, weak_learner_ClassNamesLength, &b_expl_temp,
        weak_learner_Prior, c_expl_temp, weak_learner_Cost,
        o_weak_learner_ClassProbability);
    b = isCached[29];
    loop_ub = useObsForLearner->size[0];
    i = b_useObsForLearner->size[0];
    b_useObsForLearner->size[0] = useObsForLearner->size[0];
    emxEnsureCapacity_boolean_T(b_useObsForLearner, i);
    for (i = 0; i < loop_ub; i++) {
      b_useObsForLearner->data[i] =
          useObsForLearner->data[i + useObsForLearner->size[0] * 29];
    }
    p_predictOneWithCache(
        X, cachedScore, cachedWeights, combiner,
        o_weak_learner_CutPredictorInde, o_weak_learner_Children,
        o_weak_learner_CutPoint, o_weak_learner_NanCutPoints,
        weak_learner_ClassNames, weak_learner_ClassNamesLength,
        weak_learner_Prior, weak_learner_Cost, o_weak_learner_ClassProbability,
        &b, classNames, b_useObsForLearner, firstCache, score);
  }
  emxFree_boolean_T(&b_useObsForLearner);
  emxFree_real_T(&cachedWeights);
  emxFree_real_T(&cachedScore);
}

/*
 * File trailer for aggregatePredict.c
 *
 * [EOF]
 */
