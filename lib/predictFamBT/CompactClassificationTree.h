/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CompactClassificationTree.h
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

#ifndef COMPACTCLASSIFICATIONTREE_H
#define COMPACTCLASSIFICATIONTREE_H

/* Include Files */
#include "predictFamBT_internal_types.h"
#include "predictFamBT_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void ab_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[63], double obj_Children[126],
    double obj_CutPoint[63], boolean_T obj_NanCutPoints[63],
    boolean_T obj_InfCutPoints[63], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[126]);

void bb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[59], double obj_Children[118],
    double obj_CutPoint[59], boolean_T obj_NanCutPoints[59],
    boolean_T obj_InfCutPoints[59], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[118]);

void c_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[93], double obj_Children[186],
    double obj_CutPoint[93], boolean_T obj_NanCutPoints[93],
    boolean_T obj_InfCutPoints[93], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[186]);

void c_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[93], const double obj_Children[186],
    const double obj_CutPoint[93], const boolean_T obj_NanCutPoints[93],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[186], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void cb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[71], double obj_Children[142],
    double obj_CutPoint[71], boolean_T obj_NanCutPoints[71],
    boolean_T obj_InfCutPoints[71], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[142]);

void d_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[77], double obj_Children[154],
    double obj_CutPoint[77], boolean_T obj_NanCutPoints[77],
    boolean_T obj_InfCutPoints[77], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[154]);

void d_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[77], const double obj_Children[154],
    const double obj_CutPoint[77], const boolean_T obj_NanCutPoints[77],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[154], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void db_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[65], double obj_Children[130],
    double obj_CutPoint[65], boolean_T obj_NanCutPoints[65],
    boolean_T obj_InfCutPoints[65], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[130]);

void e_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[81], double obj_Children[162],
    double obj_CutPoint[81], boolean_T obj_NanCutPoints[81],
    boolean_T obj_InfCutPoints[81], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[162]);

void e_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[81], const double obj_Children[162],
    const double obj_CutPoint[81], const boolean_T obj_NanCutPoints[81],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[162], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void eb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[63], double obj_Children[126],
    double obj_CutPoint[63], boolean_T obj_NanCutPoints[63],
    boolean_T obj_InfCutPoints[63], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[126]);

void f_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[63], double obj_Children[126],
    double obj_CutPoint[63], boolean_T obj_NanCutPoints[63],
    boolean_T obj_InfCutPoints[63], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[126]);

void f_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[63], const double obj_Children[126],
    const double obj_CutPoint[63], const boolean_T obj_NanCutPoints[63],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[126], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void fb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[75], double obj_Children[150],
    double obj_CutPoint[75], boolean_T obj_NanCutPoints[75],
    boolean_T obj_InfCutPoints[75], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[150]);

void g_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[83], double obj_Children[166],
    double obj_CutPoint[83], boolean_T obj_NanCutPoints[83],
    boolean_T obj_InfCutPoints[83], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[166]);

void g_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[83], const double obj_Children[166],
    const double obj_CutPoint[83], const boolean_T obj_NanCutPoints[83],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[166], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void gb_CompactClassificationTree_Co(
    double obj_CutPredictorIndex[89], double obj_Children[178],
    double obj_CutPoint[89], boolean_T obj_NanCutPoints[89],
    boolean_T obj_InfCutPoints[89], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[178]);

void h_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[83], double obj_Children[166],
    double obj_CutPoint[83], boolean_T obj_NanCutPoints[83],
    boolean_T obj_InfCutPoints[83], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[166]);

void h_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[91], const double obj_Children[182],
    const double obj_CutPoint[91], const boolean_T obj_NanCutPoints[91],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[182], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void i_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[91], double obj_Children[182],
    double obj_CutPoint[91], boolean_T obj_NanCutPoints[91],
    boolean_T obj_InfCutPoints[91], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[182]);

void i_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[67], const double obj_Children[134],
    const double obj_CutPoint[67], const boolean_T obj_NanCutPoints[67],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[134], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void j_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[77], double obj_Children[154],
    double obj_CutPoint[77], boolean_T obj_NanCutPoints[77],
    boolean_T obj_InfCutPoints[77], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[154]);

void j_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[99], const double obj_Children[198],
    const double obj_CutPoint[99], const boolean_T obj_NanCutPoints[99],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[198], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void k_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[83], double obj_Children[166],
    double obj_CutPoint[83], boolean_T obj_NanCutPoints[83],
    boolean_T obj_InfCutPoints[83], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[166]);

void k_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[65], const double obj_Children[130],
    const double obj_CutPoint[65], const boolean_T obj_NanCutPoints[65],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[130], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void l_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[67], double obj_Children[134],
    double obj_CutPoint[67], boolean_T obj_NanCutPoints[67],
    boolean_T obj_InfCutPoints[67], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[134]);

void l_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[79], const double obj_Children[158],
    const double obj_CutPoint[79], const boolean_T obj_NanCutPoints[79],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[158], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void m_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[83], double obj_Children[166],
    double obj_CutPoint[83], boolean_T obj_NanCutPoints[83],
    boolean_T obj_InfCutPoints[83], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[166]);

void m_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[69], const double obj_Children[138],
    const double obj_CutPoint[69], const boolean_T obj_NanCutPoints[69],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[138], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void n_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[99], double obj_Children[198],
    double obj_CutPoint[99], boolean_T obj_NanCutPoints[99],
    boolean_T obj_InfCutPoints[99], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[198]);

void n_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[71], const double obj_Children[142],
    const double obj_CutPoint[71], const boolean_T obj_NanCutPoints[71],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[142], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void o_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[81], double obj_Children[162],
    double obj_CutPoint[81], boolean_T obj_NanCutPoints[81],
    boolean_T obj_InfCutPoints[81], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[162]);

void o_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[61], const double obj_Children[122],
    const double obj_CutPoint[61], const boolean_T obj_NanCutPoints[61],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[122], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void p_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[65], double obj_Children[130],
    double obj_CutPoint[65], boolean_T obj_NanCutPoints[65],
    boolean_T obj_InfCutPoints[65], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[130]);

void p_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[59], const double obj_Children[118],
    const double obj_CutPoint[59], const boolean_T obj_NanCutPoints[59],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[118], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void q_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[67], double obj_Children[134],
    double obj_CutPoint[67], boolean_T obj_NanCutPoints[67],
    boolean_T obj_InfCutPoints[67], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[134]);

void q_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[75], const double obj_Children[150],
    const double obj_CutPoint[75], const boolean_T obj_NanCutPoints[75],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[150], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void r_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[79], double obj_Children[158],
    double obj_CutPoint[79], boolean_T obj_NanCutPoints[79],
    boolean_T obj_InfCutPoints[79], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[158]);

void r_CompactClassificationTree_pre(
    const double obj_CutPredictorIndex[89], const double obj_Children[178],
    const double obj_CutPoint[89], const boolean_T obj_NanCutPoints[89],
    const char obj_ClassNames[14], const int obj_ClassNamesLength[2],
    const double obj_Prior[2], const double obj_Cost[4],
    const double obj_ClassProbability[178], const emxArray_real_T *Xin,
    emxArray_cell_wrap_0 *labels, emxArray_real_T *scores);

void s_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[93], double obj_Children[186],
    double obj_CutPoint[93], boolean_T obj_NanCutPoints[93],
    boolean_T obj_InfCutPoints[93], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[186]);

void t_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[91], double obj_Children[182],
    double obj_CutPoint[91], boolean_T obj_NanCutPoints[91],
    boolean_T obj_InfCutPoints[91], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[182]);

void u_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[69], double obj_Children[138],
    double obj_CutPoint[69], boolean_T obj_NanCutPoints[69],
    boolean_T obj_InfCutPoints[69], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[138]);

void v_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[71], double obj_Children[142],
    double obj_CutPoint[71], boolean_T obj_NanCutPoints[71],
    boolean_T obj_InfCutPoints[71], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[142]);

void w_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[77], double obj_Children[154],
    double obj_CutPoint[77], boolean_T obj_NanCutPoints[77],
    boolean_T obj_InfCutPoints[77], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[154]);

void x_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[61], double obj_Children[122],
    double obj_CutPoint[61], boolean_T obj_NanCutPoints[61],
    boolean_T obj_InfCutPoints[61], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[122]);

void y_CompactClassificationTree_Com(
    double obj_CutPredictorIndex[63], double obj_Children[126],
    double obj_CutPoint[63], boolean_T obj_NanCutPoints[63],
    boolean_T obj_InfCutPoints[63], char obj_ClassNames[14],
    int obj_ClassNamesLength[2],
    c_classreg_learning_coderutils_ *obj_ScoreTransform, double obj_Prior[2],
    boolean_T obj_ClassLogicalIndices[2], double obj_Cost[4],
    double obj_ClassProbability[126]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for CompactClassificationTree.h
 *
 * [EOF]
 */
