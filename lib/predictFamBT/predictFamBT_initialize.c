/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: predictFamBT_initialize.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

/* Include Files */
#include "predictFamBT_initialize.h"
#include "predictFamBT_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void predictFamBT_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_predictFamBT = true;
}

/*
 * File trailer for predictFamBT_initialize.c
 *
 * [EOF]
 */
