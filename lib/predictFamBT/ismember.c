/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: ismember.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

/* Include Files */
#include "ismember.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const char a[14]
 *                const char s[14]
 *                boolean_T tf[2]
 *                int loc[2]
 * Return Type  : void
 */
void local_ismember(const char a[14], const char s[14], boolean_T tf[2],
                    int loc[2])
{
  int b_i;
  int i;
  int j;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T rowmatch;
  tf[0] = false;
  loc[0] = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    rowmatch = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 7)) {
      b_i = j << 1;
      if (!(a[b_i] == s[i + b_i])) {
        rowmatch = false;
        exitg2 = true;
      } else {
        j++;
      }
    }
    if (rowmatch) {
      tf[0] = true;
      loc[0] = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }
  tf[1] = false;
  loc[1] = 0;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 2)) {
    rowmatch = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 7)) {
      b_i = j << 1;
      if (!(a[b_i + 1] == s[i + b_i])) {
        rowmatch = false;
        exitg2 = true;
      } else {
        j++;
      }
    }
    if (rowmatch) {
      tf[1] = true;
      loc[1] = i + 1;
      exitg1 = true;
    } else {
      i++;
    }
  }
}

/*
 * File trailer for ismember.c
 *
 * [EOF]
 */
