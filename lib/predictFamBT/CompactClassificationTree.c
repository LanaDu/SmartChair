/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

/* Include Files */
#include "CompactClassificationTree.h"
#include "predictFamBT_data.h"
#include "predictFamBT_emxutil.h"
#include "predictFamBT_internal_types.h"
#include "predictFamBT_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_cell_wrap_10
#define typedef_cell_wrap_10

typedef struct {
  char f1[7];
} cell_wrap_10;

#endif                                 /* typedef_cell_wrap_10 */

/* Function Definitions */
/*
 * Arguments    : double obj_CutPredictorIndex[63]
 *                double obj_Children[126]
 *                double obj_CutPoint[63]
 *                boolean_T obj_NanCutPoints[63]
 *                boolean_T obj_InfCutPoints[63]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[126]
 * Return Type  : void
 */
void ab_CompactClassificationTree_Co(double obj_CutPredictorIndex[63], double
  obj_Children[126], double obj_CutPoint[63], boolean_T obj_NanCutPoints[63],
  boolean_T obj_InfCutPoints[63], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[126])
{
  static const double dv1[126] = { 0.578700078308538, 0.97670807453416142,
    0.17377567140600317, 0.99364406779661019, 0.93023255813953487,
    0.091085271317829467, 0.53846153846153844, 1.0, 0.98654708520179368,
    0.78124999999999989, 0.9642857142857143, 0.72340425531914887,
    0.027718550106609823, 0.97058823529411764, 0.36144578313253017,
    0.99539170506912444, 0.66666666666666674, 1.0, 0.0, 1.0, 0.8275862068965516,
    0.84999999999999987, 0.0, 0.14130434782608703, 0.0, 1.0, 0.66666666666666674,
    1.0, 0.15873015873015883, 0.95652173913043481, 1.0, 0.0, 1.0,
    0.888888888888889, 0.0, 1.0, 0.14285714285714285, 0.38461538461538469,
    0.045454545454545484, 1.0, 0.0, 0.0, 0.90909090909090917, 1.0,
    0.79999999999999993, 0.5714285714285714, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.01562500000000001, 0.0, 1.0, 0.0, 1.0, 0.79999999999999993, 0.0, 1.0, 0.0,
    0.0, 1.0, 0.421299921691462, 0.023291925465838519, 0.82622432859399686,
    0.0063559322033898344, 0.069767441860465157, 0.9089147286821706,
    0.46153846153846156, 0.0, 0.013452914798206286, 0.21875000000000008,
    0.03571428571428574, 0.27659574468085113, 0.97228144989339016,
    0.02941176470588237, 0.63855421686746983, 0.0046082949308755795,
    0.33333333333333337, 0.0, 1.0, 0.0, 0.17241379310344834, 0.15000000000000008,
    1.0, 0.858695652173913, 1.0, 0.0, 0.33333333333333337, 0.0,
    0.84126984126984117, 0.043478260869565237, 0.0, 1.0, 0.0,
    0.11111111111111116, 1.0, 0.0, 0.8571428571428571, 0.61538461538461531,
    0.95454545454545459, 0.0, 1.0, 1.0, 0.090909090909090912, 0.0,
    0.19999999999999998, 0.42857142857142855, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.984375, 1.0, 0.0, 1.0, 0.0, 0.19999999999999998, 1.0, 0.0, 1.0, 1.0, 0.0 };

  static const double dv[63] = { 0.055, 1.2149999999999999, 1.54, 0.885, 1.295,
    0.365, 0.66, 0.0, 0.27, 0.285, 1.025, 0.39, 0.015, 0.195, 0.055, 0.925,
    1.3399999999999999, 0.0, 0.0, 0.0, 0.03, 1.245, 0.0, 1.07, 0.0, 0.0,
    0.33499999999999996, 0.0, 2.08, 0.9, 0.0, 0.0, 0.0, 1.5350000000000001, 0.0,
    0.0, 0.065, 1.0350000000000001, 0.32, 0.0, 0.0, 0.0, 1.865, 0.0, 1.56, 1.68,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0, 0.0, 0.0, 0.0, 1.0350000000000001,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[126] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 0, 0, 0, 0, 0, 0, 34, 35, 36, 37, 0, 0, 38, 39, 0, 0, 0, 0, 40, 41,
    0, 0, 42, 43, 44, 45, 0, 0, 0, 0, 0, 0, 46, 47, 0, 0, 0, 0, 48, 49, 50, 51,
    52, 53, 0, 0, 0, 0, 0, 0, 54, 55, 0, 0, 56, 57, 58, 59, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 62, 63, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0 };

  static const signed char iv[63] = { 2, 7, 8, 7, 10, 11, 13, 0, 3, 3, 13, 3, 3,
    2, 1, 8, 5, 0, 0, 0, 3, 5, 0, 7, 0, 0, 3, 0, 10, 8, 0, 0, 0, 7, 0, 0, 3, 10,
    13, 0, 0, 0, 8, 0, 10, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0
  };

  static const boolean_T bv[63] = { false, false, false, false, false, false,
    false, true, false, false, false, false, false, false, false, false, false,
    true, true, true, false, false, true, false, true, true, false, true, false,
    false, true, true, true, false, true, true, false, false, false, true, true,
    true, false, true, false, false, true, true, true, true, true, true, false,
    true, true, true, true, false, true, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 63U * sizeof(double));
  for (i = 0; i < 63; i++) {
    obj_NanCutPoints[i] = bv[i];
  }

  memcpy(&obj_ClassProbability[0], &dv1[0], 126U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 63; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 126; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 63; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.57870007830853565;
  obj_Prior[1] = 0.42129992169146435;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[59]
 *                double obj_Children[118]
 *                double obj_CutPoint[59]
 *                boolean_T obj_NanCutPoints[59]
 *                boolean_T obj_InfCutPoints[59]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[118]
 * Return Type  : void
 */
void bb_CompactClassificationTree_Co(double obj_CutPredictorIndex[59], double
  obj_Children[118], double obj_CutPoint[59], boolean_T obj_NanCutPoints[59],
  boolean_T obj_InfCutPoints[59], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[118])
{
  static const double dv1[118] = { 0.57478465152701874, 0.98553054662379425,
    0.18473282442748093, 0.99784482758620685, 0.94936708860759489,
    0.82978723404255306, 0.13486842105263158, 0.99408284023668636, 1.0,
    0.98039215686274506, 0.0, 0.70370370370370361, 1.0, 0.10847457627118644, 1.0,
    0.99122807017543857, 1.0, 0.99319727891156462, 0.66666666666666674,
    0.33333333333333331, 1.0, 0.76666666666666661, 0.03396226415094341, 1.0, 0.0,
    1.0, 0.98333333333333328, 0.0, 1.0, 0.79999999999999993, 0.0,
    0.93877551020408168, 0.0, 0.3793103448275863, 0.013972055888223565,
    0.962962962962963, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.1428571428571429,
    0.006072874493927129, 0.5714285714285714, 0.83333333333333326, 1.0,
    0.052631578947368439, 1.0, 0.37499999999999994, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 1.0, 0.0, 0.42521534847298137, 0.014469453376205801,
    0.81526717557251915, 0.0021551724137931047, 0.050632911392405104,
    0.17021276595744692, 0.86513157894736847, 0.0059171597633136128, 0.0,
    0.019607843137254916, 1.0, 0.29629629629629639, 0.0, 0.8915254237288136, 0.0,
    0.00877192982456141, 0.0, 0.0068027210884353791, 0.33333333333333337,
    0.66666666666666674, 0.0, 0.23333333333333342, 0.96603773584905661, 0.0, 1.0,
    0.0, 0.016666666666666677, 1.0, 0.0, 0.19999999999999998, 1.0,
    0.0612244897959184, 1.0, 0.6206896551724137, 0.98602794411177641,
    0.037037037037037056, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.85714285714285721,
    0.99392712550607287, 0.42857142857142855, 0.16666666666666666, 0.0,
    0.94736842105263164, 0.0, 0.625, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0
  };

  static const double dv[59] = { 0.055, 1.2149999999999999, 0.045, 0.53,
    0.46499999999999997, 1.0550000000000002, 1.8450000000000002, 0.015, 0.0,
    0.02, 0.0, 1.22, 0.0, 0.345, 0.0, 0.51, 0.0, 0.015, 0.205, 0.79, 0.0,
    0.33999999999999997, 0.075000000000000011, 0.0, 0.0, 0.0, 0.015, 0.0, 0.0,
    0.875, 0.0, 1.155, 0.0, 0.865, 2.085, 1.49, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.9049999999999998, 0.005, 0.19, 1.505, 0.0, 0.12000000000000001, 0.0, 0.625,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[118] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 18, 19, 0, 0, 20, 21, 0, 0, 22, 23, 0, 0, 24, 25, 0, 0,
    26, 27, 28, 29, 30, 31, 0, 0, 32, 33, 34, 35, 0, 0, 0, 0, 0, 0, 36, 37, 0, 0,
    0, 0, 38, 39, 0, 0, 40, 41, 0, 0, 42, 43, 44, 45, 46, 47, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 48, 49, 50, 51, 52, 53, 54, 55, 0, 0, 56, 57, 0, 0, 58, 59,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[59] = { 2, 7, 1, 13, 3, 13, 5, 2, 0, 3, 0, 8, 0,
    13, 0, 13, 0, 1, 3, 11, 0, 11, 2, 0, 0, 0, 2, 0, 0, 7, 0, 10, 0, 5, 10, 5, 0,
    0, 0, 0, 0, 0, 10, 8, 1, 7, 0, 8, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const boolean_T bv[59] = { false, false, false, false, false, false,
    false, false, true, false, true, false, true, false, true, false, true,
    false, false, false, true, false, false, true, true, true, false, true, true,
    false, true, false, true, false, false, false, true, true, true, true, true,
    true, false, false, false, false, true, false, true, false, true, true, true,
    true, true, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 59U * sizeof(double));
  for (i = 0; i < 59; i++) {
    obj_NanCutPoints[i] = bv[i];
  }

  memcpy(&obj_ClassProbability[0], &dv1[0], 118U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 59; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 118; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 59; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.57478465152701641;
  obj_Prior[1] = 0.42521534847298353;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[93]
 *                double obj_Children[186]
 *                double obj_CutPoint[93]
 *                boolean_T obj_NanCutPoints[93]
 *                boolean_T obj_InfCutPoints[93]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[186]
 * Return Type  : void
 */
void c_CompactClassificationTree_Com(double obj_CutPredictorIndex[93], double
  obj_Children[186], double obj_CutPoint[93], boolean_T obj_NanCutPoints[93],
  boolean_T obj_InfCutPoints[93], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[186])
{
  static const double dv1[186] = { 0.57791699295223409, 0.9453125,
    0.48579823702252689, 0.99156118143459915, 0.368421052631579,
    0.79456706281833622, 0.064814814814814825, 1.0, 0.97058823529411764, 1.0,
    0.0, 0.92549019607843142, 0.6946107784431137, 0.79999999999999993,
    0.019656019656019673, 0.71428571428571419, 1.0, 0.83333333333333326,
    0.96174863387978138, 0.86986301369863006, 0.55851063829787229, 1.0,
    0.16666666666666666, 0.35294117647058826, 0.0051282051282051317, 1.0, 0.0,
    0.92307692307692313, 0.59999999999999987, 1.0, 0.90666666666666662, 1.0,
    0.29629629629629639, 0.93181818181818188, 0.44444444444444442, 0.0, 1.0, 0.0,
    0.8571428571428571, 0.0, 1.0, 1.0, 0.0, 0.66666666666666663, 0.0,
    0.94444444444444442, 0.0, 0.17391304347826092, 1.0, 1.0, 0.66666666666666674,
    0.93181818181818188, 0.23000000000000004, 1.0, 0.5, 1.0, 0.33333333333333331,
    0.0, 0.97142857142857142, 1.0, 0.050000000000000017, 1.0, 0.0, 1.0,
    0.7272727272727274, 0.13095238095238104, 0.74999999999999989, 1.0, 0.0, 1.0,
    0.0, 0.98181818181818181, 0.93333333333333335, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.026666666666666686, 0.0, 0.92307692307692313, 1.0, 0.74999999999999989,
    1.0, 0.66666666666666674, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.42208300704776586, 0.054687500000000028, 0.514201762977473,
    0.00843881856540085, 0.631578947368421, 0.20543293718166383,
    0.93518518518518523, 0.0, 0.029411764705882373, 0.0, 1.0,
    0.074509803921568654, 0.30538922155688619, 0.20000000000000007,
    0.98034398034398029, 0.2857142857142857, 0.0, 0.16666666666666674,
    0.038251366120218608, 0.13013698630136988, 0.44148936170212766, 0.0,
    0.83333333333333326, 0.6470588235294118, 0.99487179487179489, 0.0, 1.0,
    0.076923076923076969, 0.4, 0.0, 0.0933333333333334, 0.0, 0.70370370370370361,
    0.068181818181818218, 0.55555555555555558, 1.0, 0.0, 1.0,
    0.14285714285714285, 1.0, 0.0, 0.0, 1.0, 0.33333333333333337, 1.0,
    0.055555555555555594, 1.0, 0.826086956521739, 0.0, 0.0, 0.33333333333333331,
    0.068181818181818218, 0.76999999999999991, 0.0, 0.5, 0.0,
    0.66666666666666674, 1.0, 0.028571428571428591, 0.0, 0.95000000000000007,
    0.0, 1.0, 0.0, 0.27272727272727271, 0.869047619047619, 0.25, 0.0, 1.0, 0.0,
    1.0, 0.018181818181818195, 0.06666666666666668, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.97333333333333338, 1.0, 0.076923076923076941, 0.0, 0.25, 0.0,
    0.33333333333333337, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0 };

  static const double dv[93] = { 0.795, 0.025, 0.005, 0.525, 0.09, 1.145,
    0.33999999999999997, 0.0, 0.54, 0.0, 0.0, 1.09, 1.5950000000000002, 0.39,
    0.055, 0.69500000000000006, 0.0, 0.92999999999999994, 1.185, 0.075, 0.745,
    0.0, 1.35, 1.525, 2.085, 0.0, 0.0, 0.075000000000000011, 0.78, 0.0,
    0.33499999999999996, 0.0, 1.4, 0.095, 0.045, 0.0, 0.0, 0.0, 1.675, 0.0, 0.0,
    0.0, 0.0, 0.87, 0.0, 1.1949999999999998, 0.0, 0.165, 0.0, 0.0, 0.19, 1.645,
    1.7850000000000001, 0.0, 0.84, 0.0, 0.030000000000000002, 0.0, 0.865, 0.0,
    0.845, 0.0, 0.0, 0.0, 1.5350000000000001, 0.084999999999999992,
    2.0549999999999997, 0.0, 0.0, 0.0, 0.0, 0.15000000000000002, 1.435, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.855, 0.0, 0.81, 0.0, 0.22, 0.0, 1.4449999999999998, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[186] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0,
    0, 28, 29, 30, 31, 32, 33, 34, 35, 0, 0, 36, 37, 38, 39, 40, 41, 0, 0, 0, 0,
    42, 43, 44, 45, 0, 0, 46, 47, 0, 0, 48, 49, 50, 51, 52, 53, 0, 0, 0, 0, 0, 0,
    54, 55, 0, 0, 0, 0, 0, 0, 0, 0, 56, 57, 0, 0, 58, 59, 0, 0, 60, 61, 0, 0, 0,
    0, 62, 63, 64, 65, 66, 67, 0, 0, 68, 69, 0, 0, 70, 71, 0, 0, 72, 73, 0, 0,
    74, 75, 0, 0, 0, 0, 0, 0, 76, 77, 78, 79, 80, 81, 0, 0, 0, 0, 0, 0, 0, 0, 82,
    83, 84, 85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 86, 87, 0, 0, 88, 89, 0, 0, 90, 91,
    0, 0, 92, 93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[93] = { 5, 3, 3, 5, 1, 7, 11, 0, 5, 0, 0, 10, 10,
    3, 2, 11, 0, 10, 5, 1, 11, 0, 10, 10, 10, 0, 0, 2, 13, 0, 2, 0, 8, 2, 2, 0,
    0, 0, 7, 0, 0, 0, 0, 7, 0, 5, 0, 11, 0, 0, 1, 8, 5, 0, 13, 0, 2, 0, 13, 0,
    11, 0, 0, 0, 5, 1, 10, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 8, 0, 13, 0, 1, 0,
    10, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const boolean_T bv[93] = { false, false, false, false, false, false,
    false, true, false, true, true, false, false, false, false, false, true,
    false, false, false, false, true, false, false, false, true, true, false,
    false, true, false, true, false, false, false, true, true, true, false, true,
    true, true, true, false, true, false, true, false, true, true, false, false,
    false, true, false, true, false, true, false, true, false, true, true, true,
    false, false, false, true, true, true, true, false, false, true, true, true,
    true, true, false, true, false, true, false, true, false, true, true, true,
    true, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 93U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 93U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 186U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 93; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 186; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 93U * sizeof(boolean_T));
  obj_Prior[0] = 0.57791699295223176;
  obj_Prior[1] = 0.42208300704776819;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[93]
 *                const double obj_Children[186]
 *                const double obj_CutPoint[93]
 *                const boolean_T obj_NanCutPoints[93]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[186]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void c_CompactClassificationTree_pre(const double obj_CutPredictorIndex[93],
  const double obj_Children[186], const double obj_CutPoint[93], const boolean_T
  obj_NanCutPoints[93], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[186], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 93 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[71]
 *                double obj_Children[142]
 *                double obj_CutPoint[71]
 *                boolean_T obj_NanCutPoints[71]
 *                boolean_T obj_InfCutPoints[71]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[142]
 * Return Type  : void
 */
void cb_CompactClassificationTree_Co(double obj_CutPredictorIndex[71], double
  obj_Children[142], double obj_CutPoint[71], boolean_T obj_NanCutPoints[71],
  boolean_T obj_InfCutPoints[71], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[142])
{
  static const double dv1[142] = { 0.562255285826157, 0.9685430463576159,
    0.1976225854383358, 0.98404255319148937, 0.74999999999999989,
    0.15756630265210608, 1.0, 0.98579040852575484, 0.0, 1.0, 0.0,
    0.37327188940092165, 0.047169811320754727, 0.99702380952380953,
    0.96916299559471364, 0.81632653061224481, 0.24404761904761904,
    0.81818181818181812, 0.0049751243781094561, 1.0, 0.98245614035087725, 0.8,
    0.98113207547169812, 0.5714285714285714, 0.91428571428571426,
    0.72549019607843135, 0.034188034188034212, 1.0, 0.0, 0.0, 1.0, 1.0,
    0.88888888888888884, 0.0, 1.0, 0.985781990521327, 0.0, 0.0, 1.0, 1.0, 0.25,
    0.1818181818181818, 0.87499999999999989, 0.017391304347826098, 1.0, 0.0, 1.0,
    1.0, 0.93877551020408168, 1.0, 0.0, 0.0, 1.0, 1.0, 0.6428571428571429,
    0.66666666666666674, 0.0, 0.86956521739130443, 1.0, 0.0, 1.0, 1.0, 0.0,
    0.90909090909090917, 0.0, 0.95238095238095244, 0.0, 0.66666666666666674, 1.0,
    1.0, 0.0, 0.43774471417384309, 0.031456953642384114, 0.80237741456166423,
    0.015957446808510651, 0.25000000000000011, 0.842433697347894, 0.0,
    0.014209591474245128, 1.0, 0.0, 1.0, 0.62672811059907829,
    0.95283018867924529, 0.0029761904761904782, 0.030837004405286368,
    0.18367346938775522, 0.75595238095238093, 0.18181818181818185,
    0.99502487562189057, 0.0, 0.01754385964912282, 0.2, 0.0188679245283019,
    0.42857142857142855, 0.085714285714285757, 0.27450980392156871,
    0.96581196581196582, 0.0, 1.0, 1.0, 0.0, 0.0, 0.11111111111111109, 1.0, 0.0,
    0.014218009478672994, 1.0, 1.0, 0.0, 0.0, 0.74999999999999989,
    0.81818181818181812, 0.12500000000000006, 0.9826086956521739, 0.0, 1.0, 0.0,
    0.0, 0.0612244897959184, 0.0, 1.0, 1.0, 0.0, 0.0, 0.3571428571428571,
    0.33333333333333337, 1.0, 0.1304347826086957, 0.0, 1.0, 0.0, 0.0, 1.0,
    0.090909090909090953, 1.0, 0.047619047619047637, 1.0, 0.33333333333333337,
    0.0, 0.0, 1.0 };

  static const double dv[71] = { 0.055, 0.195, 1.835, 0.355, 1.22, 0.015, 0.0,
    0.895, 0.0, 0.0, 0.0, 0.43, 0.23, 0.035, 0.535, 0.095, 0.125, 0.175, 2.08,
    0.0, 1.17, 1.015, 0.04, 1.15, 1.065, 1.055, 1.85, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.24, 0.0, 0.0, 0.015, 0.0, 0.0, 0.0, 0.0, 0.195, 1.145, 1.1949999999999998,
    0.87, 0.0, 0.0, 0.0, 0.0, 1.5, 0.0, 0.0, 0.0, 0.0, 0.0, 1.06, 0.14, 0.0,
    1.585, 0.0, 0.0, 0.0, 0.0, 0.0, 0.15, 0.0, 0.005, 0.0, 1.2999999999999998,
    0.0, 0.0, 0.0 };

  static const signed char iv1[142] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    0, 0, 14, 15, 0, 0, 0, 0, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 0, 0, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
    45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 47, 0, 0, 0, 0, 48, 49, 0, 0, 0, 0, 0,
    0, 0, 0, 50, 51, 52, 53, 54, 55, 56, 57, 0, 0, 0, 0, 0, 0, 0, 0, 58, 59, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 61, 62, 63, 0, 0, 64, 65, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 66, 67, 0, 0, 68, 69, 0, 0, 70, 71, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[71] = { 2, 1, 8, 3, 8, 3, 0, 11, 0, 0, 0, 13, 13,
    1, 13, 1, 1, 2, 10, 0, 5, 11, 2, 10, 8, 10, 5, 0, 0, 0, 0, 0, 5, 0, 0, 1, 0,
    0, 0, 0, 2, 7, 7, 7, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 13, 6, 0, 8, 0, 0, 0, 0,
    0, 3, 0, 2, 0, 10, 0, 0, 0 };

  static const boolean_T bv[71] = { false, false, false, false, false, false,
    true, false, true, true, true, false, false, false, false, false, false,
    false, false, true, false, false, false, false, false, false, false, true,
    true, true, true, true, false, true, true, false, true, true, true, true,
    false, false, false, false, true, true, true, true, false, true, true, true,
    true, true, false, false, true, false, true, true, true, true, true, false,
    true, false, true, false, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 71U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 71U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 142U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 71; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 142; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 71U * sizeof(boolean_T));
  obj_Prior[0] = 0.562255285826155;
  obj_Prior[1] = 0.437744714173845;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[77]
 *                double obj_Children[154]
 *                double obj_CutPoint[77]
 *                boolean_T obj_NanCutPoints[77]
 *                boolean_T obj_InfCutPoints[77]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[154]
 * Return Type  : void
 */
void d_CompactClassificationTree_Com(double obj_CutPredictorIndex[77], double
  obj_Children[154], double obj_CutPoint[77], boolean_T obj_NanCutPoints[77],
  boolean_T obj_InfCutPoints[77], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[154])
{
  static const double dv1[154] = { 0.54815974941268752, 0.97350993377483441,
    0.16641901931649333, 0.98657718120805371, 0.0, 0.77999999999999992,
    0.11717495987158909, 0.99143835616438358, 0.75, 0.15384615384615385, 1.0,
    0.79032258064516125, 0.042780748663101616, 1.0, 0.984423676012461, 0.0,
    0.90000000000000013, 1.0, 0.0, 0.87272727272727257, 0.14285714285714285,
    0.027372262773722639, 0.69230769230769229, 0.8571428571428571,
    0.98726114649681529, 1.0, 0.74999999999999989, 0.9555555555555556, 0.5, 1.0,
    0.0, 0.16176470588235303, 0.0083333333333333384, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.96992481203007519, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.5625,
    0.038461538461538484, 0.33333333333333337, 0.0062893081761006327,
    0.98473282442748089, 0.0, 1.0, 0.12499999999999999, 1.0, 0.0, 1.0, 0.0,
    0.0042016806722689109, 1.0, 0.97701149425287359, 1.0, 0.0, 1.0, 0.5,
    0.0021097046413502125, 0.0, 0.98837209302325579, 1.0, 0.0, 0.0,
    0.01562500000000001, 0.8571428571428571, 1.0, 1.0, 0.0, 1.0, 0.0,
    0.45184025058731248, 0.026490066225165573, 0.83358098068350672,
    0.013422818791946321, 1.0, 0.22000000000000011, 0.8828250401284109,
    0.0085616438356164448, 0.24999999999999994, 0.84615384615384615, 0.0,
    0.2096774193548388, 0.95721925133689845, 0.0, 0.015576323987538951, 1.0,
    0.099999999999999992, 0.0, 1.0, 0.12727272727272734, 0.8571428571428571,
    0.97262773722627738, 0.30769230769230765, 0.14285714285714285,
    0.012738853503184723, 0.0, 0.25, 0.044444444444444474, 0.5, 0.0, 1.0,
    0.838235294117647, 0.9916666666666667, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.030075187969924835, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.4375,
    0.96153846153846156, 0.66666666666666674, 0.99371069182389937,
    0.015267175572519094, 1.0, 0.0, 0.875, 0.0, 1.0, 0.0, 1.0,
    0.99579831932773111, 0.0, 0.02298850574712645, 0.0, 1.0, 0.0, 0.5,
    0.99789029535864981, 1.0, 0.011627906976744193, 0.0, 1.0, 1.0, 0.984375,
    0.14285714285714285, 0.0, 0.0, 1.0, 0.0, 1.0 };

  static const double dv[77] = { 0.055, 0.375, 0.045, 0.035, 0.0, 1.22, 0.345,
    0.755, 0.05, 0.47, 0.0, 0.235, 2.085, 0.0, 0.765, 0.0, 0.635, 0.0, 0.0,
    0.245, 0.58500000000000008, 0.095, 1.835, 1.525, 1.435, 0.0, 1.795, 0.37,
    1.195, 0.0, 0.0, 0.035, 0.15, 0.0, 0.0, 0.0, 0.0, 0.0, 0.045, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.875, 0.33, 0.095, 1.9500000000000002, 0.015, 0.0, 0.0, 1.64,
    0.0, 0.0, 0.0, 0.0, 0.18, 0.0, 0.605, 0.0, 0.0, 0.0, 0.01,
    1.5150000000000001, 0.0, 0.905, 0.0, 0.0, 0.0, 1.56, 1.1, 0.0, 0.0, 0.0, 0.0,
    0.0 };

  static const signed char iv1[154] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 0, 0, 24, 25, 0, 0, 26, 27,
    0, 0, 0, 0, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 0, 0, 40, 41, 42,
    43, 44, 45, 0, 0, 0, 0, 46, 47, 48, 49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 51,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61,
    0, 0, 0, 0, 62, 63, 0, 0, 0, 0, 0, 0, 0, 0, 64, 65, 0, 0, 66, 67, 0, 0, 0, 0,
    0, 0, 68, 69, 70, 71, 0, 0, 72, 73, 0, 0, 0, 0, 0, 0, 74, 75, 76, 77, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[77] = { 2, 3, 1, 3, 0, 8, 13, 11, 3, 13, 0, 2, 10,
    0, 11, 0, 11, 0, 0, 13, 5, 2, 7, 10, 10, 0, 10, 10, 5, 0, 0, 3, 10, 0, 0, 0,
    0, 0, 2, 0, 0, 0, 0, 0, 0, 13, 11, 3, 8, 2, 0, 0, 10, 0, 0, 0, 0, 8, 0, 13,
    0, 0, 0, 4, 7, 0, 7, 0, 0, 0, 7, 5, 0, 0, 0, 0, 0 };

  static const boolean_T bv[77] = { false, false, false, false, true, false,
    false, false, false, false, true, false, false, true, false, true, false,
    true, true, false, false, false, false, false, false, true, false, false,
    false, true, true, false, false, true, true, true, true, true, false, true,
    true, true, true, true, true, false, false, false, false, false, true, true,
    false, true, true, true, true, false, true, false, true, true, true, false,
    false, true, false, true, true, true, false, false, true, true, true, true,
    true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 77U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 77U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 154U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 77; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 154; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 77U * sizeof(boolean_T));
  obj_Prior[0] = 0.548159749412686;
  obj_Prior[1] = 0.45184025058731403;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[77]
 *                const double obj_Children[154]
 *                const double obj_CutPoint[77]
 *                const boolean_T obj_NanCutPoints[77]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[154]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void d_CompactClassificationTree_pre(const double obj_CutPredictorIndex[77],
  const double obj_Children[154], const double obj_CutPoint[77], const boolean_T
  obj_NanCutPoints[77], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[154], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 77 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[65]
 *                double obj_Children[130]
 *                double obj_CutPoint[65]
 *                boolean_T obj_NanCutPoints[65]
 *                boolean_T obj_InfCutPoints[65]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[130]
 * Return Type  : void
 */
void db_CompactClassificationTree_Co(double obj_CutPredictorIndex[65], double
  obj_Children[130], double obj_CutPoint[65], boolean_T obj_NanCutPoints[65],
  boolean_T obj_InfCutPoints[65], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[130])
{
  static const double dv1[130] = { 0.54894283476899142, 0.976027397260274,
    0.18903318903318905, 0.98409893992932862, 0.72222222222222221,
    0.94117647058823528, 0.1072, 1.0, 0.96590909090909094, 1.0,
    0.2857142857142857, 1.0, 0.0, 0.82051282051282037, 0.059726962457337891,
    0.99206349206349209, 0.41666666666666663, 0.66666666666666674, 0.0,
    0.36363636363636365, 1.0, 0.43478260869565222, 0.044404973357015994,
    0.99590163934426235, 0.875, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.6428571428571429,
    0.1111111111111111, 0.023593466424682408, 1.0, 1.0, 0.9375, 0.0, 1.0,
    0.2857142857142857, 1.0, 1.0, 0.0, 0.065934065934065977,
    0.015217391304347839, 1.0, 0.66666666666666674, 0.0, 1.0, 0.0,
    0.27272727272727282, 0.3125, 0.0045045045045045079, 1.0, 0.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 0.031250000000000028, 0.0, 0.4, 0.0, 1.0, 0.45105716523100864,
    0.02397260273972604, 0.810966810966811, 0.01590106007067139,
    0.27777777777777785, 0.058823529411764747, 0.8928, 0.0, 0.034090909090909123,
    0.0, 0.71428571428571419, 0.0, 1.0, 0.17948717948717957, 0.94027303754266212,
    0.0079365079365079413, 0.58333333333333337, 0.33333333333333331, 1.0,
    0.63636363636363635, 0.0, 0.56521739130434778, 0.955595026642984,
    0.0040983606557377077, 0.12499999999999999, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.3571428571428571, 0.88888888888888884, 0.97640653357531759, 0.0, 0.0,
    0.062500000000000014, 1.0, 0.0, 0.71428571428571419, 0.0, 0.0, 1.0,
    0.93406593406593408, 0.98478260869565215, 0.0, 0.33333333333333331, 1.0, 0.0,
    1.0, 0.72727272727272718, 0.6875, 0.99549549549549554, 0.0, 1.0, 1.0, 0.0,
    1.0, 0.0, 1.0, 0.96875, 1.0, 0.59999999999999987, 1.0, 0.0 };

  static const double dv[65] = { 0.055, 0.045, 0.27, 0.815, 1.115, 0.79, 0.04,
    0.0, 0.21500000000000002, 0.0, 0.15000000000000002, 0.0, 0.0,
    1.0499999999999998, 0.365, 2.0949999999999998, 0.24, 0.07, 0.0,
    0.12000000000000001, 0.0, 1.0350000000000001, 1.815, 0.025,
    1.6099999999999999, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.005, 0.02, 0.765, 0.0,
    0.0, 1.245, 0.0, 0.0, 1.345, 0.0, 0.0, 0.0, 1.4100000000000001, 0.865, 0.0,
    0.96, 0.0, 0.0, 0.0, 0.69500000000000006, 1.4500000000000002,
    1.0950000000000002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.085, 0.0, 0.005,
    0.0, 0.0 };

  static const signed char iv1[130] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 18, 19, 0, 0, 0, 0, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 0, 0, 30, 31, 0, 0, 32, 33, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 40, 41, 42, 43, 44, 45, 0, 0, 0, 0, 46, 47, 0, 0, 0,
    0, 48, 49, 0, 0, 0, 0, 0, 0, 50, 51, 52, 53, 0, 0, 54, 55, 0, 0, 0, 0, 0, 0,
    56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 63, 0,
    0, 64, 65, 0, 0, 0, 0 };

  static const signed char iv[65] = { 2, 2, 13, 11, 5, 11, 1, 0, 1, 0, 1, 0, 0,
    10, 11, 10, 3, 1, 0, 2, 0, 8, 8, 2, 7, 0, 0, 0, 0, 0, 0, 11, 11, 11, 0, 0, 8,
    0, 0, 5, 0, 0, 0, 10, 5, 0, 7, 0, 0, 0, 13, 10, 13, 0, 0, 0, 0, 0, 0, 0, 10,
    0, 6, 0, 0 };

  static const boolean_T bv[65] = { false, false, false, false, false, false,
    false, true, false, true, false, true, true, false, false, false, false,
    false, true, false, true, false, false, false, false, true, true, true, true,
    true, true, false, false, false, true, true, false, true, true, false, true,
    true, true, false, false, true, false, true, true, true, false, false, false,
    true, true, true, true, true, true, true, false, true, false, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 65U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 65U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 130U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 65; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 130; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 65U * sizeof(boolean_T));
  obj_Prior[0] = 0.54894283476898986;
  obj_Prior[1] = 0.45105716523101019;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[81]
 *                double obj_Children[162]
 *                double obj_CutPoint[81]
 *                boolean_T obj_NanCutPoints[81]
 *                boolean_T obj_InfCutPoints[81]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[162]
 * Return Type  : void
 */
void e_CompactClassificationTree_Com(double obj_CutPredictorIndex[81], double
  obj_Children[162], double obj_CutPoint[81], boolean_T obj_NanCutPoints[81],
  boolean_T obj_InfCutPoints[81], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[162])
{
  static const double dv1[162] = { 0.55833985904463768, 0.9850746268656716,
    0.17655786350148367, 0.99711815561959649, 0.96875, 0.85964912280701744,
    0.11345218800648299, 1.0, 0.95238095238095244, 0.93939393939393945,
    0.97894736842105268, 0.90384615384615374, 0.39999999999999997,
    0.71428571428571419, 0.061619718309859163, 1.0, 0.0, 1.0, 0.6, 0.9921875,
    0.95161290322580649, 0.95454545454545459, 0.625, 0.0, 1.0, 0.0,
    0.92105263157894735, 0.030909090909090921, 1.0, 1.0, 0.19999999999999998,
    0.95652173913043481, 1.0, 0.59999999999999987, 0.98245614035087725,
    0.33333333333333337, 1.0, 1.0, 0.0, 1.0, 0.0, 0.43478260869565222,
    0.013282732447817847, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.91666666666666674,
    0.0, 1.0, 0.380952380952381, 1.0, 0.011406844106463887, 1.0, 1.0, 0.0,
    0.61538461538461531, 0.0, 0.0022779043280182249, 0.057471264367816133, 1.0,
    0.16666666666666666, 0.013333333333333343, 0.0, 1.0, 0.012048192771084345,
    0.0, 1.0, 0.33333333333333337, 0.0, 0.0, 0.19999999999999998, 0.0, 0.5, 1.0,
    0.0, 1.0, 0.0, 0.44166014095536238, 0.014925373134328372,
    0.82344213649851628, 0.00288184438040346, 0.031250000000000028,
    0.14035087719298256, 0.88654781199351707, 0.0, 0.047619047619047637,
    0.060606060606060649, 0.021052631578947382, 0.0961538461538462,
    0.59999999999999987, 0.28571428571428581, 0.93838028169014087, 0.0, 1.0, 0.0,
    0.39999999999999997, 0.0078125000000000052, 0.048387096774193575,
    0.045454545454545484, 0.37499999999999994, 1.0, 0.0, 1.0,
    0.078947368421052669, 0.96909090909090911, 0.0, 0.0, 0.79999999999999993,
    0.043478260869565237, 0.0, 0.39999999999999997, 0.01754385964912282,
    0.66666666666666674, 0.0, 0.0, 1.0, 0.0, 1.0, 0.56521739130434778,
    0.98671726755218214, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.083333333333333343,
    1.0, 0.0, 0.619047619047619, 0.0, 0.98859315589353614, 0.0, 0.0, 1.0,
    0.38461538461538458, 1.0, 0.99772209567198178, 0.94252873563218387, 0.0,
    0.83333333333333326, 0.98666666666666669, 1.0, 0.0, 0.98795180722891562, 1.0,
    0.0, 0.66666666666666674, 1.0, 1.0, 0.79999999999999993, 1.0, 0.5, 0.0, 1.0,
    0.0, 1.0 };

  static const double dv[81] = { 0.055, 1.245, 0.27, 1.44, 0.975, 0.32, 0.035,
    0.0, 0.035, 0.015, 1.665, 1.2650000000000001, 1.145, 1.05, 1.815, 0.0, 0.0,
    0.0, 0.75, 1.2850000000000001, 1.6749999999999998, 0.075000000000000011,
    0.19, 0.0, 0.0, 0.0, 0.145, 0.775, 0.0, 0.0, 0.74, 0.845, 0.0, 1.315, 1.71,
    1.195, 0.0, 0.0, 0.0, 0.0, 0.0, 0.755, 1.8450000000000002, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.035, 0.0, 0.0, 0.885, 0.0, 1.455, 0.0, 0.0, 0.0, 0.105,
    0.0, 0.015, 1.205, 0.0, 1.455, 0.95500000000000007, 0.0, 0.0, 2.085, 0.0,
    0.0, 0.97500000000000009, 0.0, 0.0, 0.15, 0.0, 0.94, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[162] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0, 0,
    0, 0, 0, 0, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0, 0, 0, 40, 41,
    42, 43, 0, 0, 0, 0, 44, 45, 46, 47, 0, 0, 48, 49, 50, 51, 52, 53, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 54, 55, 56, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    58, 59, 0, 0, 0, 0, 60, 61, 0, 0, 62, 63, 0, 0, 0, 0, 0, 0, 64, 65, 0, 0, 66,
    67, 68, 69, 0, 0, 70, 71, 72, 73, 0, 0, 0, 0, 74, 75, 0, 0, 0, 0, 76, 77, 0,
    0, 0, 0, 78, 79, 0, 0, 80, 81, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[81] = { 2, 8, 13, 5, 7, 1, 1, 0, 1, 1, 10, 7, 10,
    8, 8, 0, 0, 0, 13, 8, 10, 2, 2, 0, 0, 0, 3, 5, 0, 0, 5, 11, 0, 7, 5, 10, 0,
    0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 13, 0, 7, 0, 0, 0, 2, 0, 3,
    5, 0, 10, 7, 0, 0, 10, 0, 0, 8, 0, 0, 2, 0, 13, 0, 0, 0, 0 };

  static const boolean_T bv[81] = { false, false, false, false, false, false,
    false, true, false, false, false, false, false, false, false, true, true,
    true, false, false, false, false, false, true, true, true, false, false,
    true, true, false, false, true, false, false, false, true, true, true, true,
    true, false, false, true, true, true, true, true, true, true, false, true,
    true, false, true, false, true, true, true, false, true, false, false, true,
    false, false, true, true, false, true, true, false, true, true, false, true,
    false, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 81U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 81U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 162U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 81; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 162; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 81U * sizeof(boolean_T));
  obj_Prior[0] = 0.5583398590446359;
  obj_Prior[1] = 0.44166014095536416;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[81]
 *                const double obj_Children[162]
 *                const double obj_CutPoint[81]
 *                const boolean_T obj_NanCutPoints[81]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[162]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void e_CompactClassificationTree_pre(const double obj_CutPredictorIndex[81],
  const double obj_Children[162], const double obj_CutPoint[81], const boolean_T
  obj_NanCutPoints[81], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[162], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 81 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[63]
 *                double obj_Children[126]
 *                double obj_CutPoint[63]
 *                boolean_T obj_NanCutPoints[63]
 *                boolean_T obj_InfCutPoints[63]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[126]
 * Return Type  : void
 */
void eb_CompactClassificationTree_Co(double obj_CutPredictorIndex[63], double
  obj_Children[126], double obj_CutPoint[63], boolean_T obj_NanCutPoints[63],
  boolean_T obj_InfCutPoints[63], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[126])
{
  static const double dv1[126] = { 0.57556773688332252, 0.82206405693950257,
    0.096774193548387108, 0.96313364055299544, 0.77316293929712465,
    0.3444444444444445, 0.031976744186046534, 1.0, 0.88888888888888884,
    0.78792822185970635, 0.076923076923076941, 0.46969696969696972, 0.0, 1.0,
    0.0089285714285714333, 0.71999999999999986, 0.97872340425531912,
    0.96025104602510458, 0.17777777777777778, 1.0, 0.0, 0.9642857142857143,
    0.10526315789473689, 1.0, 0.0029940119760479061, 0.85714285714285721, 0.0,
    1.0, 0.0, 0.99763033175355453, 0.67857142857142849, 0.70967741935483863,
    0.019230769230769242, 1.0, 0.0, 0.0, 1.0, 0.25, 0.0, 0.0, 1.0, 1.0,
    0.97727272727272729, 0.861111111111111, 0.35000000000000003, 0.0, 1.0, 0.0,
    1.0, 1.0, 0.0, 1.0, 0.90909090909090917, 0.0, 0.91176470588235292, 0.0, 1.0,
    1.0, 0.0, 0.85000000000000009, 1.0, 1.0, 0.0, 0.42443226311667742,
    0.17793594306049743, 0.90322580645161288, 0.036866359447004636,
    0.2268370607028754, 0.65555555555555556, 0.96802325581395354, 0.0,
    0.11111111111111119, 0.21207177814029365, 0.92307692307692313,
    0.53030303030303028, 1.0, 0.0, 0.9910714285714286, 0.28000000000000008,
    0.021276595744680864, 0.039748953974895411, 0.82222222222222219, 0.0, 1.0,
    0.035714285714285733, 0.894736842105263, 0.0, 0.99700598802395213,
    0.1428571428571429, 1.0, 0.0, 1.0, 0.0023696682464454991,
    0.32142857142857151, 0.29032258064516142, 0.98076923076923073, 0.0, 1.0, 1.0,
    0.0, 0.74999999999999989, 1.0, 1.0, 0.0, 0.0, 0.022727272727272742,
    0.13888888888888895, 0.64999999999999991, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0,
    0.090909090909090912, 1.0, 0.0882352941176471, 1.0, 0.0, 0.0, 1.0,
    0.15000000000000005, 0.0, 0.0, 1.0 };

  static const double dv[63] = { 0.08, 0.455, 0.295, 0.045, 0.015, 0.235, 0.27,
    0.0, 0.095, 0.10500000000000001, 0.62, 0.305, 0.0, 0.0, 0.12000000000000001,
    0.29000000000000004, 0.01, 0.045, 0.045, 0.0, 0.0, 0.6, 2.08, 0.0, 0.055,
    0.085, 0.0, 0.0, 0.0, 1.525, 0.14500000000000002, 1.0350000000000001, 1.83,
    0.0, 0.0, 0.0, 0.0, 0.165, 0.0, 0.0, 0.0, 0.0, 1.085, 0.51,
    1.5699999999999998, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.015, 0.0,
    1.0350000000000001, 0.0, 0.0, 0.0, 0.0, 0.995, 0.0, 0.0, 0.0 };

  static const signed char iv1[126] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 0, 0, 0, 0, 24, 25, 26, 27, 28,
    29, 30, 31, 32, 33, 0, 0, 0, 0, 34, 35, 36, 37, 0, 0, 38, 39, 40, 41, 0, 0,
    0, 0, 0, 0, 42, 43, 44, 45, 46, 47, 48, 49, 0, 0, 0, 0, 0, 0, 0, 0, 50, 51,
    0, 0, 0, 0, 0, 0, 0, 0, 52, 53, 54, 55, 56, 57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 58, 59, 0, 0, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 62, 63, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv[63] = { 3, 11, 3, 2, 3, 1, 13, 0, 1, 2, 10, 11, 0,
    0, 8, 11, 4, 2, 1, 0, 0, 9, 10, 0, 2, 2, 0, 0, 0, 7, 1, 10, 5, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 11, 11, 7, 0, 0, 0, 0, 0, 0, 0, 1, 0, 13, 0, 0, 0, 0, 11, 0, 0,
    0 };

  static const boolean_T bv[63] = { false, false, false, false, false, false,
    false, true, false, false, false, false, true, true, false, false, false,
    false, false, true, true, false, false, true, false, false, true, true, true,
    false, false, false, false, true, true, true, true, false, true, true, true,
    true, false, false, false, true, true, true, true, true, true, true, false,
    true, false, true, true, true, true, false, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 63U * sizeof(double));
  for (i = 0; i < 63; i++) {
    obj_NanCutPoints[i] = bv[i];
  }

  memcpy(&obj_ClassProbability[0], &dv1[0], 126U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 63; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 126; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 63; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.5755677368833203;
  obj_Prior[1] = 0.4244322631166797;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[63]
 *                double obj_Children[126]
 *                double obj_CutPoint[63]
 *                boolean_T obj_NanCutPoints[63]
 *                boolean_T obj_InfCutPoints[63]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[126]
 * Return Type  : void
 */
void f_CompactClassificationTree_Com(double obj_CutPredictorIndex[63], double
  obj_Children[126], double obj_CutPoint[63], boolean_T obj_NanCutPoints[63],
  boolean_T obj_InfCutPoints[63], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[126])
{
  static const double dv1[126] = { 0.57948316366484187, 0.96752136752136753,
    0.25144508670520233, 0.98758865248226946, 0.42857142857142866,
    0.65734265734265729, 0.14571948998178508, 0.990990990990991,
    0.77777777777777779, 0.0, 0.6428571428571429, 0.978021978021978,
    0.0961538461538462, 0.90476190476190477, 0.082840236686390539,
    0.97499999999999987, 0.99746835443037973, 1.0, 0.0, 0.0, 1.0,
    0.98863636363636365, 0.66666666666666674, 1.0, 0.020833333333333346, 1.0,
    0.0, 0.054878048780487812, 1.0, 0.894736842105263, 1.0, 0.99459459459459465,
    1.0, 0.8571428571428571, 1.0, 0.0, 1.0, 0.0, 1.0, 0.65217391304347816,
    0.025586353944562913, 1.0, 0.5, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.0053050397877984117, 0.1086956521739131, 1.0, 0.0, 0.22222222222222218,
    0.0, 1.0, 0.012048192771084345, 0.0, 0.66666666666666674, 1.0, 0.0, 1.0, 0.0,
    0.42051683633515818, 0.032478632478632488, 0.74855491329479762,
    0.012411347517730507, 0.5714285714285714, 0.34265734265734266,
    0.85428051001821492, 0.0090090090090090159, 0.22222222222222218, 1.0,
    0.3571428571428571, 0.021978021978021994, 0.90384615384615374,
    0.0952380952380953, 0.91715976331360949, 0.025000000000000015,
    0.0025316455696202549, 0.0, 1.0, 1.0, 0.0, 0.011363636363636371,
    0.33333333333333337, 0.0, 0.97916666666666663, 0.0, 1.0, 0.94512195121951226,
    0.0, 0.10526315789473689, 0.0, 0.0054054054054054092, 0.0,
    0.14285714285714285, 0.0, 1.0, 0.0, 1.0, 0.0, 0.34782608695652178,
    0.97441364605543712, 0.0, 0.5, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.99469496021220161, 0.89130434782608681, 0.0, 1.0, 0.77777777777777779, 1.0,
    0.0, 0.98795180722891562, 1.0, 0.33333333333333337, 0.0, 1.0, 0.0, 1.0 };

  static const double dv[63] = { 0.065, 0.135, 0.945, 1.8, 1.0699999999999998,
    0.095, 0.265, 1.1749999999999998, 0.275, 0.0, 1.5750000000000002, 1.23,
    0.225, 0.32999999999999996, 1.815, 0.415, 1.435, 0.0, 0.0, 0.0, 0.0,
    0.075000000000000011, 1.31, 0.0, 1.38, 0.0, 0.0, 0.045, 0.0, 0.97, 0.0,
    0.205, 0.0, 0.06, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2349999999999999,
    1.4049999999999998, 0.0, 0.165, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.4,
    0.44499999999999995, 0.0, 0.0, 0.425, 0.0, 0.0, 1.1, 0.0,
    0.12000000000000001, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[126] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 0, 0, 0, 0, 0, 0, 0, 0, 34, 35, 36, 37, 0, 0, 38, 39, 0, 0, 0, 0, 40,
    41, 0, 0, 42, 43, 0, 0, 44, 45, 0, 0, 46, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    48, 49, 50, 51, 0, 0, 52, 53, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54, 55, 56,
    57, 0, 0, 0, 0, 58, 59, 0, 0, 0, 0, 60, 61, 0, 0, 62, 63, 0, 0, 0, 0, 0, 0,
    0, 0 };

  static const signed char iv[63] = { 1, 2, 5, 7, 10, 2, 13, 10, 3, 0, 8, 8, 13,
    1, 8, 11, 10, 0, 0, 0, 0, 1, 8, 0, 7, 0, 0, 2, 0, 10, 0, 3, 0, 2, 0, 0, 0, 0,
    0, 7, 7, 0, 13, 0, 0, 0, 0, 0, 0, 10, 13, 0, 0, 12, 0, 0, 8, 0, 8, 0, 0, 0,
    0 };

  static const boolean_T bv[63] = { false, false, false, false, false, false,
    false, false, false, true, false, false, false, false, false, false, false,
    true, true, true, true, false, false, true, false, true, true, false, true,
    false, true, false, true, false, true, true, true, true, true, false, false,
    true, false, true, true, true, true, true, true, false, false, true, true,
    false, true, true, false, true, false, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 63U * sizeof(double));
  for (i = 0; i < 63; i++) {
    obj_NanCutPoints[i] = bv[i];
  }

  memcpy(&obj_ClassProbability[0], &dv1[0], 126U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 63; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 126; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 63; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.57948316366483943;
  obj_Prior[1] = 0.42051683633516052;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[63]
 *                const double obj_Children[126]
 *                const double obj_CutPoint[63]
 *                const boolean_T obj_NanCutPoints[63]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[126]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void f_CompactClassificationTree_pre(const double obj_CutPredictorIndex[63],
  const double obj_Children[126], const double obj_CutPoint[63], const boolean_T
  obj_NanCutPoints[63], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[126], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 63 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[75]
 *                double obj_Children[150]
 *                double obj_CutPoint[75]
 *                boolean_T obj_NanCutPoints[75]
 *                boolean_T obj_InfCutPoints[75]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[150]
 * Return Type  : void
 */
void fb_CompactClassificationTree_Co(double obj_CutPredictorIndex[75], double
  obj_Children[150], double obj_CutPoint[75], boolean_T obj_NanCutPoints[75],
  boolean_T obj_InfCutPoints[75], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[150])
{
  static const double dv1[150] = { 0.55833985904463768, 0.94956521739130439,
    0.2378917378917379, 0.97644927536231885, 0.3043478260869566,
    0.73958333333333326, 0.15841584158415842, 1.0, 0.95608108108108114, 1.0, 0.0,
    0.37500000000000006, 1.0, 0.86956521739130421, 0.1, 0.60000000000000009,
    0.97508896797153022, 0.66666666666666663, 0.20000000000000007, 0.975,
    0.16666666666666666, 0.072222222222222229, 0.85000000000000009, 1.0, 0.0,
    1.0, 0.91954022988505746, 0.0, 0.83333333333333326, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 0.063551401869158891, 1.0, 0.94444444444444442, 0.0, 1.0,
    0.75862068965517226, 1.0, 0.66666666666666674, 0.18343195266272191,
    0.0081967213114754137, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.85185185185185175,
    0.056338028169014134, 0.0027855153203342636, 0.2857142857142857,
    0.63636363636363646, 1.0, 0.30769230769230776, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.875, 0.0, 0.0, 0.7272727272727274, 1.0, 0.66666666666666674, 1.0, 0.25,
    1.0, 0.0, 0.0, 1.0, 0.44166014095536238, 0.050434782608695661,
    0.7621082621082621, 0.023550724637681174, 0.69565217391304335,
    0.26041666666666669, 0.84158415841584155, 0.0, 0.043918918918918942, 0.0,
    1.0, 0.625, 0.0, 0.13043478260869573, 0.9, 0.4, 0.024911032028469771,
    0.33333333333333331, 0.79999999999999993, 0.025000000000000015,
    0.83333333333333326, 0.92777777777777781, 0.15000000000000005, 0.0, 1.0, 0.0,
    0.080459770114942583, 1.0, 0.16666666666666666, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.93644859813084114, 0.0, 0.055555555555555573, 1.0, 0.0,
    0.24137931034482768, 0.0, 0.33333333333333337, 0.81656804733727806,
    0.99180327868852458, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.1481481481481482,
    0.94366197183098588, 0.99721448467966578, 0.71428571428571419,
    0.36363636363636365, 0.0, 0.69230769230769218, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.12499999999999999, 1.0, 1.0, 0.27272727272727271, 0.0, 0.33333333333333337,
    0.0, 0.74999999999999989, 0.0, 1.0, 1.0, 0.0 };

  static const double dv[75] = { 0.055, 0.085, 0.84, 1.1349999999999998,
    0.22499999999999998, 1.355, 0.255, 0.0, 0.985, 0.0, 0.0, 0.60000000000000009,
    0.0, 0.78499999999999992, 2.075, 0.045000000000000005, 0.865, 0.21, 0.26,
    1.25, 0.275, 1.2, 0.11, 0.0, 0.0, 0.0, 0.015, 0.0, 0.60000000000000009, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.075, 0.0, 0.16, 0.0, 0.0, 1.5, 0.0, 0.345, 1.065,
    0.425, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.71500000000000008, 1.16, 2.08, 0.14,
    1.12, 0.0, 1.1749999999999998, 0.0, 0.0, 0.0, 0.0, 0.0, 0.075, 0.0, 0.0,
    0.07, 0.0, 0.49, 0.0, 1.365, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[150] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 0, 0, 0, 0, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0, 0, 0, 40, 41,
    0, 0, 42, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 44, 45, 0, 0, 46, 47, 0, 0,
    0, 0, 48, 49, 0, 0, 50, 51, 52, 53, 54, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 0, 0, 66, 67, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 68, 69, 0, 0, 0, 0, 70, 71, 0, 0, 72, 73, 0, 0, 74, 75, 0, 0, 0, 0,
    0, 0, 0, 0 };

  static const signed char iv[75] = { 1, 3, 5, 5, 11, 10, 13, 0, 8, 0, 0, 5, 0,
    11, 10, 2, 13, 8, 11, 7, 1, 13, 12, 0, 0, 0, 1, 0, 13, 0, 0, 0, 0, 0, 0, 3,
    0, 2, 0, 0, 5, 0, 10, 5, 12, 0, 0, 0, 0, 0, 0, 11, 8, 5, 2, 8, 0, 10, 0, 0,
    0, 0, 0, 2, 0, 0, 2, 0, 11, 0, 7, 0, 0, 0, 0 };

  static const boolean_T bv[75] = { false, false, false, false, false, false,
    false, true, false, true, true, false, true, false, false, false, false,
    false, false, false, false, false, false, true, true, true, false, true,
    false, true, true, true, true, true, true, false, true, false, true, true,
    false, true, false, false, false, true, true, true, true, true, true, false,
    false, false, false, false, true, false, true, true, true, true, true, false,
    true, true, false, true, false, true, false, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 75U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 75U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 150U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 75; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 150; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 75U * sizeof(boolean_T));
  obj_Prior[0] = 0.5583398590446359;
  obj_Prior[1] = 0.44166014095536416;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[83]
 *                double obj_Children[166]
 *                double obj_CutPoint[83]
 *                boolean_T obj_NanCutPoints[83]
 *                boolean_T obj_InfCutPoints[83]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[166]
 * Return Type  : void
 */
void g_CompactClassificationTree_Com(double obj_CutPredictorIndex[83], double
  obj_Children[166], double obj_CutPoint[83], boolean_T obj_NanCutPoints[83],
  boolean_T obj_InfCutPoints[83], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[166])
{
  static const double dv1[166] = { 0.55285826155051065, 0.80760095011876554,
    0.059770114942528749, 0.92571428571428571, 0.61198738170347, 0.88,
    0.0097560975609756167, 0.92925430210325044, 0.0, 0.60260586319218234,
    0.90000000000000013, 1.0, 0.0, 0.0073349633251833784, 1.0, 0.967741935483871,
    0.22222222222222232, 0.98773006134969321, 0.16666666666666669, 1.0, 0.0,
    0.10526315789473686, 0.0025641025641025658, 0.99147727272727271,
    0.9097222222222221, 0.0, 1.0, 0.96491228070175439, 1.0, 1.0,
    0.097744360902255675, 0.0, 1.0, 0.0, 0.027777777777777794, 1.0,
    0.97029702970297027, 0.5, 0.9538461538461539, 1.0, 0.33333333333333337,
    0.062500000000000056, 1.0, 0.0, 0.25, 0.76923076923076927, 1.0, 1.0, 0.0,
    0.99152542372881358, 0.58333333333333337, 1.0, 0.0, 0.83333333333333326,
    0.024590163934426243, 1.0, 0.0, 0.90909090909090917, 0.0, 1.0,
    0.74999999999999989, 1.0, 0.16666666666666666, 0.5, 1.0,
    0.0085470085470085531, 0.39999999999999997, 0.66666666666666674, 1.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.090909090909090912, 1.0, 0.0, 0.0, 1.0, 1.0,
    0.0, 0.44714173844948929, 0.19239904988123452, 0.94022988505747129,
    0.074285714285714288, 0.38801261829652994, 0.12000000000000005,
    0.99024390243902438, 0.070745697896749532, 1.0, 0.39739413680781754,
    0.099999999999999992, 0.0, 1.0, 0.99266503667481665, 0.0,
    0.032258064516129045, 0.77777777777777768, 0.012269938650306756,
    0.83333333333333326, 0.0, 1.0, 0.894736842105263, 0.99743589743589745,
    0.0085227272727272773, 0.090277777777777818, 1.0, 0.0, 0.03508771929824564,
    0.0, 0.0, 0.9022556390977442, 1.0, 0.0, 1.0, 0.97222222222222221, 0.0,
    0.029702970297029719, 0.5, 0.046153846153846191, 0.0, 0.66666666666666674,
    0.9375, 0.0, 1.0, 0.74999999999999989, 0.23076923076923075, 0.0, 0.0, 1.0,
    0.0084745762711864459, 0.41666666666666663, 0.0, 1.0, 0.16666666666666666,
    0.97540983606557374, 0.0, 1.0, 0.090909090909090912, 1.0, 0.0, 0.25, 0.0,
    0.83333333333333326, 0.5, 0.0, 0.99145299145299148, 0.59999999999999987,
    0.33333333333333337, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.90909090909090917, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0 };

  static const double dv[83] = { 0.065, 1.2149999999999999, 0.26, 0.01, 0.005,
    0.24, 2.08, 0.2, 0.0, 0.10500000000000001, 0.305, 0.0, 0.0, 0.48, 0.0, 0.035,
    1.55, 1.4849999999999999, 0.43, 0.0, 0.0, 1.575, 1.475, 1.225, 1.12, 0.0,
    0.0, 1.0750000000000002, 0.0, 0.0, 1.8450000000000002, 0.0, 0.0, 0.0,
    1.0150000000000001, 0.0, 1.29, 0.895, 1.165, 0.0, 1.48, 0.075000000000000011,
    0.0, 0.0, 1.745, 0.015, 0.0, 0.0, 0.0, 0.10500000000000001, 0.565, 0.0, 0.0,
    0.71500000000000008, 1.18, 0.0, 0.0, 0.595, 0.0, 0.0, 0.395, 0.0,
    1.1349999999999998, 1.31, 0.0, 1.725, 0.14, 0.975, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.175, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[166] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 0, 0, 0, 0, 22, 23, 0, 0, 24, 25, 26,
    27, 28, 29, 30, 31, 0, 0, 0, 0, 32, 33, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0,
    40, 41, 0, 0, 0, 0, 42, 43, 0, 0, 0, 0, 0, 0, 44, 45, 0, 0, 46, 47, 48, 49,
    50, 51, 0, 0, 52, 53, 54, 55, 0, 0, 0, 0, 56, 57, 58, 59, 0, 0, 0, 0, 0, 0,
    60, 61, 62, 63, 0, 0, 0, 0, 64, 65, 66, 67, 0, 0, 0, 0, 68, 69, 0, 0, 0, 0,
    70, 71, 0, 0, 72, 73, 74, 75, 0, 0, 76, 77, 78, 79, 80, 81, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 82, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[83] = { 3, 7, 13, 4, 6, 2, 5, 2, 0, 1, 1, 0, 0, 13,
    0, 1, 5, 5, 13, 0, 0, 10, 7, 5, 10, 0, 0, 13, 0, 0, 5, 0, 0, 0, 11, 0, 5, 7,
    7, 0, 7, 2, 0, 0, 8, 1, 0, 0, 0, 2, 13, 0, 0, 13, 13, 0, 0, 13, 0, 0, 13, 0,
    8, 7, 0, 7, 2, 8, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0 };

  static const boolean_T bv[83] = { false, false, false, false, false, false,
    false, false, true, false, false, true, true, false, true, false, false,
    false, false, true, true, false, false, false, false, true, true, false,
    true, true, false, true, true, true, false, true, false, false, false, true,
    false, false, true, true, false, false, true, true, true, false, false, true,
    true, false, false, true, true, false, true, true, false, true, false, false,
    true, false, false, false, true, true, true, true, true, true, true, true,
    false, true, true, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 83U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 83U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 166U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 83; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 166; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 83U * sizeof(boolean_T));
  obj_Prior[0] = 0.552858261550509;
  obj_Prior[1] = 0.447141738449491;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[83]
 *                const double obj_Children[166]
 *                const double obj_CutPoint[83]
 *                const boolean_T obj_NanCutPoints[83]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[166]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void g_CompactClassificationTree_pre(const double obj_CutPredictorIndex[83],
  const double obj_Children[166], const double obj_CutPoint[83], const boolean_T
  obj_NanCutPoints[83], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[166], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 83 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[89]
 *                double obj_Children[178]
 *                double obj_CutPoint[89]
 *                boolean_T obj_NanCutPoints[89]
 *                boolean_T obj_InfCutPoints[89]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[178]
 * Return Type  : void
 */
void gb_CompactClassificationTree_Co(double obj_CutPredictorIndex[89], double
  obj_Children[178], double obj_CutPoint[89], boolean_T obj_NanCutPoints[89],
  boolean_T obj_InfCutPoints[89], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[178])
{
  static const double dv1[178] = { 0.57635082223962641, 0.914396887159533,
    0.49117647058823527, 0.99285714285714288, 0.82051282051282037,
    0.44864864864864862, 0.90526315789473666, 1.0, 0.66666666666666674,
    0.96153846153846156, 0.53846153846153844, 0.96107784431137722,
    0.15905245346869715, 1.0, 0.65384615384615374, 1.0, 0.0, 0.97368421052631582,
    0.5, 1.0, 0.0, 0.97734627831715215, 0.7599999999999999, 0.80357142857142849,
    0.091588785046728974, 1.0, 0.24999999999999994, 1.0, 0.88888888888888884,
    1.0, 0.0, 0.99516908212560384, 0.94117647058823528, 1.0, 0.14285714285714285,
    0.22222222222222218, 0.91489361702127658, 0.91666666666666674,
    0.032064128256513037, 0.11111111111111109, 0.66666666666666674,
    0.59999999999999987, 1.0, 0.98461538461538467, 1.0, 0.96969696969696972, 0.0,
    0.33333333333333337, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.026209677419354854,
    1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.95000000000000007, 1.0,
    0.85714285714285721, 0.0, 1.0, 0.3125, 0.01666666666666668, 1.0, 0.0,
    0.76923076923076927, 1.0, 1.0, 0.0, 0.33333333333333331,
    0.0085470085470085531, 1.0, 0.5, 0.0, 1.0, 0.0021505376344086034, 1.0, 0.0,
    1.0, 1.0, 0.0, 0.42364917776037359, 0.085603112840466955,
    0.50882352941176467, 0.0071428571428571478, 0.17948717948717952,
    0.55135135135135127, 0.094736842105263216, 0.0, 0.33333333333333337,
    0.038461538461538484, 0.46153846153846156, 0.03892215568862277,
    0.84094754653130288, 0.0, 0.34615384615384626, 0.0, 1.0, 0.02631578947368423,
    0.5, 0.0, 1.0, 0.022653721682847915, 0.2400000000000001, 0.19642857142857154,
    0.908411214953271, 0.0, 0.75, 0.0, 0.11111111111111113, 0.0, 1.0,
    0.0048309178743961385, 0.058823529411764747, 0.0, 0.8571428571428571,
    0.77777777777777779, 0.085106382978723458, 0.08333333333333337,
    0.96793587174348694, 0.88888888888888884, 0.33333333333333337,
    0.39999999999999997, 0.0, 0.015384615384615396, 0.0, 0.030303030303030321,
    1.0, 0.66666666666666674, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0,
    0.97379032258064513, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.050000000000000017, 0.0, 0.1428571428571429, 1.0, 0.0, 0.6875,
    0.98333333333333328, 0.0, 1.0, 0.23076923076923075, 0.0, 0.0, 1.0,
    0.66666666666666674, 0.99145299145299148, 0.0, 0.5, 1.0, 0.0,
    0.99784946236559136, 0.0, 1.0, 0.0, 0.0, 1.0 };

  static const double dv[89] = { 0.815, 0.425, 1.7650000000000001, 0.14, 0.18,
    0.055, 1.7850000000000001, 0.0, 0.07, 1.085, 0.11, 0.035, 0.045, 0.0, 0.185,
    0.0, 0.0, 0.065, 0.005, 0.0, 0.0, 1.4649999999999999, 1.42, 0.79, 0.26, 0.0,
    0.005, 0.0, 0.78, 0.0, 0.0, 0.975, 0.29, 0.0, 0.02, 0.11000000000000001,
    0.14, 0.315, 1.1749999999999998, 1.905, 0.14, 0.43999999999999995, 0.0,
    0.765, 0.0, 1.08, 0.0, 0.925, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.365, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.025, 0.0, 0.015, 0.0, 0.0,
    1.0350000000000001, 0.865, 0.0, 0.0, 1.675, 0.0, 0.0, 0.0, 1.495, 2.04, 0.0,
    2.27, 0.0, 0.0, 0.005, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[178] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 26, 27, 0, 0, 0,
    0, 28, 29, 30, 31, 0, 0, 0, 0, 32, 33, 34, 35, 36, 37, 38, 39, 0, 0, 40, 41,
    0, 0, 42, 43, 0, 0, 0, 0, 44, 45, 46, 47, 0, 0, 48, 49, 50, 51, 52, 53, 54,
    55, 56, 57, 58, 59, 60, 61, 62, 63, 0, 0, 64, 65, 0, 0, 66, 67, 0, 0, 68, 69,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 72, 73, 0, 0, 74, 75, 0, 0, 0, 0, 76, 77, 78, 79, 0, 0,
    0, 0, 80, 81, 0, 0, 0, 0, 0, 0, 82, 83, 84, 85, 0, 0, 86, 87, 0, 0, 0, 0, 88,
    89, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[89] = { 5, 5, 5, 6, 1, 2, 10, 0, 5, 7, 3, 2, 1, 0,
    1, 0, 0, 1, 2, 0, 0, 5, 5, 7, 13, 0, 6, 0, 13, 0, 0, 7, 3, 0, 3, 2, 3, 7, 13,
    8, 2, 11, 0, 13, 0, 11, 0, 13, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 0, 2, 0, 0, 8, 5, 0, 0, 8, 0, 0, 0, 10, 10, 0, 10, 0, 0, 8, 0, 0, 0, 0,
    0 };

  static const boolean_T bv[89] = { false, false, false, false, false, false,
    false, true, false, false, false, false, false, true, false, true, true,
    false, false, true, true, false, false, false, false, true, false, true,
    false, true, true, false, false, true, false, false, false, false, false,
    false, false, false, true, false, true, false, true, false, true, true, true,
    true, true, true, true, false, true, true, true, true, true, true, true,
    true, false, true, false, true, true, false, false, true, true, false, true,
    true, true, false, false, true, false, true, true, false, true, true, true,
    true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 89U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 89U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 178U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 89; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 178; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 89U * sizeof(boolean_T));
  obj_Prior[0] = 0.57635082223962408;
  obj_Prior[1] = 0.42364917776037586;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[83]
 *                double obj_Children[166]
 *                double obj_CutPoint[83]
 *                boolean_T obj_NanCutPoints[83]
 *                boolean_T obj_InfCutPoints[83]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[166]
 * Return Type  : void
 */
void h_CompactClassificationTree_Com(double obj_CutPredictorIndex[83], double
  obj_Children[166], double obj_CutPoint[83], boolean_T obj_NanCutPoints[83],
  boolean_T obj_InfCutPoints[83], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[166])
{
  static const double dv1[166] = { 0.55833985904463768, 0.97723577235772363,
    0.16918429003021146, 0.9971910112359551, 0.9498069498069498,
    0.1001727115716753, 0.6506024096385542, 1.0, 0.9850746268656716,
    0.99567099567099571, 0.5714285714285714, 0.65999999999999992,
    0.047258979206049156, 0.93478260869565222, 0.29729729729729737,
    0.94444444444444442, 1.0, 1.0, 0.96969696969696972, 0.12499999999999999,
    0.75, 0.95454545454545459, 0.4285714285714286, 0.28333333333333338,
    0.01705756929637528, 0.85000000000000009, 1.0, 0.16129032258064524, 1.0, 1.0,
    0.0, 0.91666666666666674, 1.0, 0.0, 0.33333333333333337, 1.0,
    0.2857142857142857, 1.0, 0.79999999999999993, 0.5714285714285714, 0.0, 0.875,
    0.1923076923076924, 0.4, 0.0, 0.9375, 0.5, 1.0, 0.071428571428571466, 0.0,
    1.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.24999999999999994, 1.0, 0.0, 1.0,
    0.47619047619047622, 0.0, 0.25, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.099999999999999992, 1.0, 0.71428571428571419, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0,
    0.0, 0.44166014095536238, 0.022764227642276435, 0.83081570996978849,
    0.0028089887640449455, 0.050193050193050218, 0.89982728842832471,
    0.3493975903614458, 0.0, 0.014925373134328368, 0.0043290043290043316,
    0.4285714285714286, 0.34000000000000008, 0.95274102079395084,
    0.065217391304347866, 0.70270270270270263, 0.055555555555555573, 0.0, 0.0,
    0.030303030303030321, 0.875, 0.25000000000000006, 0.045454545454545477,
    0.5714285714285714, 0.71666666666666656, 0.98294243070362475,
    0.15000000000000005, 0.0, 0.83870967741935476, 0.0, 0.0, 1.0,
    0.083333333333333343, 0.0, 1.0, 0.66666666666666674, 0.0,
    0.71428571428571419, 0.0, 0.19999999999999998, 0.42857142857142866, 1.0,
    0.12499999999999999, 0.8076923076923076, 0.59999999999999987, 1.0,
    0.062500000000000014, 0.5, 0.0, 0.9285714285714286, 1.0, 0.0, 0.0, 1.0, 0.5,
    1.0, 0.0, 1.0, 0.75, 0.0, 1.0, 0.0, 0.52380952380952384, 1.0,
    0.74999999999999989, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    0.90000000000000013, 0.0, 0.2857142857142857, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0,
    1.0 };

  static const double dv[83] = { 0.055, 1.16, 1.625, 0.975, 0.035, 0.365, 1.67,
    0.0, 0.975, 1.68, 1.2349999999999999, 0.19, 0.095, 1.7149999999999999, 1.355,
    0.145, 0.0, 0.0, 1.57, 1.15, 1.19, 0.135, 0.44, 0.035, 0.035, 1.645, 0.0,
    0.1, 0.0, 0.0, 0.0, 1.76, 0.0, 0.0, 1.22, 0.0, 0.15000000000000002, 0.0,
    0.21, 1.19, 0.0, 1.135, 0.08, 0.855, 0.0, 0.915, 1.705, 0.0, 1.865, 0.0, 0.0,
    0.0, 0.0, 1.06, 0.0, 0.0, 0.0, 1.33, 0.0, 0.0, 0.0, 1.0350000000000001, 0.0,
    1.03, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.77, 0.0, 1.155, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[166] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    0, 0, 0, 0, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    0, 0, 48, 49, 0, 0, 0, 0, 0, 0, 50, 51, 0, 0, 0, 0, 52, 53, 0, 0, 54, 55, 0,
    0, 56, 57, 58, 59, 0, 0, 60, 61, 62, 63, 64, 65, 0, 0, 66, 67, 68, 69, 0, 0,
    70, 71, 0, 0, 0, 0, 0, 0, 0, 0, 72, 73, 0, 0, 0, 0, 0, 0, 74, 75, 0, 0, 0, 0,
    0, 0, 76, 77, 0, 0, 78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 80, 81, 0, 0, 82, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[83] = { 2, 5, 8, 5, 1, 11, 7, 0, 7, 8, 10, 13, 2,
    8, 11, 3, 0, 0, 7, 8, 7, 13, 12, 1, 1, 5, 0, 2, 0, 0, 0, 8, 0, 0, 8, 0, 1, 0,
    3, 7, 0, 5, 3, 11, 0, 13, 5, 0, 8, 0, 0, 0, 0, 11, 0, 0, 0, 8, 0, 0, 0, 11,
    0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 5, 0, 0, 0, 0, 0, 0, 0 };

  static const boolean_T bv[83] = { false, false, false, false, false, false,
    false, true, false, false, false, false, false, false, false, false, true,
    true, false, false, false, false, false, false, false, false, true, false,
    true, true, true, false, true, true, false, true, false, true, false, false,
    true, false, false, false, true, false, false, true, false, true, true, true,
    true, false, true, true, true, false, true, true, true, false, true, false,
    true, true, true, true, true, true, true, true, true, false, true, false,
    true, true, true, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 83U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 83U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 166U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 83; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 166; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 83U * sizeof(boolean_T));
  obj_Prior[0] = 0.5583398590446359;
  obj_Prior[1] = 0.44166014095536416;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[91]
 *                const double obj_Children[182]
 *                const double obj_CutPoint[91]
 *                const boolean_T obj_NanCutPoints[91]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[182]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void h_CompactClassificationTree_pre(const double obj_CutPredictorIndex[91],
  const double obj_Children[182], const double obj_CutPoint[91], const boolean_T
  obj_NanCutPoints[91], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[182], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 91 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[91]
 *                double obj_Children[182]
 *                double obj_CutPoint[91]
 *                boolean_T obj_NanCutPoints[91]
 *                boolean_T obj_InfCutPoints[91]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[182]
 * Return Type  : void
 */
void i_CompactClassificationTree_Com(double obj_CutPredictorIndex[91], double
  obj_Children[182], double obj_CutPoint[91], boolean_T obj_NanCutPoints[91],
  boolean_T obj_InfCutPoints[91], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[182])
{
  static const double dv1[182] = { 0.56617071260767626, 0.94719471947194722,
    0.22205663189269748, 0.975736568457539, 0.3793103448275863,
    0.81196581196581186, 0.097472924187725629, 0.92499999999999982,
    0.98905908096280093, 0.52380952380952384, 0.0, 0.98461538461538467,
    0.59615384615384615, 0.0655430711610487, 0.95000000000000007,
    0.70000000000000007, 0.94545454545454544, 0.9924050632911392,
    0.967741935483871, 0.77777777777777779, 0.33333333333333331, 1.0,
    0.94736842105263164, 0.28571428571428581, 0.95833333333333337,
    0.71999999999999986, 0.033398821218074672, 1.0, 0.66666666666666674, 1.0,
    0.39999999999999997, 1.0, 0.857142857142857, 0.97058823529411764,
    0.99694189602446481, 0.0, 1.0, 1.0, 0.0, 0.19999999999999998, 1.0, 1.0, 0.5,
    0.090909090909090953, 1.0, 1.0, 0.0, 0.94736842105263164, 0.0,
    0.11971830985915496, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.5,
    0.98684210526315785, 1.0, 1.0, 0.11111111111111109, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.0, 0.5, 0.0090909090909090974, 1.0, 0.0, 1.0, 0.96666666666666667, 1.0,
    0.0, 0.88888888888888884, 0.0, 1.0, 0.0, 0.88888888888888884, 1.0, 1.0,
    0.59999999999999987, 1.0, 0.74999999999999989, 1.0, 0.0, 1.0, 0.0,
    0.43382928739232374, 0.052805280528052813, 0.77794336810730258,
    0.024263431542461019, 0.6206896551724137, 0.18803418803418806,
    0.90252707581227443, 0.075000000000000053, 0.010940919037199133,
    0.47619047619047622, 1.0, 0.015384615384615396, 0.40384615384615385,
    0.93445692883895137, 0.050000000000000017, 0.29999999999999993,
    0.054545454545454584, 0.0075949367088607635, 0.032258064516129052,
    0.22222222222222218, 0.66666666666666674, 0.0, 0.052631578947368439,
    0.71428571428571419, 0.041666666666666685, 0.28000000000000008,
    0.96660117878192531, 0.0, 0.33333333333333337, 0.0, 0.59999999999999987, 0.0,
    0.14285714285714293, 0.029411764705882373, 0.00305810397553517, 1.0, 0.0,
    0.0, 1.0, 0.8, 0.0, 0.0, 0.5, 0.90909090909090917, 0.0, 0.0, 1.0,
    0.052631578947368439, 1.0, 0.880281690140845, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.0, 0.5, 0.013157894736842115, 0.0, 0.0, 0.88888888888888884, 0.0, 1.0,
    0.0, 1.0, 0.0, 1.0, 0.5, 0.990909090909091, 0.0, 1.0, 0.0,
    0.033333333333333354, 0.0, 1.0, 0.11111111111111113, 1.0, 0.0, 1.0,
    0.11111111111111109, 0.0, 0.0, 0.39999999999999997, 0.0, 0.25, 0.0, 1.0, 0.0,
    1.0 };

  static const double dv[91] = { 0.075000000000000011, 0.065, 0.455,
    1.0550000000000002, 0.35, 1.26, 2.075, 0.3, 1.525, 1.13, 0.0, 0.895,
    1.6150000000000002, 0.755, 2.175, 0.03, 0.555, 0.92999999999999994,
    1.4849999999999999, 0.44, 1.86, 0.0, 0.22, 1.245, 0.29500000000000004, 0.145,
    0.01, 0.0, 0.14500000000000002, 0.0, 0.95500000000000007, 0.0, 0.08, 0.905,
    0.905, 0.0, 0.0, 0.0, 0.0, 0.885, 0.0, 0.0, 0.27, 0.12000000000000001, 0.0,
    0.0, 0.0, 0.14, 0.0, 1.1749999999999998, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.47500000000000003, 1.295, 0.0, 0.0, 0.32, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.25, 1.085, 0.0, 0.0, 0.0, 1.5, 0.0, 0.0, 1.225, 0.0, 0.0, 0.0, 1.195,
    0.0, 0.0, 0.05, 0.0, 0.895, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[182] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 0, 0, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 0, 0, 52, 53, 0, 0, 54, 55, 0, 0, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0,
    0, 0, 0, 0, 62, 63, 0, 0, 0, 0, 64, 65, 66, 67, 0, 0, 0, 0, 0, 0, 68, 69, 0,
    0, 70, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 73, 74, 75, 0,
    0, 0, 0, 76, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 78, 79, 80, 81, 0, 0, 0,
    0, 0, 0, 82, 83, 0, 0, 0, 0, 84, 85, 0, 0, 0, 0, 0, 0, 86, 87, 0, 0, 0, 0,
    88, 89, 0, 0, 90, 91, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[91] = { 1, 3, 11, 10, 3, 5, 10, 11, 7, 10, 0, 5, 5,
    5, 10, 1, 13, 8, 5, 11, 10, 0, 2, 10, 1, 3, 3, 0, 2, 0, 10, 0, 2, 8, 7, 0, 0,
    0, 0, 8, 0, 0, 3, 8, 0, 0, 0, 6, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 11, 8, 0, 0,
    13, 0, 0, 0, 0, 0, 0, 1, 8, 0, 0, 0, 10, 0, 0, 5, 0, 0, 0, 5, 0, 0, 2, 0, 7,
    0, 0, 0, 0 };

  static const boolean_T bv[91] = { false, false, false, false, false, false,
    false, false, false, false, true, false, false, false, false, false, false,
    false, false, false, false, true, false, false, false, false, false, true,
    false, true, false, true, false, false, false, true, true, true, true, false,
    true, true, false, false, true, true, true, false, true, false, true, true,
    true, true, true, true, true, true, false, false, true, true, false, true,
    true, true, true, true, true, false, false, true, true, true, false, true,
    true, false, true, true, true, false, true, true, false, true, false, true,
    true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 91U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 91U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 182U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 91; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 182; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 91U * sizeof(boolean_T));
  obj_Prior[0] = 0.56617071260767426;
  obj_Prior[1] = 0.43382928739232579;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[67]
 *                const double obj_Children[134]
 *                const double obj_CutPoint[67]
 *                const boolean_T obj_NanCutPoints[67]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[134]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void i_CompactClassificationTree_pre(const double obj_CutPredictorIndex[67],
  const double obj_Children[134], const double obj_CutPoint[67], const boolean_T
  obj_NanCutPoints[67], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[134], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 67 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[77]
 *                double obj_Children[154]
 *                double obj_CutPoint[77]
 *                boolean_T obj_NanCutPoints[77]
 *                boolean_T obj_InfCutPoints[77]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[154]
 * Return Type  : void
 */
void j_CompactClassificationTree_Com(double obj_CutPredictorIndex[77], double
  obj_Children[154], double obj_CutPoint[77], boolean_T obj_NanCutPoints[77],
  boolean_T obj_InfCutPoints[77], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[154])
{
  static const double dv1[154] = { 0.55050900548159909, 0.97249190938511332,
    0.15477996965098637, 0.98780487804878048, 0.7727272727272726,
    0.34285714285714286, 0.015831134564643811, 0.97747747747747749,
    0.99431818181818177, 0.97142857142857142, 0.0, 0.61842105263157887,
    0.24019607843137256, 0.54545454545454553, 0.0, 1.0, 0.93975903614457823, 1.0,
    0.98319327731092432, 1.0, 0.0, 0.5, 1.0, 0.20207253886010362,
    0.90909090909090917, 1.0, 0.0, 0.96296296296296291, 0.0, 1.0,
    0.88235294117647056, 1.0, 0.40816326530612246, 0.11347517730496458,
    0.44230769230769235, 1.0, 0.50000000000000011, 1.0, 0.86363636363636365, 0.0,
    0.9375, 0.2400000000000001, 0.58333333333333326, 0.83333333333333326,
    0.0081300813008130142, 1.0, 0.14705882352941183, 0.0, 1.0, 0.0, 1.0,
    0.66666666666666674, 1.0, 0.6, 0.0, 0.2857142857142857, 1.0, 0.0, 1.0, 0.0,
    1.0, 0.66666666666666674, 0.03571428571428574, 1.0, 0.0, 0.83333333333333326,
    0.25000000000000006, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.44949099451840091, 0.027508090614886741, 0.84522003034901372,
    0.012195121951219523, 0.22727272727272738, 0.65714285714285714,
    0.9841688654353562, 0.022522522522522539, 0.0056818181818181854,
    0.028571428571428588, 1.0, 0.38157894736842107, 0.75980392156862742,
    0.45454545454545459, 1.0, 0.0, 0.060240963855421728, 0.0,
    0.016806722689075643, 0.0, 1.0, 0.5, 0.0, 0.79792746113989632,
    0.090909090909090912, 0.0, 1.0, 0.037037037037037056, 1.0, 0.0,
    0.11764705882352944, 0.0, 0.59183673469387754, 0.88652482269503541,
    0.55769230769230771, 0.0, 0.5, 0.0, 0.13636363636363641, 1.0,
    0.062500000000000014, 0.7599999999999999, 0.41666666666666674,
    0.16666666666666669, 0.991869918699187, 0.0, 0.8529411764705882, 1.0, 0.0,
    1.0, 0.0, 0.33333333333333331, 0.0, 0.39999999999999997, 1.0,
    0.71428571428571419, 0.0, 1.0, 0.0, 1.0, 0.0, 0.33333333333333331,
    0.9642857142857143, 0.0, 1.0, 0.16666666666666666, 0.74999999999999989, 0.0,
    1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0 };

  static const double dv[77] = { 0.055, 0.195, 0.295, 1.065, 0.03,
    0.10500000000000001, 0.195, 0.905, 1.2149999999999999, 1.335, 0.0, 1.64,
    1.81, 0.175, 0.0, 0.0, 0.045, 0.0, 1.025, 0.0, 0.0, 0.16999999999999998, 0.0,
    1.5750000000000002, 0.86999999999999988, 0.0, 0.0, 1.45, 0.0, 0.0, 1.225,
    0.0, 1.505, 0.35, 1.35, 0.0, 1.865, 0.0, 1.52, 0.0, 1.11, 1.08, 1.405, 1.08,
    1.155, 0.0, 1.685, 0.0, 0.0, 0.0, 0.0, 2.01, 0.0, 0.7, 0.0, 0.89, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.995, 1.855, 0.0, 0.0, 1.02, 1.135, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[154] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0, 28,
    29, 0, 0, 30, 31, 0, 0, 0, 0, 32, 33, 0, 0, 34, 35, 36, 37, 0, 0, 0, 0, 38,
    39, 0, 0, 0, 0, 40, 41, 0, 0, 42, 43, 44, 45, 46, 47, 0, 0, 48, 49, 0, 0, 50,
    51, 0, 0, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 62, 63, 0, 0, 0, 0,
    0, 0, 0, 0, 64, 65, 0, 0, 66, 67, 0, 0, 68, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    70, 71, 72, 73, 0, 0, 0, 0, 74, 75, 76, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[77] = { 2, 1, 3, 8, 3, 2, 11, 8, 7, 8, 0, 10, 5, 2,
    0, 0, 2, 0, 13, 0, 0, 13, 0, 8, 13, 0, 0, 10, 0, 0, 7, 0, 10, 11, 7, 0, 8, 0,
    10, 0, 13, 7, 5, 10, 13, 0, 5, 0, 0, 0, 0, 10, 0, 13, 0, 5, 0, 0, 0, 0, 0,
    10, 8, 0, 0, 7, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const boolean_T bv[77] = { false, false, false, false, false, false,
    false, false, false, false, true, false, false, false, true, true, false,
    true, false, true, true, false, true, false, false, true, true, false, true,
    true, false, true, false, false, false, true, false, true, false, true,
    false, false, false, false, false, true, false, true, true, true, true,
    false, true, false, true, false, true, true, true, true, true, false, false,
    true, true, false, false, true, true, true, true, true, true, true, true,
    true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 77U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 77U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 154U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 77; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 154; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 77U * sizeof(boolean_T));
  obj_Prior[0] = 0.55050900548159754;
  obj_Prior[1] = 0.44949099451840252;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[99]
 *                const double obj_Children[198]
 *                const double obj_CutPoint[99]
 *                const boolean_T obj_NanCutPoints[99]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[198]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void j_CompactClassificationTree_pre(const double obj_CutPredictorIndex[99],
  const double obj_Children[198], const double obj_CutPoint[99], const boolean_T
  obj_NanCutPoints[99], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[198], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 99 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[83]
 *                double obj_Children[166]
 *                double obj_CutPoint[83]
 *                boolean_T obj_NanCutPoints[83]
 *                boolean_T obj_InfCutPoints[83]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[166]
 * Return Type  : void
 */
void k_CompactClassificationTree_Com(double obj_CutPredictorIndex[83], double
  obj_Children[166], double obj_CutPoint[83], boolean_T obj_NanCutPoints[83],
  boolean_T obj_InfCutPoints[83], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[166])
{
  static const double dv1[166] = { 0.562255285826157, 0.83720930232558144,
    0.49263984298331703, 0.95348837209302328, 0.25581395348837221,
    0.95707070707070707, 0.19743178170144463, 1.0, 0.861111111111111,
    0.75000000000000011, 0.14285714285714293, 0.87323943661971826,
    0.97538461538461529, 0.43382352941176472, 0.014245014245014254, 0.96875, 0.0,
    1.0, 0.0, 0.0, 0.625, 0.96875, 0.0, 1.0, 0.950920245398773,
    0.96491228070175439, 0.2930232558139535, 0.00288184438040346, 1.0,
    0.84615384615384615, 1.0, 1.0, 0.0, 1.0, 0.66666666666666674,
    0.33333333333333337, 0.96249999999999991, 1.0, 0.0, 0.81081081081081063,
    0.1853932584269663, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.91891891891891886, 1.0, 0.0, 0.15060240963855423, 0.66666666666666674, 0.5,
    0.94285714285714284, 0.79999999999999993, 0.0616438356164384, 0.5, 1.0, 1.0,
    0.0, 0.94029850746268662, 1.0, 1.0, 0.33333333333333337,
    0.014388489208633103, 1.0, 1.0, 0.0, 0.96923076923076923, 0.0, 0.0, 1.0,
    0.22222222222222218, 0.0, 1.0, 0.9, 0.0, 1.0, 0.0, 1.0, 0.43774471417384309,
    0.16279069767441862, 0.507360157016683, 0.046511627906976778,
    0.74418604651162779, 0.042929292929292942, 0.8025682182985554, 0.0,
    0.13888888888888898, 0.25, 0.8571428571428571, 0.12676056338028177,
    0.024615384615384633, 0.56617647058823528, 0.98575498575498577,
    0.031250000000000021, 1.0, 0.0, 1.0, 1.0, 0.37499999999999994,
    0.031250000000000021, 1.0, 0.0, 0.04907975460122703, 0.03508771929824564,
    0.7069767441860465, 0.99711815561959649, 0.0, 0.15384615384615385, 0.0, 0.0,
    1.0, 0.0, 0.33333333333333337, 0.66666666666666674, 0.037500000000000026,
    0.0, 1.0, 0.18918918918918928, 0.8146067415730337, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.0, 1.0, 0.0, 0.0, 0.081081081081081141, 0.0, 1.0, 0.84939759036144569,
    0.33333333333333331, 0.5, 0.057142857142857183, 0.20000000000000004,
    0.93835616438356151, 0.5, 0.0, 0.0, 1.0, 0.059701492537313473, 0.0, 0.0,
    0.66666666666666674, 0.98561151079136688, 0.0, 0.0, 1.0,
    0.030769230769230792, 1.0, 1.0, 0.0, 0.77777777777777779, 1.0, 0.0,
    0.10000000000000003, 1.0, 0.0, 1.0, 0.0 };

  static const double dv[83] = { 0.805, 0.025, 0.065, 0.805,
    0.075000000000000011, 1.1150000000000002, 0.295, 0.0, 0.16,
    0.11000000000000001, 1.3250000000000002, 0.055, 0.805, 0.275, 1.63, 0.955,
    0.0, 0.0, 0.0, 0.0, 0.865, 0.895, 0.0, 0.0, 0.815, 0.03, 1.0, 0.28, 0.0,
    1.17, 0.0, 0.0, 0.0, 0.0, 0.81, 1.92, 1.1150000000000002, 0.0, 0.0, 0.09,
    0.005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2149999999999999, 0.0,
    0.0, 0.055, 1.3450000000000002, 1.085, 0.005, 1.205, 1.815, 1.635, 0.0, 0.0,
    0.0, 0.04, 0.0, 0.0, 0.16499999999999998, 0.33999999999999997, 0.0, 0.0, 0.0,
    2.105, 0.0, 0.0, 0.0, 1.46, 0.0, 0.0, 1.5, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[166] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    0, 0, 0, 0, 0, 0, 0, 0, 32, 33, 34, 35, 0, 0, 0, 0, 36, 37, 38, 39, 40, 41,
    42, 43, 0, 0, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0, 46, 47, 48, 49, 50, 51, 0, 0,
    0, 0, 52, 53, 54, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    56, 57, 0, 0, 0, 0, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    0, 0, 0, 0, 0, 0, 72, 73, 0, 0, 0, 0, 74, 75, 76, 77, 0, 0, 0, 0, 0, 0, 78,
    79, 0, 0, 0, 0, 0, 0, 80, 81, 0, 0, 0, 0, 82, 83, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[83] = { 7, 3, 1, 11, 1, 8, 3, 0, 1, 2, 10, 2, 13,
    11, 8, 8, 0, 0, 0, 0, 8, 11, 0, 0, 13, 4, 5, 13, 0, 5, 0, 0, 0, 0, 13, 8, 7,
    0, 0, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 2, 11, 5, 12, 8, 8, 7, 0, 0,
    0, 1, 0, 0, 3, 13, 0, 0, 0, 10, 0, 0, 0, 10, 0, 0, 5, 0, 0, 0, 0 };

  static const boolean_T bv[83] = { false, false, false, false, false, false,
    false, true, false, false, false, false, false, false, false, false, true,
    true, true, true, false, false, true, true, false, false, false, false, true,
    false, true, true, true, true, false, false, false, true, true, false, false,
    true, true, true, true, true, true, true, true, true, false, true, true,
    false, false, false, false, false, false, false, true, true, true, false,
    true, true, false, false, true, true, true, false, true, true, true, false,
    true, true, false, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 83U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 83U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 166U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 83; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 166; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 83U * sizeof(boolean_T));
  obj_Prior[0] = 0.562255285826155;
  obj_Prior[1] = 0.437744714173845;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[65]
 *                const double obj_Children[130]
 *                const double obj_CutPoint[65]
 *                const boolean_T obj_NanCutPoints[65]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[130]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void k_CompactClassificationTree_pre(const double obj_CutPredictorIndex[65],
  const double obj_Children[130], const double obj_CutPoint[65], const boolean_T
  obj_NanCutPoints[65], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[130], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 65 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[67]
 *                double obj_Children[134]
 *                double obj_CutPoint[67]
 *                boolean_T obj_NanCutPoints[67]
 *                boolean_T obj_InfCutPoints[67]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[134]
 * Return Type  : void
 */
void l_CompactClassificationTree_Com(double obj_CutPredictorIndex[67], double
  obj_Children[134], double obj_CutPoint[67], boolean_T obj_NanCutPoints[67],
  boolean_T obj_InfCutPoints[67], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[134])
{
  static const double dv1[134] = { 0.56617071260767626, 0.9706362153344209,
    0.19277108433734938, 0.98086956521739133, 0.8157894736842104,
    0.75949367088607589, 0.11623931623931624, 0.997229916897507,
    0.95327102803738317, 0.92592592592592593, 0.54545454545454553,
    0.81081081081081074, 0.0, 0.09580838323353294, 0.23809523809523814, 1.0,
    0.66666666666666674, 0.97607655502392343, 0.0, 0.0, 1.0, 0.2857142857142857,
    1.0, 0.89552238805970141, 0.0, 0.30379746835443039, 0.0, 0.0,
    0.689655172413793, 1.0, 0.0, 1.0, 0.87804878048780477, 1.0, 0.0,
    0.53846153846153844, 0.98148148148148151, 0.66101694915254228,
    0.090909090909090967, 1.0, 0.0, 1.0, 0.6875, 0.0, 0.77777777777777779, 1.0,
    0.5, 0.84782608695652162, 0.0, 0.032258064516129052, 1.0, 0.0, 1.0, 1.0, 0.0,
    0.0, 1.0, 0.96969696969696972, 0.53846153846153844, 0.0, 1.0, 1.0,
    0.83333333333333326, 0.0, 1.0, 0.0, 1.0, 0.43382928739232374,
    0.02936378466557913, 0.80722891566265054, 0.019130434782608709,
    0.18421052631578957, 0.24050632911392411, 0.88376068376068373,
    0.0027700831024930765, 0.046728971962616855, 0.074074074074074112,
    0.45454545454545459, 0.18918918918918926, 1.0, 0.90419161676646709,
    0.76190476190476186, 0.0, 0.33333333333333337, 0.023923444976076572, 1.0,
    1.0, 0.0, 0.71428571428571419, 0.0, 0.10447761194029857, 1.0,
    0.69620253164556956, 1.0, 1.0, 0.310344827586207, 0.0, 1.0, 0.0,
    0.12195121951219517, 0.0, 1.0, 0.46153846153846151, 0.018518518518518531,
    0.33898305084745767, 0.909090909090909, 0.0, 1.0, 0.0, 0.3125, 1.0,
    0.22222222222222218, 0.0, 0.5, 0.15217391304347835, 1.0, 0.967741935483871,
    0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.030303030303030321, 0.46153846153846151,
    1.0, 0.0, 0.0, 0.16666666666666666, 1.0, 0.0, 1.0, 0.0 };

  static const double dv[67] = { 0.055, 0.035, 0.33999999999999997, 1.275,
    1.1349999999999998, 0.535, 1.54, 0.22999999999999998, 0.2,
    1.1400000000000001, 2.065, 0.86, 0.0, 0.005, 2.08, 0.0, 0.78499999999999992,
    1.045, 0.0, 0.0, 0.0, 0.03, 0.0, 0.084999999999999992, 0.0, 1.12, 0.0, 0.0,
    0.19, 0.0, 0.0, 0.0, 0.015, 0.0, 0.0, 0.075000000000000011, 0.325,
    0.15500000000000003, 1.605, 0.0, 0.0, 0.0, 1.0950000000000002, 0.0,
    0.075000000000000011, 0.0, 1.415, 0.195, 0.0, 1.24, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.135, 1.3599999999999999, 0.0, 0.0, 0.0, 0.77, 0.0, 0.0, 0.0, 0.0
  };

  static const signed char iv1[134] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 26, 27, 28, 29, 0, 0,
    30, 31, 32, 33, 0, 0, 0, 0, 0, 0, 34, 35, 0, 0, 36, 37, 0, 0, 38, 39, 0, 0,
    0, 0, 40, 41, 0, 0, 0, 0, 0, 0, 42, 43, 0, 0, 0, 0, 44, 45, 46, 47, 48, 49,
    50, 51, 0, 0, 0, 0, 0, 0, 52, 53, 0, 0, 54, 55, 0, 0, 56, 57, 58, 59, 0, 0,
    60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 63, 64, 65, 0, 0, 0, 0,
    0, 0, 66, 67, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[67] = { 2, 2, 11, 5, 8, 3, 7, 3, 1, 10, 10, 12, 0,
    3, 10, 0, 7, 11, 0, 0, 0, 1, 0, 1, 0, 7, 0, 0, 2, 0, 0, 0, 1, 0, 0, 2, 11, 1,
    8, 0, 0, 0, 11, 0, 1, 0, 10, 2, 0, 11, 0, 0, 0, 0, 0, 0, 0, 2, 5, 0, 0, 0, 7,
    0, 0, 0, 0 };

  static const boolean_T bv[67] = { false, false, false, false, false, false,
    false, false, false, false, false, false, true, false, false, true, false,
    false, true, true, true, false, true, false, true, false, true, true, false,
    true, true, true, false, true, true, false, false, false, false, true, true,
    true, false, true, false, true, false, false, true, false, true, true, true,
    true, true, true, true, false, false, true, true, true, false, true, true,
    true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 67U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 67U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 134U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 67; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 134; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 67U * sizeof(boolean_T));
  obj_Prior[0] = 0.56617071260767426;
  obj_Prior[1] = 0.43382928739232579;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[79]
 *                const double obj_Children[158]
 *                const double obj_CutPoint[79]
 *                const boolean_T obj_NanCutPoints[79]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[158]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void l_CompactClassificationTree_pre(const double obj_CutPredictorIndex[79],
  const double obj_Children[158], const double obj_CutPoint[79], const boolean_T
  obj_NanCutPoints[79], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[158], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 79 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[83]
 *                double obj_Children[166]
 *                double obj_CutPoint[83]
 *                boolean_T obj_NanCutPoints[83]
 *                boolean_T obj_InfCutPoints[83]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[166]
 * Return Type  : void
 */
void m_CompactClassificationTree_Com(double obj_CutPredictorIndex[83], double
  obj_Children[166], double obj_CutPoint[83], boolean_T obj_NanCutPoints[83],
  boolean_T obj_InfCutPoints[83], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[166])
{
  static const double dv1[166] = { 0.55990602975724535, 0.96935483870967742,
    0.17351598173515984, 0.97647058823529409, 0.79999999999999993,
    0.3529411764705882, 0.032608695652173933, 0.98765432098765438,
    0.74999999999999989, 0.90909090909090917, 0.0, 0.90243902439024393,
    0.26209677419354838, 1.0, 0.0028011204481792735, 1.0, 0.97286821705426352,
    1.0, 0.0, 1.0, 0.71428571428571419, 0.94444444444444442, 0.59999999999999987,
    0.20779220779220781, 1.0, 0.0079365079365079413, 0.0, 0.98046875, 0.0, 0.0,
    1.0, 0.5, 1.0, 0.0, 1.0, 0.82499999999999984, 0.078534031413612593, 0.25,
    0.0, 0.95238095238095244, 0.98963730569948183, 1.0, 0.0, 0.5625, 1.0,
    0.7272727272727274, 0.038888888888888917, 1.0, 0.0, 1.0, 0.85714285714285721,
    0.93333333333333335, 0.9943820224719101, 0.0, 1.0, 0.0, 1.0,
    0.66666666666666674, 0.02824858757062149, 1.0, 0.39999999999999997, 1.0, 0.0,
    1.0, 0.98181818181818181, 1.0, 0.0, 0.16666666666666669,
    0.012578616352201267, 1.0, 0.0, 0.0, 1.0, 1.0, 0.062500000000000014, 1.0,
    0.0063291139240506371, 0.0, 1.0, 0.0, 0.25, 1.0, 0.0, 0.4400939702427546,
    0.030645161290322593, 0.82648401826484019, 0.023529411764705896,
    0.20000000000000007, 0.64705882352941169, 0.967391304347826,
    0.012345679012345689, 0.25000000000000006, 0.090909090909090953, 1.0,
    0.097560975609756156, 0.73790322580645162, 0.0, 0.99719887955182074, 0.0,
    0.027131782945736455, 0.0, 1.0, 0.0, 0.2857142857142857,
    0.055555555555555587, 0.39999999999999997, 0.79220779220779225, 0.0,
    0.99206349206349209, 1.0, 0.019531250000000014, 1.0, 1.0, 0.0, 0.5, 0.0, 1.0,
    0.0, 0.1750000000000001, 0.92146596858638741, 0.74999999999999989, 1.0,
    0.047619047619047644, 0.010362694300518142, 0.0, 1.0, 0.4375, 0.0,
    0.27272727272727271, 0.96111111111111114, 0.0, 1.0, 0.0, 0.1428571428571429,
    0.06666666666666668, 0.005617977528089891, 1.0, 0.0, 1.0, 0.0,
    0.33333333333333337, 0.97175141242937857, 0.0, 0.59999999999999987, 0.0, 1.0,
    0.0, 0.018181818181818195, 0.0, 1.0, 0.83333333333333326,
    0.98742138364779874, 0.0, 1.0, 1.0, 0.0, 0.0, 0.9375, 0.0,
    0.99367088607594933, 1.0, 0.0, 1.0, 0.74999999999999989, 0.0, 1.0 };

  static const double dv[83] = { 0.055, 0.045, 0.295, 0.21500000000000002, 0.375,
    0.245, 0.255, 1.4249999999999998, 0.25, 1.1949999999999998, 0.0, 0.32, 1.815,
    0.0, 0.775, 0.0, 0.19999999999999998, 0.0, 0.0, 0.0, 1.315,
    0.075000000000000011, 0.84, 0.04, 0.0, 0.02, 0.0, 0.905, 0.0, 0.0, 0.0,
    1.2349999999999999, 0.0, 0.0, 0.0, 1.295, 0.785, 0.39, 0.0, 1.04, 0.565, 0.0,
    0.0, 1.0350000000000001, 0.0, 0.575, 0.155, 0.0, 0.0, 0.0, 0.015, 0.525,
    1.525, 0.0, 0.0, 0.0, 0.0, 0.485, 0.075000000000000011, 0.0,
    0.95500000000000007, 0.0, 0.0, 0.0, 1.5350000000000001, 0.0, 0.0, 1.01,
    0.265, 0.0, 0.0, 0.0, 0.0, 0.0, 1.17, 0.0, 2.085, 0.0, 0.0, 0.0, 0.185, 0.0,
    0.0 };

  static const signed char iv1[166] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 0, 0, 22, 23, 24, 25, 0, 0, 26, 27, 0, 0, 28,
    29, 0, 0, 0, 0, 0, 0, 30, 31, 32, 33, 34, 35, 36, 37, 0, 0, 38, 39, 0, 0, 40,
    41, 0, 0, 0, 0, 0, 0, 42, 43, 0, 0, 0, 0, 0, 0, 44, 45, 46, 47, 48, 49, 0, 0,
    50, 51, 52, 53, 0, 0, 0, 0, 54, 55, 0, 0, 56, 57, 58, 59, 0, 0, 0, 0, 0, 0,
    60, 61, 62, 63, 64, 65, 0, 0, 0, 0, 0, 0, 0, 0, 66, 67, 68, 69, 0, 0, 70, 71,
    0, 0, 0, 0, 0, 0, 72, 73, 0, 0, 0, 0, 74, 75, 76, 77, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 78, 79, 0, 0, 80, 81, 0, 0, 0, 0, 0, 0, 82, 83, 0, 0, 0, 0 };

  static const signed char iv[83] = { 2, 2, 3, 1, 3, 13, 13, 10, 3, 5, 0, 1, 8,
    0, 13, 0, 3, 0, 0, 0, 7, 2, 10, 1, 0, 11, 0, 7, 0, 0, 0, 5, 0, 0, 0, 5, 5, 3,
    0, 11, 5, 0, 0, 8, 0, 7, 10, 0, 0, 0, 1, 5, 7, 0, 0, 0, 0, 11, 2, 0, 5, 0, 0,
    0, 7, 0, 0, 8, 13, 0, 0, 0, 0, 0, 11, 0, 10, 0, 0, 0, 1, 0, 0 };

  static const boolean_T bv[83] = { false, false, false, false, false, false,
    false, false, false, false, true, false, false, true, false, true, false,
    true, true, true, false, false, false, false, true, false, true, false, true,
    true, true, false, true, true, true, false, false, false, true, false, false,
    true, true, false, true, false, false, true, true, true, false, false, false,
    true, true, true, true, false, false, true, false, true, true, true, false,
    true, true, false, false, true, true, true, true, true, false, true, false,
    true, true, true, false, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 83U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 83U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 166U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 83; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 166; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 83U * sizeof(boolean_T));
  obj_Prior[0] = 0.55990602975724357;
  obj_Prior[1] = 0.44009397024275648;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[69]
 *                const double obj_Children[138]
 *                const double obj_CutPoint[69]
 *                const boolean_T obj_NanCutPoints[69]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[138]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void m_CompactClassificationTree_pre(const double obj_CutPredictorIndex[69],
  const double obj_Children[138], const double obj_CutPoint[69], const boolean_T
  obj_NanCutPoints[69], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[138], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 69 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[99]
 *                double obj_Children[198]
 *                double obj_CutPoint[99]
 *                boolean_T obj_NanCutPoints[99]
 *                boolean_T obj_InfCutPoints[99]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[198]
 * Return Type  : void
 */
void n_CompactClassificationTree_Com(double obj_CutPredictorIndex[99], double
  obj_Children[198], double obj_CutPoint[99], boolean_T obj_NanCutPoints[99],
  boolean_T obj_InfCutPoints[99], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[198])
{
  static const double dv1[198] = { 0.5638214565387647, 0.8399014778325129,
    0.081720430107526887, 0.96263736263736266, 0.68347338935574231,
    0.92592592592592593, 0.029680365296803669, 0.97695852534562211,
    0.66666666666666652, 0.79999999999999993, 0.58333333333333337, 1.0,
    0.33333333333333337, 0.39999999999999997, 0.021028037383177586,
    0.97921478060046185, 0.0, 1.0, 0.0, 0.96, 0.3000000000000001,
    0.93333333333333335, 0.47619047619047622, 0.0, 1.0, 1.0, 0.0,
    0.38888888888888895, 0.0048780487804878083, 0.99518072289156623,
    0.611111111111111, 0.0, 1.0, 1.0, 0.12500000000000006, 0.8125, 1.0,
    0.36885245901639346, 1.0, 0.63636363636363646, 0.0, 0.0024509803921568644,
    0.5, 1.0, 0.95454545454545459, 0.8, 0.37499999999999994, 1.0, 0.0,
    0.92307692307692313, 0.33333333333333337, 0.76923076923076916,
    0.07142857142857148, 0.875, 0.0, 0.25, 0.0, 0.0, 1.0, 0.83333333333333326,
    1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.611111111111111,
    0.8529411764705882, 0.015151515151515162, 1.0, 0.0, 1.0, 0.0, 0.5, 1.0, 0.0,
    0.60000000000000009, 0.66666666666666674, 0.95652173913043481,
    0.63636363636363646, 0.11111111111111109, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0,
    1.0, 0.79999999999999993, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.4361785434612353,
    0.1600985221674871, 0.91827956989247317, 0.037362637362637376,
    0.31652661064425769, 0.074074074074074112, 0.97031963470319638,
    0.0230414746543779, 0.33333333333333337, 0.2, 0.41666666666666669, 0.0,
    0.66666666666666674, 0.6, 0.9789719626168224, 0.020785219399538122, 1.0, 0.0,
    1.0, 0.040000000000000029, 0.7, 0.066666666666666707, 0.52380952380952384,
    1.0, 0.0, 0.0, 1.0, 0.611111111111111, 0.99512195121951219,
    0.004819277108433738, 0.38888888888888895, 1.0, 0.0, 0.0,
    0.87499999999999989, 0.1875, 0.0, 0.63114754098360659, 0.0,
    0.36363636363636365, 1.0, 0.99754901960784315, 0.5, 0.0,
    0.045454545454545484, 0.19999999999999998, 0.625, 0.0, 1.0,
    0.076923076923076941, 0.66666666666666674, 0.23076923076923087,
    0.92857142857142849, 0.12499999999999999, 1.0, 0.74999999999999989, 1.0, 1.0,
    0.0, 0.16666666666666666, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0,
    0.38888888888888895, 0.14705882352941183, 0.98484848484848486, 0.0, 1.0, 0.0,
    1.0, 0.5, 0.0, 1.0, 0.4, 0.33333333333333337, 0.043478260869565237,
    0.36363636363636365, 0.88888888888888884, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0,
    0.0, 0.19999999999999998, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0 };

  static const double dv[99] = { 0.015, 1.0950000000000002, 0.28500000000000003,
    0.275, 1.585, 1.085, 0.035, 0.11, 0.92, 0.05, 1.2149999999999999, 0.0, 1.635,
    0.045, 0.055, 0.135, 0.0, 0.0, 0.0, 0.65, 0.05, 1.705, 2.1900000000000004,
    0.0, 0.0, 0.0, 0.0, 0.33999999999999997, 2.085, 0.045, 0.67999999999999994,
    0.0, 0.0, 0.0, 0.25, 0.2, 0.0, 0.10500000000000001, 0.0, 1.23, 0.0, 0.365,
    0.16, 0.0, 0.21000000000000002, 1.335, 1.35, 0.0, 0.0, 1.4500000000000002,
    0.56, 1.6749999999999998, 1.83, 0.455, 0.0, 0.26, 0.0, 0.0, 0.0,
    0.11000000000000001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.005,
    2.1399999999999997, 0.11499999999999999, 0.0, 0.0, 0.0, 0.0, 1.13, 0.0, 0.0,
    0.049999999999999996, 0.99, 1.045, 0.02, 1.08, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.17, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[198] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 0, 0, 24, 25, 26, 27, 28, 29, 30, 31,
    0, 0, 0, 0, 0, 0, 32, 33, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0, 0, 0, 0, 0, 40,
    41, 42, 43, 44, 45, 46, 47, 0, 0, 0, 0, 0, 0, 48, 49, 50, 51, 0, 0, 52, 53,
    0, 0, 54, 55, 0, 0, 56, 57, 58, 59, 0, 0, 60, 61, 62, 63, 64, 65, 0, 0, 0, 0,
    66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 0, 0, 76, 77, 0, 0, 0, 0, 0, 0, 78,
    79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80, 81, 82, 83, 84,
    85, 0, 0, 0, 0, 0, 0, 0, 0, 86, 87, 0, 0, 0, 0, 88, 89, 90, 91, 92, 93, 94,
    95, 96, 97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 99, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[99] = { 3, 7, 13, 1, 10, 7, 1, 4, 5, 2, 5, 0, 8, 2,
    2, 2, 0, 0, 0, 5, 1, 10, 10, 0, 0, 0, 0, 3, 10, 2, 13, 0, 0, 0, 11, 1, 0, 2,
    0, 11, 0, 10, 3, 0, 11, 5, 8, 0, 0, 8, 8, 10, 8, 13, 0, 3, 0, 0, 0, 13, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 9, 10, 2, 0, 0, 0, 0, 7, 0, 0, 1, 11, 11, 2, 13, 0, 0,
    0, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0 };

  static const boolean_T bv[99] = { false, false, false, false, false, false,
    false, false, false, false, false, true, false, false, false, false, true,
    true, true, false, false, false, false, true, true, true, true, false, false,
    false, false, true, true, true, false, false, true, false, true, false, true,
    false, false, true, false, false, false, true, true, false, false, false,
    false, false, true, false, true, true, true, false, true, true, true, true,
    true, true, true, true, true, false, false, false, true, true, true, true,
    false, true, true, false, false, false, false, false, true, true, true, true,
    true, true, true, true, false, true, true, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 99U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 99U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 198U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 99; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 198; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 99U * sizeof(boolean_T));
  obj_Prior[0] = 0.5638214565387627;
  obj_Prior[1] = 0.4361785434612373;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[71]
 *                const double obj_Children[142]
 *                const double obj_CutPoint[71]
 *                const boolean_T obj_NanCutPoints[71]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[142]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void n_CompactClassificationTree_pre(const double obj_CutPredictorIndex[71],
  const double obj_Children[142], const double obj_CutPoint[71], const boolean_T
  obj_NanCutPoints[71], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[142], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 71 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[81]
 *                double obj_Children[162]
 *                double obj_CutPoint[81]
 *                boolean_T obj_NanCutPoints[81]
 *                boolean_T obj_InfCutPoints[81]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[162]
 * Return Type  : void
 */
void o_CompactClassificationTree_Com(double obj_CutPredictorIndex[81], double
  obj_Children[162], double obj_CutPoint[81], boolean_T obj_NanCutPoints[81],
  boolean_T obj_InfCutPoints[81], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[162])
{
  static const double dv1[162] = { 0.57243539545810707, 0.839853300733497,
    0.095860566448801754, 0.91438979963570133, 0.68773234200743494,
    0.043879907621247126, 0.96153846153846156, 0.84140969162995594,
    0.96583850931677007, 0.93370165745856359, 0.18181818181818188, 0.5,
    0.024096385542168693, 1.0, 0.0, 0.92574257425742579, 0.16000000000000006,
    1.0, 0.38888888888888895, 0.97484276729559749, 0.63636363636363624, 1.0,
    0.14285714285714293, 0.875, 0.19999999999999998, 0.59999999999999987,
    0.017073170731707329, 0.99367088607594933, 0.68181818181818177, 1.0, 0.0,
    0.5, 0.0, 1.0, 0.94736842105263164, 1.0, 0.46666666666666667, 1.0,
    0.05263157894736846, 1.0, 0.0, 0.66666666666666674, 0.0, 1.0, 0.0, 0.4375,
    0.0, 1.0, 0.875, 1.0, 0.22222222222222224, 0.36363636363636365, 1.0, 1.0,
    0.78947368421052622, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.30769230769230765,
    1.0, 0.0, 0.5714285714285714, 0.0, 1.0, 0.0, 0.92307692307692313, 0.5, 1.0,
    0.0, 0.25, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.42756460454189288,
    0.160146699266503, 0.9041394335511983, 0.085610200364298727,
    0.31226765799256506, 0.95612009237875284, 0.038461538461538478,
    0.15859030837004406, 0.034161490683229837, 0.0662983425414365,
    0.81818181818181812, 0.5, 0.97590361445783136, 0.0, 1.0,
    0.074257425742574282, 0.83999999999999986, 0.0, 0.611111111111111,
    0.025157232704402534, 0.3636363636363637, 0.0, 0.8571428571428571,
    0.12499999999999999, 0.8, 0.39999999999999997, 0.98292682926829267,
    0.0063291139240506371, 0.31818181818181823, 0.0, 1.0, 0.5, 1.0, 0.0,
    0.05263157894736846, 0.0, 0.53333333333333333, 0.0, 0.94736842105263164, 0.0,
    1.0, 0.33333333333333337, 1.0, 0.0, 1.0, 0.5625, 1.0, 0.0,
    0.12499999999999999, 0.0, 0.77777777777777768, 0.63636363636363646, 0.0, 0.0,
    0.2105263157894737, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.69230769230769229,
    0.0, 1.0, 0.42857142857142855, 1.0, 0.0, 1.0, 0.076923076923076941, 0.5, 0.0,
    1.0, 0.74999999999999989, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0 };

  static const double dv[81] = { 0.08, 1.5950000000000002, 1.635, 0.595, 0.095,
    0.67999999999999994, 1.69, 0.16999999999999998, 0.20500000000000002, 0.065,
    0.105, 0.95, 0.70500000000000007, 0.0, 0.0, 0.060000000000000005, 0.3, 0.0,
    1.37, 0.015, 1.185, 0.0, 1.04, 0.6150000000000001, 0.44, 0.86, 0.375, 1.505,
    0.26, 0.0, 0.0, 0.98, 0.0, 0.0, 0.995, 0.0, 1.4300000000000002, 0.0,
    1.8599999999999999, 0.0, 0.0, 0.37, 0.0, 0.0, 0.0, 0.055, 0.0, 0.0, 0.28,
    0.0, 1.0150000000000001, 0.095, 0.0, 0.0, 1.435, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.105, 0.0, 0.0, 0.99, 0.0, 0.0, 0.0, 1.605, 0.005, 0.0, 0.0,
    0.575, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[162] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0, 28, 29,
    30, 31, 0, 0, 32, 33, 34, 35, 36, 37, 0, 0, 38, 39, 40, 41, 42, 43, 44, 45,
    46, 47, 48, 49, 50, 51, 0, 0, 0, 0, 52, 53, 0, 0, 0, 0, 54, 55, 0, 0, 56, 57,
    0, 0, 58, 59, 0, 0, 0, 0, 60, 61, 0, 0, 0, 0, 0, 0, 62, 63, 0, 0, 0, 0, 64,
    65, 0, 0, 66, 67, 68, 69, 0, 0, 0, 0, 70, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 72, 73, 0, 0, 0, 0, 74, 75, 0, 0, 0, 0, 0, 0, 76, 77, 78, 79, 0,
    0, 0, 0, 80, 81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[81] = { 3, 10, 8, 13, 2, 7, 7, 2, 1, 2, 1, 5, 8, 0,
    0, 2, 11, 0, 5, 1, 8, 0, 8, 11, 11, 12, 11, 10, 13, 0, 0, 11, 0, 0, 11, 0, 7,
    0, 8, 0, 0, 3, 0, 0, 0, 1, 0, 0, 13, 0, 7, 2, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0,
    7, 0, 0, 10, 0, 0, 0, 10, 12, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0 };

  static const boolean_T bv[81] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, false, false,
    true, false, false, false, true, false, false, false, false, false, false,
    false, true, true, false, true, true, false, true, false, true, false, true,
    true, false, true, true, true, false, true, true, false, true, false, false,
    true, true, false, true, true, true, true, true, true, true, false, true,
    true, false, true, true, true, false, false, true, true, false, true, true,
    true, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 81U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 81U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 162U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 81; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 162; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 81U * sizeof(boolean_T));
  obj_Prior[0] = 0.572435395458105;
  obj_Prior[1] = 0.42756460454189504;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[61]
 *                const double obj_Children[122]
 *                const double obj_CutPoint[61]
 *                const boolean_T obj_NanCutPoints[61]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[122]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void o_CompactClassificationTree_pre(const double obj_CutPredictorIndex[61],
  const double obj_Children[122], const double obj_CutPoint[61], const boolean_T
  obj_NanCutPoints[61], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[122], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 61 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[65]
 *                double obj_Children[130]
 *                double obj_CutPoint[65]
 *                boolean_T obj_NanCutPoints[65]
 *                boolean_T obj_InfCutPoints[65]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[130]
 * Return Type  : void
 */
void p_CompactClassificationTree_Com(double obj_CutPredictorIndex[65], double
  obj_Children[130], double obj_CutPoint[65], boolean_T obj_NanCutPoints[65],
  boolean_T obj_InfCutPoints[65], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[130])
{
  static const double dv1[130] = { 0.53484729835552181, 0.97250859106529208,
    0.16834532374100719, 0.98713235294117652, 0.763157894736842,
    0.85365853658536572, 0.0766721044045677, 0.99444444444444446, 0.0, 0.9, 0.25,
    0.55555555555555547, 1.0, 0.033868092691622116, 0.53846153846153844,
    0.9975669099756691, 0.98449612403100772, 1.0, 0.75, 0.14285714285714285, 1.0,
    0.5, 1.0, 0.030411449016100191, 1.0, 1.0, 0.20000000000000009,
    0.99583333333333335, 1.0, 0.96153846153846156, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0,
    0.25000000000000006, 0.59090909090909083, 0.0074487895716946056,
    0.076923076923076969, 1.0, 1.0, 0.98181818181818181, 0.0, 1.0, 0.0,
    0.5714285714285714, 0.0, 1.0, 0.13636363636363641, 0.0019417475728155356,
    0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0096153846153846229, 0.0,
    0.50000000000000011, 0.0, 1.0, 0.0, 0.46515270164447808,
    0.027491408934707917, 0.83165467625899281, 0.012867647058823539,
    0.23684210526315802, 0.14634146341463422, 0.92332789559543227,
    0.0055555555555555592, 1.0, 0.10000000000000005, 0.75, 0.44444444444444448,
    0.0, 0.966131907308378, 0.46153846153846156, 0.002433090024330902,
    0.015503875968992258, 0.0, 0.24999999999999994, 0.8571428571428571, 0.0, 0.5,
    0.0, 0.96958855098389984, 0.0, 0.0, 0.79999999999999993,
    0.0041666666666666692, 0.0, 0.038461538461538484, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.0, 0.74999999999999989, 0.40909090909090917, 0.99255121042830541,
    0.92307692307692313, 0.0, 0.0, 0.018181818181818195, 1.0, 0.0, 1.0,
    0.42857142857142849, 1.0, 0.0, 0.86363636363636354, 0.99805825242718449, 1.0,
    0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.99038461538461542, 1.0, 0.5, 1.0, 0.0,
    1.0 };

  static const double dv[65] = { 0.055, 0.035, 0.365, 0.27, 0.03, 1.07,
    1.6400000000000001, 0.875, 0.0, 1.19, 2.07, 0.255, 0.0, 1.4449999999999998,
    1.255, 0.015, 1.4449999999999998, 0.0, 1.1949999999999998, 1.755, 0.0, 0.135,
    0.0, 0.035, 0.0, 0.0, 1.355, 1.505, 0.0, 0.885, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.675, 1.03, 0.895, 1.865, 0.0, 0.0, 0.895, 0.0, 0.0, 0.0, 0.79, 0.0, 0.0,
    1.4649999999999999, 0.005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.07, 0.0,
    0.11, 0.0, 0.0, 0.0 };

  static const signed char iv1[130] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 0, 0, 24, 25, 26, 27, 28, 29,
    30, 31, 0, 0, 32, 33, 34, 35, 0, 0, 36, 37, 0, 0, 38, 39, 0, 0, 0, 0, 40, 41,
    42, 43, 0, 0, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46, 47, 48, 49, 50,
    51, 52, 53, 0, 0, 0, 0, 54, 55, 0, 0, 0, 0, 0, 0, 56, 57, 0, 0, 0, 0, 58, 59,
    60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 63, 0, 0, 64, 65,
    0, 0, 0, 0, 0, 0 };

  static const signed char iv[65] = { 2, 2, 11, 3, 3, 10, 8, 13, 0, 7, 10, 2, 0,
    11, 11, 1, 10, 0, 5, 8, 0, 13, 0, 1, 0, 0, 11, 10, 0, 13, 0, 0, 0, 0, 0, 0,
    13, 8, 8, 8, 0, 0, 11, 0, 0, 0, 7, 0, 0, 10, 3, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0,
    2, 0, 0, 0 };

  static const boolean_T bv[65] = { false, false, false, false, false, false,
    false, false, true, false, false, false, true, false, false, false, false,
    true, false, false, true, false, true, false, true, true, false, false, true,
    false, true, true, true, true, true, true, false, false, false, false, true,
    true, false, true, true, true, false, true, true, false, false, true, true,
    true, true, true, true, true, true, false, true, false, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 65U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 65U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 130U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 65; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 130; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 65U * sizeof(boolean_T));
  obj_Prior[0] = 0.53484729835552081;
  obj_Prior[1] = 0.46515270164447925;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[59]
 *                const double obj_Children[118]
 *                const double obj_CutPoint[59]
 *                const boolean_T obj_NanCutPoints[59]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[118]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void p_CompactClassificationTree_pre(const double obj_CutPredictorIndex[59],
  const double obj_Children[118], const double obj_CutPoint[59], const boolean_T
  obj_NanCutPoints[59], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[118], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 59 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[67]
 *                double obj_Children[134]
 *                double obj_CutPoint[67]
 *                boolean_T obj_NanCutPoints[67]
 *                boolean_T obj_InfCutPoints[67]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[134]
 * Return Type  : void
 */
void q_CompactClassificationTree_Com(double obj_CutPredictorIndex[67], double
  obj_Children[134], double obj_CutPoint[67], boolean_T obj_NanCutPoints[67],
  boolean_T obj_InfCutPoints[67], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[134])
{
  static const double dv1[134] = { 0.55520751761942222, 0.95979020979020979,
    0.2269503546099291, 0.97996357012750457, 0.47826086956521741,
    0.87777777777777766, 0.13170731707317074, 0.96802325581395354, 1.0, 1.0, 0.0,
    1.0, 0.74418604651162779, 0.68292682926829262, 0.092334494773519168,
    0.98516320474777452, 0.14285714285714285, 1.0, 0.0, 0.13333333333333336, 1.0,
    0.9, 0.031835205992509379, 0.99667774086378735, 0.88888888888888884, 0.5,
    0.0, 1.0, 0.0, 0.97142857142857142, 0.39999999999999997,
    0.017110266159695832, 1.0, 1.0, 0.9882352941176471, 1.0, 0.0, 0.0, 1.0, 1.0,
    0.0, 1.0, 0.0, 0.20512820512820523, 0.0020533880903490774,
    0.97368421052631582, 1.0, 0.071428571428571466, 0.54545454545454553,
    0.33333333333333337, 0.0, 1.0, 0.0, 1.0, 0.037037037037037056,
    0.8571428571428571, 0.0, 1.0, 0.0, 0.25, 0.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.0,
    0.44479248238057778, 0.040209790209790222, 0.77304964539007093,
    0.020036429872495459, 0.52173913043478259, 0.1222222222222223,
    0.86829268292682926, 0.031976744186046534, 0.0, 0.0, 1.0, 0.0,
    0.25581395348837221, 0.31707317073170738, 0.90766550522648082,
    0.014836795252225529, 0.8571428571428571, 0.0, 1.0, 0.86666666666666659, 0.0,
    0.10000000000000006, 0.96816479400749067, 0.0033222591362126268,
    0.11111111111111116, 0.5, 1.0, 0.0, 1.0, 0.028571428571428588,
    0.59999999999999987, 0.9828897338403042, 0.0, 0.0, 0.011764705882352948, 0.0,
    1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.79487179487179471, 0.997946611909651,
    0.026315789473684226, 0.0, 0.9285714285714286, 0.45454545454545459,
    0.66666666666666674, 1.0, 0.0, 1.0, 0.0, 0.962962962962963,
    0.14285714285714285, 1.0, 0.0, 1.0, 0.74999999999999989, 1.0, 0.0, 0.5, 1.0,
    0.0, 0.0, 1.0 };

  static const double dv[67] = { 0.065, 0.08, 0.335, 1.3250000000000002, 0.39,
    1.1150000000000002, 0.78, 0.13, 0.0, 0.0, 0.0, 0.0, 0.27, 1.355, 0.035,
    0.035, 0.655, 0.0, 0.0, 0.05, 0.0, 0.005, 1.815, 1.5, 1.115, 0.015, 0.0, 0.0,
    0.0, 0.31499999999999995, 1.1600000000000001, 0.075000000000000011, 0.0, 0.0,
    0.545, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.635, 0.02, 0.525, 0.0, 0.53,
    0.16, 0.735, 0.0, 0.0, 0.0, 0.0, 0.045, 0.95, 0.0, 0.0, 0.0,
    0.95500000000000007, 0.0, 0.0, 0.084999999999999992, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[134] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 0, 0, 0, 0, 0, 0, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 0, 0, 0, 0, 28, 29, 0, 0, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 0, 0,
    0, 0, 0, 0, 40, 41, 42, 43, 44, 45, 0, 0, 0, 0, 46, 47, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 48, 49, 50, 51, 52, 53, 0, 0, 54, 55, 56, 57, 58,
    59, 0, 0, 0, 0, 0, 0, 0, 0, 60, 61, 62, 63, 0, 0, 0, 0, 0, 0, 64, 65, 0, 0,
    0, 0, 66, 67, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[67] = { 1, 3, 13, 5, 11, 5, 5, 2, 0, 0, 0, 0, 11,
    10, 2, 1, 13, 0, 0, 2, 0, 6, 8, 10, 5, 1, 0, 0, 0, 3, 7, 2, 0, 0, 5, 0, 0, 0,
    0, 0, 0, 0, 0, 10, 11, 5, 0, 8, 1, 13, 0, 0, 0, 0, 2, 13, 0, 0, 0, 11, 0, 0,
    1, 0, 0, 0, 0 };

  static const boolean_T bv[67] = { false, false, false, false, false, false,
    false, false, true, true, true, true, false, false, false, false, false,
    true, true, false, true, false, false, false, false, false, true, true, true,
    false, false, false, true, true, false, true, true, true, true, true, true,
    true, true, false, false, false, true, false, false, false, true, true, true,
    true, false, false, true, true, true, false, true, true, false, true, true,
    true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 67U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 67U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 134U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 67; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 134; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 67U * sizeof(boolean_T));
  obj_Prior[0] = 0.55520751761942055;
  obj_Prior[1] = 0.4447924823805795;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[75]
 *                const double obj_Children[150]
 *                const double obj_CutPoint[75]
 *                const boolean_T obj_NanCutPoints[75]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[150]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void q_CompactClassificationTree_pre(const double obj_CutPredictorIndex[75],
  const double obj_Children[150], const double obj_CutPoint[75], const boolean_T
  obj_NanCutPoints[75], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[150], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 75 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[79]
 *                double obj_Children[158]
 *                double obj_CutPoint[79]
 *                boolean_T obj_NanCutPoints[79]
 *                boolean_T obj_InfCutPoints[79]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[158]
 * Return Type  : void
 */
void r_CompactClassificationTree_Com(double obj_CutPredictorIndex[79], double
  obj_Children[158], double obj_CutPoint[79], boolean_T obj_NanCutPoints[79],
  boolean_T obj_InfCutPoints[79], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[158])
{
  static const double dv1[158] = { 0.55442443226311833, 0.84250960307298361,
    0.10080645161290323, 0.97324414715719065, 0.41530054644808739,
    0.94444444444444442, 0.034782608695652188, 0.98511166253101734,
    0.94871794871794868, 0.91176470588235281, 0.12173913043478264, 1.0, 0.0, 0.5,
    0.022321428571428589, 1.0, 0.95862068965517244, 0.71428571428571419,
    0.95744680851063835, 1.0, 0.68421052631578949, 0.23636363636363644,
    0.016666666666666677, 1.0, 0.0, 0.21052631578947378, 0.0048780487804878083,
    0.61538461538461531, 0.99242424242424243, 0.0, 1.0, 0.96256684491978606, 0.0,
    0.9285714285714286, 0.0, 1.0, 0.17647058823529424, 1.0, 0.0,
    0.11764705882352947, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.97916666666666663, 1.0,
    0.9213483146067416, 0.0, 1.0, 1.0, 0.066666666666666707, 0.33333333333333331,
    0.040000000000000022, 0.91666666666666674, 1.0, 0.97222222222222221,
    0.70588235294117641, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.5,
    0.93333333333333335, 1.0, 0.44444444444444442, 1.0, 1.0, 0.0,
    0.86666666666666659, 1.0, 1.0, 0.0, 1.0, 0.0, 0.44557556773688162,
    0.15749039692701636, 0.89919354838709675, 0.026755852842809374,
    0.58469945355191255, 0.055555555555555587, 0.9652173913043478,
    0.014888337468982641, 0.051282051282051315, 0.08823529411764712,
    0.87826086956521732, 0.0, 1.0, 0.5, 0.9776785714285714, 0.0,
    0.04137931034482762, 0.2857142857142857, 0.042553191489361736, 0.0,
    0.31578947368421062, 0.76363636363636356, 0.98333333333333328, 0.0, 1.0,
    0.78947368421052622, 0.99512195121951219, 0.38461538461538458,
    0.0075757575757575812, 1.0, 0.0, 0.037433155080213935, 1.0,
    0.071428571428571438, 1.0, 0.0, 0.82352941176470573, 0.0, 1.0,
    0.88235294117647045, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.020833333333333346, 0.0,
    0.07865168539325848, 1.0, 0.0, 0.0, 0.93333333333333335, 0.66666666666666674,
    0.96, 0.083333333333333343, 0.0, 0.027777777777777797, 0.29411764705882354,
    1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.5, 0.066666666666666707, 0.0,
    0.55555555555555558, 0.0, 0.0, 1.0, 0.13333333333333336, 0.0, 0.0, 1.0, 0.0,
    1.0 };

  static const double dv[79] = { 0.015, 0.155, 0.26, 1.145, 1.15, 0.6, 0.035,
    1.0950000000000002, 1.14, 0.095, 0.255, 0.0, 0.0, 0.615,
    0.075000000000000011, 0.0, 0.985, 1.4500000000000002, 0.2, 0.0, 0.515, 0.31,
    0.26, 0.0, 0.0, 0.42, 2.085, 0.045000000000000005, 0.015, 0.0, 0.0,
    1.5950000000000002, 0.0, 0.615, 0.0, 0.0, 0.055000000000000007, 0.0, 0.0,
    0.62, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.005, 0.0, 0.084999999999999992, 0.0,
    0.0, 0.0, 1.835, 1.42, 1.755, 1.295, 0.0, 0.015, 1.7650000000000001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.2149999999999999, 1.55, 0.0, 1.145, 0.0, 0.0,
    0.0, 1.96, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[158] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 0, 0, 0, 0, 24, 25, 26, 27, 0, 0, 28,
    29, 30, 31, 32, 33, 0, 0, 34, 35, 36, 37, 38, 39, 0, 0, 0, 0, 40, 41, 42, 43,
    44, 45, 46, 47, 0, 0, 0, 0, 48, 49, 0, 0, 50, 51, 0, 0, 0, 0, 52, 53, 0, 0,
    0, 0, 54, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 57, 0, 0, 58, 59, 0, 0,
    0, 0, 0, 0, 60, 61, 62, 63, 64, 65, 66, 67, 0, 0, 68, 69, 70, 71, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 73, 74, 75, 0, 0, 76, 77, 0, 0, 0, 0, 0, 0,
    78, 79, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[79] = { 3, 1, 13, 7, 5, 11, 1, 5, 10, 2, 1, 0, 0,
    13, 2, 0, 8, 5, 2, 0, 13, 11, 11, 0, 0, 12, 10, 2, 1, 0, 0, 10, 0, 7, 0, 0,
    2, 0, 0, 13, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 5, 10, 8, 10, 0, 2, 8, 0, 0,
    0, 0, 0, 0, 0, 5, 7, 0, 8, 0, 0, 0, 10, 0, 0, 0, 0, 0 };

  static const boolean_T bv[79] = { false, false, false, false, false, false,
    false, false, false, false, false, true, true, false, false, true, false,
    false, false, true, false, false, false, true, true, false, false, false,
    false, true, true, false, true, false, true, true, false, true, true, false,
    true, true, true, true, true, true, false, true, false, true, true, true,
    false, false, false, false, true, false, false, true, true, true, true, true,
    true, true, false, false, true, false, true, true, true, false, true, true,
    true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 79U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 79U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 158U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 79; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 158; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 79U * sizeof(boolean_T));
  obj_Prior[0] = 0.55442443226311666;
  obj_Prior[1] = 0.44557556773688334;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : const double obj_CutPredictorIndex[89]
 *                const double obj_Children[178]
 *                const double obj_CutPoint[89]
 *                const boolean_T obj_NanCutPoints[89]
 *                const char obj_ClassNames[14]
 *                const int obj_ClassNamesLength[2]
 *                const double obj_Prior[2]
 *                const double obj_Cost[4]
 *                const double obj_ClassProbability[178]
 *                const emxArray_real_T *Xin
 *                emxArray_cell_wrap_0 *labels
 *                emxArray_real_T *scores
 * Return Type  : void
 */
void r_CompactClassificationTree_pre(const double obj_CutPredictorIndex[89],
  const double obj_Children[178], const double obj_CutPoint[89], const boolean_T
  obj_NanCutPoints[89], const char obj_ClassNames[14], const int
  obj_ClassNamesLength[2], const double obj_Prior[2], const double obj_Cost[4],
  const double obj_ClassProbability[178], const emxArray_real_T *Xin,
  emxArray_cell_wrap_0 *labels, emxArray_real_T *scores)
{
  cell_wrap_0 r1;
  cell_wrap_10 r;
  emxArray_cell_wrap_0 *labelTemp;
  emxArray_int8_T *node;
  emxArray_real_T *a__1;
  emxArray_real_T *rawScores;
  double d;
  int b_i;
  int boffset;
  int i;
  int j;
  int m;
  int numberOfObservations;
  boolean_T exitg1;
  if (Xin->size[0] == 0) {
    scores->size[0] = 0;
    scores->size[1] = 2;
    labels->size[0] = 0;
  } else {
    emxInit_int8_T(&node, 1);
    numberOfObservations = Xin->size[0];
    i = node->size[0];
    node->size[0] = Xin->size[0];
    emxEnsureCapacity_int8_T(node, i);
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      m = 0;
      exitg1 = false;
      while (!(exitg1 || (obj_CutPredictorIndex[m] == 0.0))) {
        d = Xin->data[boffset + Xin->size[0] * ((int)obj_CutPredictorIndex[m] -
          1)];
        if (rtIsNaN(d) || obj_NanCutPoints[m]) {
          exitg1 = true;
        } else if (d < obj_CutPoint[m]) {
          m = (int)obj_Children[m << 1] - 1;
        } else {
          m = (int)obj_Children[(m << 1) + 1] - 1;
        }
      }

      node->data[boffset] = (signed char)(m + 1);
    }

    emxInit_real_T(&rawScores, 2);
    i = rawScores->size[0] * rawScores->size[1];
    rawScores->size[0] = node->size[0];
    rawScores->size[1] = 2;
    emxEnsureCapacity_real_T(rawScores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      rawScores->data[i] = 0.0;
    }

    i = scores->size[0] * scores->size[1];
    scores->size[0] = node->size[0];
    scores->size[1] = 2;
    emxEnsureCapacity_real_T(scores, i);
    numberOfObservations = node->size[0] << 1;
    for (i = 0; i < numberOfObservations; i++) {
      scores->data[i] = 0.0;
    }

    numberOfObservations = node->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        rawScores->data[j + rawScores->size[0] * i] = obj_ClassProbability
          [(node->data[j] + 89 * i) - 1];
      }
    }

    for (i = 0; i < 7; i++) {
      r.f1[i] = obj_ClassNames[i << 1];
    }

    i = labels->size[0];
    labels->size[0] = node->size[0];
    emxEnsureCapacity_cell_wrap_0(labels, i);
    numberOfObservations = node->size[0];
    for (boffset = 0; boffset < numberOfObservations; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        labels->data[boffset].f1.data[i] = r.f1[i];
      }
    }

    emxInit_real_T(&a__1, 2);
    m = rawScores->size[0];
    i = a__1->size[0] * a__1->size[1];
    a__1->size[0] = rawScores->size[0];
    a__1->size[1] = 2;
    emxEnsureCapacity_real_T(a__1, i);
    for (j = 0; j < 2; j++) {
      numberOfObservations = j * m;
      boffset = j << 1;
      for (b_i = 0; b_i < m; b_i++) {
        i = rawScores->size[0] + b_i;
        a__1->data[numberOfObservations + b_i] = rawScores->data[b_i %
          rawScores->size[0] + rawScores->size[0] * (b_i / rawScores->size[0])] *
          obj_Cost[boffset] + rawScores->data[i % rawScores->size[0] +
          rawScores->size[0] * (i / rawScores->size[0])] * obj_Cost[boffset + 1];
      }
    }

    if ((obj_Prior[0] < obj_Prior[1]) || (rtIsNaN(obj_Prior[0]) && (!rtIsNaN
          (obj_Prior[1])))) {
      boffset = 1;
    } else {
      boffset = 0;
    }

    i = node->size[0];
    node->size[0] = rawScores->size[0];
    emxEnsureCapacity_int8_T(node, i);
    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      if (a__1->data[m] > a__1->data[m + a__1->size[0]]) {
        numberOfObservations = 2;
      } else {
        numberOfObservations = 1;
      }

      node->data[m] = (signed char)numberOfObservations;
    }

    emxFree_real_T(&a__1);
    numberOfObservations = obj_ClassNamesLength[boffset];
    r1.f1.size[1] = obj_ClassNamesLength[boffset];
    for (i = 0; i < numberOfObservations; i++) {
      r1.f1.data[i] = obj_ClassNames[boffset + (i << 1)];
    }

    emxInit_cell_wrap_0(&labelTemp, 1);
    i = labelTemp->size[0];
    labelTemp->size[0] = rawScores->size[0];
    emxEnsureCapacity_cell_wrap_0(labelTemp, i);
    i = rawScores->size[0] - 1;
    for (boffset = 0; boffset <= i; boffset++) {
      labelTemp->data[boffset].f1.size[0] = 1;
      numberOfObservations = r1.f1.size[1];
      labelTemp->data[boffset].f1.size[1] = r1.f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[boffset].f1.data[j] = r1.f1.data[j];
      }
    }

    i = rawScores->size[0] - 1;
    for (m = 0; m <= i; m++) {
      numberOfObservations = obj_ClassNamesLength[node->data[m] - 1];
      labelTemp->data[m].f1.size[0] = 1;
      labelTemp->data[m].f1.size[1] = numberOfObservations;
      for (j = 0; j < numberOfObservations; j++) {
        labelTemp->data[m].f1.data[j] = obj_ClassNames[(node->data[m] + (j << 1))
          - 1];
      }
    }

    emxFree_int8_T(&node);
    numberOfObservations = rawScores->size[0];
    for (i = 0; i < 2; i++) {
      for (j = 0; j < numberOfObservations; j++) {
        scores->data[j + scores->size[0] * i] = rawScores->data[j +
          rawScores->size[0] * i];
      }
    }

    emxFree_real_T(&rawScores);
    i = labelTemp->size[0];
    for (boffset = 0; boffset < i; boffset++) {
      labels->data[boffset].f1.size[0] = 1;
      labels->data[boffset].f1.size[1] = labelTemp->data[boffset].f1.size[1];
      numberOfObservations = labelTemp->data[boffset].f1.size[1];
      for (j = 0; j < numberOfObservations; j++) {
        labels->data[boffset].f1.data[j] = labelTemp->data[boffset].f1.data[j];
      }
    }

    emxFree_cell_wrap_0(&labelTemp);
  }
}

/*
 * Arguments    : double obj_CutPredictorIndex[93]
 *                double obj_Children[186]
 *                double obj_CutPoint[93]
 *                boolean_T obj_NanCutPoints[93]
 *                boolean_T obj_InfCutPoints[93]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[186]
 * Return Type  : void
 */
void s_CompactClassificationTree_Com(double obj_CutPredictorIndex[93], double
  obj_Children[186], double obj_CutPoint[93], boolean_T obj_NanCutPoints[93],
  boolean_T obj_InfCutPoints[93], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[186])
{
  static const double dv1[186] = { 0.55442443226311833, 0.82545454545454611,
    0.059734513274336293, 0.9, 0.68421052631578938, 0.039080459770114956,
    0.58823529411764708, 0.82170542635658916, 0.97163120567375882,
    0.98795180722891562, 0.26050420168067229, 0.72727272727272718,
    0.00242130750605327, 1.0, 0.0, 0.87671232876712335, 0.51282051282051277,
    0.98098859315589348, 0.84210526315789469, 0.93333333333333335, 1.0,
    0.16504854368932043, 0.875, 1.0, 0.25, 0.19999999999999998, 0.0,
    0.96132596685082872, 0.47368421052631582, 0.95000000000000007,
    0.052631578947368439, 0.995, 0.93650793650793651, 1.0, 0.0, 1.0,
    0.71428571428571419, 1.0, 0.094736842105263216, 0.81818181818181812, 1.0,
    0.66666666666666674, 0.0, 1.0, 0.0, 0.91666666666666663, 1.0,
    0.91666666666666674, 0.26923076923076933, 1.0, 0.66666666666666674, 0.0, 1.0,
    1.0, 0.97674418604651159, 0.75000000000000011, 0.96363636363636362, 1.0, 0.0,
    1.0, 0.022727272727272742, 0.66666666666666674, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0,
    1.0, 1.0, 0.17391304347826092, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.92592592592592593, 1.0, 1.0, 0.011494252873563225, 1.0, 0.0, 1.0, 0.0, 1.0,
    0.71428571428571419, 0.0, 0.33333333333333337, 1.0, 0.0, 0.0, 1.0,
    0.44557556773688162, 0.17454545454545392, 0.94026548672566368, 0.1,
    0.31578947368421051, 0.960919540229885, 0.411764705882353,
    0.17829457364341086, 0.028368794326241158, 0.012048192771084345,
    0.73949579831932766, 0.27272727272727282, 0.99757869249394671, 0.0, 1.0,
    0.12328767123287673, 0.48717948717948717, 0.019011406844106477,
    0.15789473684210528, 0.066666666666666707, 0.0, 0.83495145631067946,
    0.12500000000000003, 0.0, 0.75000000000000011, 0.79999999999999993, 1.0,
    0.0386740331491713, 0.52631578947368418, 0.050000000000000017,
    0.94736842105263164, 0.0050000000000000036, 0.06349206349206353, 0.0, 1.0,
    0.0, 0.2857142857142857, 0.0, 0.90526315789473666, 0.1818181818181818, 0.0,
    0.33333333333333337, 1.0, 0.0, 1.0, 0.0833333333333334, 0.0,
    0.083333333333333343, 0.73076923076923062, 0.0, 0.33333333333333337, 1.0,
    0.0, 0.0, 0.023255813953488386, 0.25, 0.03636363636363639, 0.0, 1.0, 0.0,
    0.97727272727272729, 0.33333333333333337, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.0, 0.826086956521739, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.074074074074074112,
    0.0, 0.0, 0.9885057471264368, 0.0, 1.0, 0.0, 1.0, 0.0, 0.2857142857142857,
    1.0, 0.66666666666666674, 0.0, 1.0, 1.0, 0.0 };

  static const double dv[93] = { 0.08, 1.585, 1.63, 1.2650000000000001,
    0.075000000000000011, 0.195, 1.2349999999999999, 1.225, 0.245, 1.625, 1.81,
    0.14, 0.02, 0.0, 0.0, 0.035, 1.31, 1.505, 1.075, 0.075, 0.0, 0.075, 0.005,
    0.0, 0.375, 0.14500000000000002, 0.0, 0.945, 0.20500000000000002, 0.81,
    0.655, 1.04, 0.56, 0.0, 0.0, 0.0, 1.085, 0.0, 0.51, 1.2349999999999999, 0.0,
    0.12, 0.0, 0.0, 0.0, 0.12000000000000001, 0.0, 0.275, 0.05, 0.0, 0.005, 0.0,
    0.0, 0.0, 1.0550000000000002, 0.97500000000000009, 1.545, 0.0, 0.0, 0.0,
    1.085, 0.21, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.35, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.505, 0.0, 0.0, 2.09, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0,
    1.85, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[186] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 0, 0, 28, 29,
    30, 31, 32, 33, 34, 35, 36, 37, 0, 0, 38, 39, 40, 41, 0, 0, 42, 43, 44, 45,
    0, 0, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 0, 0, 0, 0, 0, 0, 58,
    59, 0, 0, 60, 61, 62, 63, 0, 0, 64, 65, 0, 0, 0, 0, 0, 0, 66, 67, 0, 0, 68,
    69, 70, 71, 0, 0, 72, 73, 0, 0, 0, 0, 0, 0, 74, 75, 76, 77, 78, 79, 0, 0, 0,
    0, 0, 0, 80, 81, 82, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 84,
    85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 86, 87, 0, 0, 0, 0, 88, 89, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 90, 91, 0, 0, 92, 93, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[93] = { 3, 10, 8, 10, 2, 11, 11, 10, 1, 10, 5, 13,
    2, 0, 0, 1, 7, 10, 7, 1, 0, 1, 9, 0, 3, 1, 0, 10, 13, 13, 13, 11, 13, 0, 0,
    0, 5, 0, 11, 13, 0, 3, 0, 0, 0, 2, 0, 7, 2, 0, 9, 0, 0, 0, 11, 8, 10, 0, 0,
    0, 5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 8, 0, 0, 10, 0, 0, 0,
    0, 0, 1, 0, 8, 0, 0, 0, 0 };

  static const boolean_T bv[93] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, true, true, false, false,
    false, false, false, true, false, false, true, false, false, true, false,
    false, false, false, false, false, true, true, true, false, true, false,
    false, true, false, true, true, true, false, true, false, false, true, false,
    true, true, true, false, false, false, true, true, true, false, false, true,
    true, true, true, true, true, true, true, false, true, true, true, true,
    true, true, false, true, true, false, true, true, true, true, true, false,
    true, false, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 93U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 93U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 186U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 93; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 186; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 93U * sizeof(boolean_T));
  obj_Prior[0] = 0.55442443226311666;
  obj_Prior[1] = 0.44557556773688334;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[91]
 *                double obj_Children[182]
 *                double obj_CutPoint[91]
 *                boolean_T obj_NanCutPoints[91]
 *                boolean_T obj_InfCutPoints[91]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[182]
 * Return Type  : void
 */
void t_CompactClassificationTree_Com(double obj_CutPredictorIndex[91], double
  obj_Children[182], double obj_CutPoint[91], boolean_T obj_NanCutPoints[91],
  boolean_T obj_InfCutPoints[91], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[182])
{
  static const double dv1[182] = { 0.567736883320284, 0.83715319662243737,
    0.069196428571428575, 0.91732283464566933, 0.71028037383177567,
    0.79999999999999982, 0.00726392251815981, 0.928, 0.25, 0.97409326424870468,
    0.3125, 0.96153846153846156, 0.33333333333333331, 0.037974683544303819, 0.0,
    0.96234309623430958, 0.896551724137931, 1.0, 0.14285714285714285,
    0.99431818181818177, 0.76470588235294112, 0.92, 0.16504854368932043, 1.0,
    0.0, 0.0, 0.59999999999999987, 0.74999999999999989, 0.0, 0.98706896551724144,
    0.14285714285714285, 0.98095238095238091, 0.54901960784313719, 1.0, 0.0,
    0.94736842105263164, 1.0, 0.5, 1.0, 1.0, 0.0, 1.0, 0.085106382978723472, 1.0,
    0.0, 0.0, 1.0, 1.0, 0.95238095238095244, 1.0, 0.0, 0.25, 0.99514563106796117,
    0.33333333333333343, 0.85714285714285721, 1.0, 0.74999999999999989, 1.0, 0.0,
    0.022727272727272742, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    0.25925925925925936, 0.9, 0.0, 0.0, 1.0, 0.15384615384615385, 0.0, 0.0,
    0.411764705882353, 0.94736842105263164, 0.0, 0.0, 1.0, 1.0,
    0.090909090909090912, 1.0, 0.79999999999999993, 0.25, 0.0, 0.0, 1.0, 0.0,
    1.0, 0.43226311667971606, 0.16284680337756255, 0.9308035714285714,
    0.082677165354330714, 0.28971962616822428, 0.20000000000000009,
    0.99273607748184023, 0.072000000000000008, 0.75000000000000011,
    0.025906735751295356, 0.6875, 0.038461538461538478, 0.66666666666666674,
    0.96202531645569622, 1.0, 0.037656903765690405, 0.10344827586206899, 0.0,
    0.8571428571428571, 0.0056818181818181854, 0.23529411764705885,
    0.080000000000000043, 0.83495145631067946, 0.0, 1.0, 1.0,
    0.39999999999999997, 0.25, 1.0, 0.012931034482758627, 0.8571428571428571,
    0.01904761904761906, 0.45098039215686275, 0.0, 1.0, 0.052631578947368439,
    0.0, 0.5, 0.0, 0.0, 1.0, 0.0, 0.91489361702127658, 0.0, 1.0, 1.0, 0.0, 0.0,
    0.047619047619047644, 0.0, 1.0, 0.74999999999999989, 0.004854368932038838,
    0.66666666666666652, 0.1428571428571429, 0.0, 0.25, 0.0, 1.0,
    0.97727272727272729, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.74074074074074059, 0.10000000000000003, 1.0, 1.0, 0.0, 0.84615384615384615,
    1.0, 1.0, 0.58823529411764708, 0.052631578947368439, 1.0, 1.0, 0.0, 0.0,
    0.90909090909090917, 0.0, 0.19999999999999998, 0.74999999999999989, 1.0, 1.0,
    0.0, 1.0, 0.0 };

  static const double dv[91] = { 0.08, 1.565, 0.305, 0.015, 0.155, 0.38,
    0.10500000000000001, 0.895, 0.060000000000000005, 0.095,
    0.075000000000000011, 1.165, 1.425, 0.055, 0.0, 0.315, 0.035, 0.0, 0.345,
    1.605, 1.7650000000000001, 1.495, 0.49, 0.0, 0.0, 0.0, 1.205,
    1.4449999999999998, 0.0, 0.805, 0.18, 0.95, 1.255, 0.0, 0.0, 0.035, 0.0,
    1.46, 0.0, 0.0, 0.0, 0.0, 1.3450000000000002, 0.0, 0.0, 0.0, 0.0, 0.0, 0.11,
    0.0, 0.0, 1.0150000000000001, 0.905, 0.47000000000000003, 0.855, 0.0, 1.525,
    0.0, 0.0, 0.185, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.12, 1.245, 0.0,
    0.0, 0.0, 0.16999999999999998, 0.0, 0.0, 0.055000000000000007,
    1.2650000000000001, 0.0, 0.0, 0.0, 0.0, 0.135, 0.0, 1.1749999999999998, 0.13,
    0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[182] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0, 0, 30, 31,
    32, 33, 0, 0, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 0, 0, 0, 0, 0, 0, 44,
    45, 46, 47, 0, 0, 48, 49, 50, 51, 52, 53, 54, 55, 0, 0, 0, 0, 56, 57, 0, 0,
    58, 59, 0, 0, 0, 0, 0, 0, 0, 0, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 63,
    0, 0, 0, 0, 64, 65, 66, 67, 68, 69, 70, 71, 0, 0, 72, 73, 0, 0, 0, 0, 74, 75,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76, 77, 78, 79, 0, 0, 0, 0,
    0, 0, 80, 81, 0, 0, 0, 0, 82, 83, 84, 85, 0, 0, 0, 0, 0, 0, 0, 0, 86, 87, 0,
    0, 88, 89, 90, 91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[91] = { 3, 10, 11, 3, 1, 3, 1, 7, 1, 2, 2, 7, 5, 2,
    0, 1, 1, 0, 11, 10, 8, 8, 11, 0, 0, 0, 7, 8, 0, 11, 2, 10, 10, 0, 0, 2, 0, 8,
    0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 2, 0, 0, 7, 7, 10, 13, 0, 5, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 8, 7, 0, 0, 0, 1, 0, 0, 2, 8, 0, 0, 0, 0, 1, 0, 7, 2, 0, 0, 0,
    0, 0 };

  static const boolean_T bv[91] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, false, false,
    true, false, false, false, false, false, true, true, true, false, false,
    true, false, false, false, false, true, true, false, true, false, true, true,
    true, true, false, true, true, true, true, true, false, true, true, false,
    false, false, false, true, false, true, true, false, true, true, true, true,
    true, true, true, true, false, false, true, true, true, false, true, true,
    false, false, true, true, true, true, false, true, false, false, true, true,
    true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 91U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 91U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 182U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 91; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 182; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 91U * sizeof(boolean_T));
  obj_Prior[0] = 0.56773688332028194;
  obj_Prior[1] = 0.43226311667971806;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[69]
 *                double obj_Children[138]
 *                double obj_CutPoint[69]
 *                boolean_T obj_NanCutPoints[69]
 *                boolean_T obj_InfCutPoints[69]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[138]
 * Return Type  : void
 */
void u_CompactClassificationTree_Com(double obj_CutPredictorIndex[69], double
  obj_Children[138], double obj_CutPoint[69], boolean_T obj_NanCutPoints[69],
  boolean_T obj_InfCutPoints[69], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[138])
{
  static const double dv1[138] = { 0.55833985904463768, 0.97545008183306059,
    0.17567567567567566, 0.98888888888888893, 0.93788819875776386,
    0.85294117647058809, 0.098662207357859535, 0.99548532731376971,
    0.5714285714285714, 0.99315068493150682, 0.4, 0.30769230769230765,
    0.98181818181818181, 0.072289156626506035, 1.0, 0.987012987012987, 1.0, 1.0,
    0.39999999999999997, 1.0, 0.96, 0.099999999999999992, 1.0, 0.0, 1.0, 1.0,
    0.875, 0.24375, 0.0071258907363420465, 1.0, 0.75000000000000011, 0.0, 1.0,
    0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.75555555555555542, 0.043478260869565251,
    0.2857142857142857, 0.0024154589371980693, 0.0, 1.0, 0.0,
    0.82926829268292668, 1.0, 0.01785714285714287, 0.66666666666666674, 0.0, 0.0,
    0.5, 0.66666666666666663, 0.95652173913043481, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
    0.45454545454545459, 1.0, 0.5, 1.0, 0.0, 1.0, 1.0, 0.0, 0.44166014095536238,
    0.024549918166939456, 0.82432432432432423, 0.011111111111111118,
    0.062111801242236066, 0.14705882352941185, 0.90133779264214053,
    0.0045146726862302514, 0.42857142857142855, 0.0068493150684931555,
    0.60000000000000009, 0.69230769230769229, 0.018181818181818195,
    0.927710843373494, 0.0, 0.012987012987012997, 0.0, 0.0, 0.59999999999999987,
    0.0, 0.040000000000000022, 0.90000000000000013, 0.0, 1.0, 0.0, 0.0,
    0.12499999999999999, 0.75625, 0.99287410926365793, 0.0, 0.25, 1.0, 0.0, 1.0,
    0.0, 0.0, 1.0, 0.0, 1.0, 0.24444444444444455, 0.95652173913043481,
    0.71428571428571419, 0.99758454106280192, 1.0, 0.0, 1.0, 0.17073170731707327,
    0.0, 0.9821428571428571, 0.33333333333333337, 1.0, 1.0, 0.5,
    0.33333333333333337, 0.043478260869565237, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.54545454545454553, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 1.0 };

  static const double dv[69] = { 0.055, 1.2149999999999999, 0.365, 0.27,
    0.084999999999999992, 1.165, 1.815, 0.92, 0.82000000000000006,
    2.0949999999999998, 1.375, 0.22, 0.27, 0.01, 0.0, 0.905, 0.0, 0.0,
    1.3399999999999999, 0.0, 1.745, 0.6399999999999999, 0.0, 0.0, 0.0, 0.0, 1.32,
    0.125, 0.02, 0.0, 0.075000000000000011, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.56, 0.21, 0.425, 2.085, 0.0, 0.0, 0.0, 0.905, 0.0, 0.84,
    1.3599999999999999, 0.0, 0.0, 1.71, 1.045, 0.065, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.075, 0.0, 1.02, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[138] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0, 0, 30, 31,
    0, 0, 0, 0, 32, 33, 0, 0, 34, 35, 36, 37, 0, 0, 0, 0, 0, 0, 0, 0, 38, 39, 40,
    41, 42, 43, 0, 0, 44, 45, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 46,
    47, 48, 49, 50, 51, 52, 53, 0, 0, 0, 0, 0, 0, 54, 55, 0, 0, 56, 57, 58, 59,
    0, 0, 0, 0, 60, 61, 62, 63, 64, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 66,
    67, 0, 0, 68, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[69] = { 2, 7, 13, 3, 1, 10, 8, 8, 5, 10, 7, 3, 13,
    3, 0, 8, 0, 0, 5, 0, 8, 13, 0, 0, 0, 0, 5, 1, 11, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 11, 11, 10, 10, 0, 0, 0, 11, 0, 5, 5, 0, 0, 7, 8, 2, 0, 0, 0, 0, 0, 0, 1,
    0, 5, 0, 0, 0, 0, 0 };

  static const boolean_T bv[69] = { false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, true, false, true,
    true, false, true, false, false, true, true, true, true, false, false, false,
    true, false, true, true, true, true, true, true, true, true, false, false,
    false, false, true, true, true, false, true, false, false, true, true, false,
    false, false, true, true, true, true, true, true, false, true, false, true,
    true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 69U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 69U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 138U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 69; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 138; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 69U * sizeof(boolean_T));
  obj_Prior[0] = 0.5583398590446359;
  obj_Prior[1] = 0.44166014095536416;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[71]
 *                double obj_Children[142]
 *                double obj_CutPoint[71]
 *                boolean_T obj_NanCutPoints[71]
 *                boolean_T obj_InfCutPoints[71]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[142]
 * Return Type  : void
 */
void v_CompactClassificationTree_Com(double obj_CutPredictorIndex[71], double
  obj_Children[142], double obj_CutPoint[71], boolean_T obj_NanCutPoints[71],
  boolean_T obj_InfCutPoints[71], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[142])
{
  static const double dv1[142] = { 0.57635082223962641, 0.975767366720517,
    0.20060790273556228, 0.98854337152209493, 0.0, 0.96666666666666667,
    0.12374581939799331, 0.99336650082918743, 0.625, 0.0, 0.98305084745762716,
    0.0824561403508772, 0.9642857142857143, 0.9971830985915493,
    0.98790322580645162, 0.25, 1.0, 1.0, 0.74999999999999989,
    0.26829268292682928, 0.0073891625615763587, 1.0, 0.0, 0.99561403508771928,
    1.0, 0.99591836734693873, 0.33333333333333337, 1.0, 0.0, 1.0, 0.0,
    0.46153846153846156, 0.093023255813953556, 0.42857142857142855, 0.0, 1.0,
    0.97826086956521741, 1.0, 0.984375, 0.0, 1.0, 0.66666666666666663,
    0.31111111111111117, 1.0, 0.012658227848101274, 0.0, 0.74999999999999989,
    0.66666666666666674, 1.0, 0.88888888888888884, 1.0, 1.0, 0.47619047619047622,
    0.0882352941176471, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0,
    0.90909090909090917, 0.031250000000000014, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.42364917776037359, 0.024232633279483048, 0.79939209726443761,
    0.011456628477905084, 1.0, 0.033333333333333354, 0.87625418060200666,
    0.0066334991708126081, 0.37499999999999994, 1.0, 0.016949152542372892,
    0.91754385964912277, 0.035714285714285733, 0.0028169014084507061,
    0.012096774193548394, 0.74999999999999989, 0.0, 0.0, 0.25,
    0.73170731707317072, 0.9926108374384236, 0.0, 1.0, 0.004385964912280705, 0.0,
    0.0040816326530612275, 0.66666666666666674, 0.0, 1.0, 0.0, 1.0,
    0.53846153846153844, 0.90697674418604646, 0.5714285714285714, 1.0, 0.0,
    0.021739130434782622, 0.0, 0.01562500000000001, 1.0, 0.0,
    0.33333333333333343, 0.68888888888888877, 0.0, 0.98734177215189878, 1.0,
    0.25, 0.33333333333333337, 0.0, 0.11111111111111109, 0.0, 0.0,
    0.52380952380952384, 0.91176470588235292, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.0, 1.0, 1.0, 0.090909090909090912, 0.96875, 0.0, 0.0, 1.0, 1.0, 0.0 };

  static const double dv[71] = { 0.055, 0.355, 0.265, 0.11499999999999999, 0.0,
    0.28500000000000003, 2.05, 1.2349999999999999, 1.255, 0.0, 0.245, 0.005,
    1.8450000000000002, 0.015, 0.045, 0.885, 0.0, 0.0, 0.99500000000000011,
    1.5950000000000002, 0.02, 0.0, 0.0, 1.0950000000000002, 0.0, 0.015, 1.125,
    0.0, 0.0, 0.0, 0.0, 1.0950000000000002, 1.065, 0.60000000000000009, 0.0, 0.0,
    1.105, 0.0, 0.005, 0.0, 0.0, 0.655, 1.185, 0.0, 0.125, 0.0, 0.6, 0.305, 0.0,
    0.825, 0.0, 0.0, 1.245, 0.005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.305, 0.31, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const signed char iv1[142] = { 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 10, 11, 12,
    13, 14, 15, 16, 17, 0, 0, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0,
    0, 0, 0, 30, 31, 32, 33, 34, 35, 0, 0, 0, 0, 36, 37, 0, 0, 38, 39, 40, 41, 0,
    0, 0, 0, 0, 0, 0, 0, 42, 43, 44, 45, 46, 47, 0, 0, 0, 0, 48, 49, 0, 0, 50,
    51, 0, 0, 0, 0, 52, 53, 54, 55, 0, 0, 56, 57, 0, 0, 58, 59, 60, 61, 0, 0, 62,
    63, 0, 0, 0, 0, 64, 65, 66, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 68, 69, 70, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[71] = { 2, 3, 13, 3, 0, 10, 10, 8, 8, 0, 11, 3, 7,
    2, 2, 8, 0, 0, 7, 10, 11, 0, 0, 7, 0, 1, 13, 0, 0, 0, 0, 7, 8, 7, 0, 0, 7, 0,
    2, 0, 0, 13, 11, 0, 1, 0, 10, 13, 0, 13, 0, 0, 10, 9, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 2, 0, 0, 0, 0, 0 };

  static const boolean_T bv[71] = { false, false, false, false, true, false,
    false, false, false, true, false, false, false, false, false, false, true,
    true, false, false, false, true, true, false, true, false, false, true, true,
    true, true, false, false, false, true, true, false, true, false, true, true,
    false, false, true, false, true, false, false, true, false, true, true,
    false, false, true, true, true, true, true, true, true, true, true, true,
    false, false, true, true, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 71U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 71U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 142U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 71; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 142; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 71U * sizeof(boolean_T));
  obj_Prior[0] = 0.57635082223962408;
  obj_Prior[1] = 0.42364917776037586;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[77]
 *                double obj_Children[154]
 *                double obj_CutPoint[77]
 *                boolean_T obj_NanCutPoints[77]
 *                boolean_T obj_InfCutPoints[77]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[154]
 * Return Type  : void
 */
void w_CompactClassificationTree_Com(double obj_CutPredictorIndex[77], double
  obj_Children[154], double obj_CutPoint[77], boolean_T obj_NanCutPoints[77],
  boolean_T obj_InfCutPoints[77], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[154])
{
  static const double dv1[154] = { 0.55912294440094146, 0.9737274220032841,
    0.18113772455089819, 0.989492119089317, 0.73684210526315774,
    0.89189189189189177, 0.0925925925925926, 0.96938775510204078,
    0.9936575052854123, 0.0, 0.87499999999999989, 0.94202898550724634,
    0.19999999999999998, 0.076256499133448882, 0.6470588235294118, 1.0, 0.5, 1.0,
    0.99224806201550386, 1.0, 0.0, 0.69230769230769229, 1.0, 1.0, 0.0,
    0.070052539404553416, 0.66666666666666674, 1.0, 0.0, 1.0, 0.25,
    0.95833333333333337, 0.99705014749262533, 1.0, 0.5, 0.71874999999999989,
    0.031539888682745841, 1.0, 0.0, 0.0, 1.0, 1.0, 0.33333333333333337, 1.0,
    0.98305084745762716, 0.0, 0.79999999999999993, 0.33333333333333331,
    0.95000000000000007, 0.3243243243243244, 0.0099601593625498076, 0.0, 1.0,
    0.962962962962963, 1.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.92307692307692313,
    0.0, 0.0040080160320641314, 1.0, 0.0, 1.0, 1.0, 0.0, 0.33333333333333337,
    0.0020161290322580658, 1.0, 0.0, 0.035714285714285733, 0.0, 1.0, 0.0,
    0.44087705559905843, 0.026272577996715941, 0.81886227544910173,
    0.010507880910683021, 0.2631578947368422, 0.10810810810810818,
    0.90740740740740744, 0.0306122448979592, 0.0063424947145877411, 1.0,
    0.12500000000000006, 0.057971014492753666, 0.79999999999999993,
    0.9237435008665511, 0.35294117647058826, 0.0, 0.5, 0.0,
    0.0077519379844961283, 0.0, 1.0, 0.30769230769230765, 0.0, 0.0, 1.0,
    0.92994746059544664, 0.33333333333333337, 0.0, 1.0, 0.0, 0.74999999999999989,
    0.041666666666666692, 0.002949852507374633, 0.0, 0.5, 0.28125000000000011,
    0.96846011131725418, 0.0, 1.0, 1.0, 0.0, 0.0, 0.66666666666666674, 0.0,
    0.016949152542372892, 1.0, 0.19999999999999998, 0.66666666666666674,
    0.050000000000000017, 0.67567567567567555, 0.99003984063745021, 1.0, 0.0,
    0.037037037037037056, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0,
    0.076923076923076941, 1.0, 0.99599198396793587, 0.0, 1.0, 0.0, 0.0, 1.0,
    0.66666666666666674, 0.99798387096774188, 0.0, 1.0, 0.9642857142857143, 1.0,
    0.0, 1.0 };

  static const double dv[77] = { 0.055, 0.195, 0.345, 0.415, 0.015,
    0.33999999999999997, 1.165, 0.035, 0.005, 0.0, 1.38, 1.125, 1.06, 1.815,
    0.16999999999999998, 0.0, 1.17, 0.0, 0.525, 0.0, 0.0, 0.905, 0.0, 0.0, 0.0,
    0.035, 1.7149999999999999, 0.0, 0.0, 0.0, 1.2349999999999999, 1.47, 1.525,
    0.0, 0.084999999999999992, 1.055, 0.075000000000000011, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.74, 0.0, 2.1550000000000002, 0.0, 1.7000000000000002, 1.05, 0.145,
    1.105, 1.8050000000000002, 0.0, 0.0, 1.5350000000000001, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.46499999999999997, 0.0, 0.12000000000000001, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.7, 0.095, 0.0, 0.0, 0.75, 0.0, 0.0, 0.0 };

  static const signed char iv1[154] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0, 0,
    30, 31, 0, 0, 32, 33, 0, 0, 0, 0, 34, 35, 0, 0, 0, 0, 0, 0, 36, 37, 38, 39,
    0, 0, 0, 0, 0, 0, 40, 41, 42, 43, 44, 45, 0, 0, 46, 47, 48, 49, 50, 51, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 52, 53, 0, 0, 54, 55, 0, 0, 56, 57, 58, 59, 60, 61,
    62, 63, 64, 65, 0, 0, 0, 0, 66, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    68, 69, 0, 0, 70, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 72, 73, 74, 75, 0, 0, 0,
    0, 76, 77, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[77] = { 2, 1, 13, 11, 2, 11, 13, 2, 1, 0, 5, 10, 8,
    5, 2, 0, 5, 0, 13, 0, 0, 5, 0, 0, 0, 1, 7, 0, 0, 0, 10, 10, 7, 0, 1, 10, 2,
    0, 0, 0, 0, 0, 5, 0, 10, 0, 8, 8, 3, 8, 8, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 3,
    0, 5, 0, 0, 0, 0, 0, 13, 2, 0, 0, 5, 0, 0, 0 };

  static const boolean_T bv[77] = { false, false, false, false, false, false,
    false, false, false, true, false, false, false, false, false, true, false,
    true, false, true, true, false, true, true, true, false, false, true, true,
    true, false, false, false, true, false, false, false, true, true, true, true,
    true, false, true, false, true, false, false, false, false, false, true,
    true, false, true, true, true, true, true, true, true, false, true, false,
    true, true, true, true, true, false, false, true, true, false, true, true,
    true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 77U * sizeof(double));
  memcpy(&obj_NanCutPoints[0], &bv[0], 77U * sizeof(boolean_T));
  memcpy(&obj_ClassProbability[0], &dv1[0], 154U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 77; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 154; i++) {
    obj_Children[i] = iv1[i];
  }

  memset(&obj_InfCutPoints[0], 0, 77U * sizeof(boolean_T));
  obj_Prior[0] = 0.55912294440093968;
  obj_Prior[1] = 0.44087705559906032;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[61]
 *                double obj_Children[122]
 *                double obj_CutPoint[61]
 *                boolean_T obj_NanCutPoints[61]
 *                boolean_T obj_InfCutPoints[61]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[122]
 * Return Type  : void
 */
void x_CompactClassificationTree_Com(double obj_CutPredictorIndex[61], double
  obj_Children[122], double obj_CutPoint[61], boolean_T obj_NanCutPoints[61],
  boolean_T obj_InfCutPoints[61], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[122])
{
  static const double dv1[122] = { 0.57165231010180317, 0.94809688581314877,
    0.46153846153846156, 0.992619926199262, 0.27777777777777785,
    0.96848137535816614, 0.18466353677621283, 1.0, 0.98757763975155266,
    0.071428571428571438, 1.0, 0.99085365853658536, 0.619047619047619,
    0.89285714285714268, 0.11663807890222985, 1.0, 0.97222222222222221, 1.0, 0.0,
    1.0, 0.925, 0.0, 1.0, 0.97872340425531912, 0.44444444444444442,
    0.425531914893617, 0.089552238805970158, 0.9859154929577465, 0.0, 1.0, 0.0,
    0.9375, 1.0, 0.0, 0.79999999999999993, 0.035714285714285733, 1.0,
    0.3087248322147651, 0.005167958656330753, 0.0, 1.0, 0.66666666666666674, 1.0,
    1.0, 0.0, 0.16666666666666666, 0.0, 0.97142857142857142, 0.10526315789473689,
    0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.028571428571428588, 1.0, 1.0, 0.0,
    0.42834768989819672, 0.051903114186851236, 0.53846153846153844,
    0.0073800738007380124, 0.72222222222222221, 0.031518624641833831,
    0.81533646322378717, 0.0, 0.012422360248447213, 0.9285714285714286, 0.0,
    0.0091463414634146388, 0.380952380952381, 0.10714285714285721,
    0.88336192109777012, 0.0, 0.027777777777777797, 0.0, 1.0, 0.0,
    0.075000000000000039, 1.0, 0.0, 0.021276595744680864, 0.55555555555555558,
    0.57446808510638292, 0.91044776119402981, 0.014084507042253532, 1.0, 0.0,
    1.0, 0.062500000000000014, 0.0, 1.0, 0.19999999999999998, 0.9642857142857143,
    0.0, 0.6912751677852349, 0.9948320413436692, 1.0, 0.0, 0.33333333333333337,
    0.0, 0.0, 1.0, 0.83333333333333326, 1.0, 0.028571428571428588,
    0.894736842105263, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0,
    0.97142857142857142, 0.0, 0.0, 1.0 };

  static const double dv[61] = { 0.845, 0.095, 0.035, 0.515, 1.04, 0.135, 0.245,
    0.0, 0.83, 0.245, 0.0, 0.025, 0.815, 0.38, 0.075000000000000011, 0.0, 0.27,
    0.0, 0.0, 0.0, 0.155, 0.0, 0.0, 1.2, 1.245, 1.615, 0.065, 0.535, 0.0, 0.0,
    0.0, 1.0550000000000002, 0.0, 0.0, 0.255, 0.745, 0.0, 0.045, 2.105, 0.0, 0.0,
    0.96, 0.0, 0.0, 0.0, 1.16, 0.0, 1.855, 1.855, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.05, 0.0, 0.0, 0.0 };

  static const signed char iv1[122] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 0, 0, 16, 17, 18, 19, 0, 0, 20, 21, 22, 23, 24, 25, 26, 27, 0, 0, 28,
    29, 0, 0, 0, 0, 0, 0, 30, 31, 0, 0, 0, 0, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 0, 0, 0, 0, 0, 0, 42, 43, 0, 0, 0, 0, 44, 45, 46, 47, 0, 0, 48, 49, 50,
    51, 0, 0, 0, 0, 52, 53, 0, 0, 0, 0, 0, 0, 54, 55, 0, 0, 56, 57, 58, 59, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 61, 0, 0, 0, 0, 0, 0 };

  static const signed char iv[61] = { 5, 2, 1, 13, 7, 2, 11, 0, 11, 13, 0, 2, 11,
    3, 1, 0, 3, 0, 0, 0, 3, 0, 0, 5, 10, 10, 3, 13, 0, 0, 0, 10, 0, 0, 1, 11, 0,
    2, 10, 0, 0, 10, 0, 0, 0, 8, 0, 10, 8, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0 };

  static const boolean_T bv[61] = { false, false, false, false, false, false,
    false, true, false, false, true, false, false, false, false, true, false,
    true, true, true, false, true, true, false, false, false, false, false, true,
    true, true, false, true, true, false, false, true, false, false, true, true,
    false, true, true, true, false, true, false, false, true, true, true, true,
    true, true, true, true, false, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 61U * sizeof(double));
  for (i = 0; i < 61; i++) {
    obj_NanCutPoints[i] = bv[i];
  }

  memcpy(&obj_ClassProbability[0], &dv1[0], 122U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 61; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 122; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 61; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.57165231010180106;
  obj_Prior[1] = 0.42834768989819888;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * Arguments    : double obj_CutPredictorIndex[63]
 *                double obj_Children[126]
 *                double obj_CutPoint[63]
 *                boolean_T obj_NanCutPoints[63]
 *                boolean_T obj_InfCutPoints[63]
 *                char obj_ClassNames[14]
 *                int obj_ClassNamesLength[2]
 *                c_classreg_learning_coderutils_ *obj_ScoreTransform
 *                double obj_Prior[2]
 *                boolean_T obj_ClassLogicalIndices[2]
 *                double obj_Cost[4]
 *                double obj_ClassProbability[126]
 * Return Type  : void
 */
void y_CompactClassificationTree_Com(double obj_CutPredictorIndex[63], double
  obj_Children[126], double obj_CutPoint[63], boolean_T obj_NanCutPoints[63],
  boolean_T obj_InfCutPoints[63], char obj_ClassNames[14], int
  obj_ClassNamesLength[2], c_classreg_learning_coderutils_ *obj_ScoreTransform,
  double obj_Prior[2], boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
  double obj_ClassProbability[126])
{
  static const double dv1[126] = { 0.562255285826157, 0.97253634894991925,
    0.17629179331306991, 0.989492119089317, 0.77083333333333326,
    0.78787878787878785, 0.10810810810810811, 0.96363636363636362,
    0.99566160520607372, 1.0, 0.0, 0.85245901639344257, 0.0, 0.82051282051282037,
    0.057866184448462941, 1.0, 0.5, 0.9978070175438597, 0.79999999999999993,
    0.75675675675675669, 1.0, 0.5, 1.0, 0.029962546816479415,
    0.84210526315789469, 0.0, 0.66666666666666674, 1.0, 0.9939393939393939, 0.0,
    1.0, 0.8928571428571429, 0.33333333333333331, 1.0, 0.0, 0.42424242424242431,
    0.0039920159680638754, 1.0, 0.0, 0.0, 1.0, 0.79999999999999993, 1.0,
    0.96153846153846156, 0.0, 0.74999999999999989, 0.0, 0.0, 1.0,
    0.19999999999999998, 0.0020161290322580658, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0,
    0.0, 1.0, 0.12499999999999999, 0.0, 1.0, 0.0, 0.43774471417384309,
    0.027463651050080785, 0.82370820668693, 0.010507880910683021,
    0.22916666666666677, 0.21212121212121221, 0.89189189189189189,
    0.03636363636363639, 0.00433839479392625, 0.0, 1.0, 0.14754098360655749, 1.0,
    0.17948717948717957, 0.94213381555153708, 0.0, 0.5, 0.0021929824561403525,
    0.19999999999999998, 0.24324324324324337, 0.0, 0.5, 0.0, 0.97003745318352064,
    0.15789473684210528, 1.0, 0.33333333333333337, 0.0, 0.0060606060606060641,
    1.0, 0.0, 0.10714285714285719, 0.66666666666666674, 0.0, 1.0,
    0.57575757575757569, 0.99600798403193613, 0.0, 1.0, 1.0, 0.0,
    0.19999999999999998, 0.0, 0.038461538461538478, 1.0, 0.25, 1.0, 1.0, 0.0,
    0.79999999999999993, 0.99798387096774188, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0,
    0.0, 0.875, 1.0, 0.0, 1.0 };

  static const double dv[63] = { 0.055, 0.195, 0.29000000000000004, 0.42, 0.03,
    0.915, 0.04, 0.035, 0.175, 0.0, 0.0, 1.625, 0.0, 1.245, 2.075, 0.0, 0.045,
    1.0150000000000001, 0.05, 0.155, 0.0, 0.655, 0.0, 0.865, 0.16, 0.0, 0.085,
    0.0, 1.025, 0.0, 0.0, 1.605, 0.24, 0.0, 0.0, 1.42, 0.365, 0.0, 0.0, 0.0, 0.0,
    0.030000000000000002, 0.0, 1.75, 0.0, 1.05, 0.0, 0.0, 0.0, 1.435,
    0.23500000000000001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.79, 0.0, 0.0,
    0.0 };

  static const signed char iv1[126] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 0, 0, 0, 0, 20, 21, 0, 0, 22, 23, 24, 25, 0, 0, 26,
    27, 28, 29, 30, 31, 32, 33, 0, 0, 34, 35, 0, 0, 36, 37, 38, 39, 0, 0, 40, 41,
    0, 0, 42, 43, 0, 0, 0, 0, 44, 45, 46, 47, 0, 0, 0, 0, 48, 49, 50, 51, 0, 0,
    0, 0, 0, 0, 0, 0, 52, 53, 0, 0, 54, 55, 0, 0, 56, 57, 0, 0, 0, 0, 0, 0, 58,
    59, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62, 63, 0, 0, 0,
    0, 0, 0 };

  static const signed char iv[63] = { 2, 1, 11, 11, 3, 12, 1, 2, 3, 0, 0, 8, 0,
    5, 10, 0, 2, 11, 1, 11, 0, 13, 0, 5, 2, 0, 1, 0, 11, 0, 0, 8, 13, 0, 0, 10,
    11, 0, 0, 0, 0, 2, 0, 7, 0, 8, 0, 0, 0, 10, 13, 0, 0, 0, 0, 0, 0, 0, 0, 11,
    0, 0, 0 };

  static const boolean_T bv[63] = { false, false, false, false, false, false,
    false, false, false, true, true, false, true, false, false, true, false,
    false, false, false, true, false, true, false, false, true, false, true,
    false, true, true, false, false, true, true, false, false, true, true, true,
    true, false, true, false, true, false, true, true, true, false, false, true,
    true, true, true, true, true, true, true, false, true, true, true };

  int i;
  for (i = 0; i < 14; i++) {
    obj_ClassNames[i] = cv[i];
  }

  memcpy(&obj_CutPoint[0], &dv[0], 63U * sizeof(double));
  for (i = 0; i < 63; i++) {
    obj_NanCutPoints[i] = bv[i];
  }

  memcpy(&obj_ClassProbability[0], &dv1[0], 126U * sizeof(double));
  obj_ClassNamesLength[0] = 3;
  obj_ClassLogicalIndices[0] = true;
  obj_ClassNamesLength[1] = 7;
  obj_ClassLogicalIndices[1] = true;
  *obj_ScoreTransform = Identity;
  for (i = 0; i < 63; i++) {
    obj_CutPredictorIndex[i] = iv[i];
  }

  for (i = 0; i < 126; i++) {
    obj_Children[i] = iv1[i];
  }

  for (i = 0; i < 63; i++) {
    obj_InfCutPoints[i] = false;
  }

  obj_Prior[0] = 0.562255285826155;
  obj_Prior[1] = 0.437744714173845;
  obj_Cost[0] = 0.0;
  obj_Cost[1] = 1.0;
  obj_Cost[2] = 1.0;
  obj_Cost[3] = 0.0;
}

/*
 * File trailer for CompactClassificationTree.c
 *
 * [EOF]
 */
