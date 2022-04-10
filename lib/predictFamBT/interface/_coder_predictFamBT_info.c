/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_predictFamBT_info.c
 *
 * MATLAB Coder version            : 5.2
 * C/C++ source code generated on  : 10-Apr-2022 17:05:19
 */

/* Include Files */
#include "_coder_predictFamBT_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789ce554cd4edc3010f6562055ad6873694f3df480b8a046fde15071e8a14188e5678544"
      "164a3152bdc9b06bd63f91eda08527e0c6eb204e3c04879e79813e41"
      "a526bb9bac89940675ab54a82359f6f81bfb9b197b06359a5b0d84d0333492eba7a3792e"
      "19b7c970c6fb8fd05d29e28d825d638c67328b66f273b6fdc5780ea4",
      "3030302345100ef9c950722a8830fe6904488196ec04c221724419f894c38eadb4528daf"
      "5a50aea450baf67a10f477628e544f4f3c64b692e7e39b152fb2e29d"
      "a9c847518af970ac1cfc4f7c977fc897ddd5aee0cbf083f6e1da32de3a7dbd2283988330"
      "1a478a048606d055328e22258f2130d893bc937c2f43a5d0789570ca",
      "2851f9e233e97621f41580763931a83a6fcfef19873ddfdeb17f8c7852443f36bf0f4dea"
      "e27bf3e9c9ab3af932f9577c8312befbfec317257c4e016f6e9cecf5"
      "fa67ebfa6bff7877a9fda1e7bd5bb3ffd176891f76edfcce0f64e9b61f75dd3f6d3def96"
      "dcef14f083e617ef703ea941463a4a4a338f8d94ac2307581b921477",
      "c088d60aba7871b2624094a022dd9321a8b4d6a3a4056c2b086960a472f9248ef329e358"
      "a88823c333efdccc3977e85b6c28d3aeaf88d04752f17afab32d7feb"
      "3dfd0abe0c4fdeb335e57b0e7386f39ca5af595f3f59bebaa9b53f23fc93d5ca379687da"
      "9f5f96f039057c9df87e4cc23dd569996869ffe3e0ed7ba9bc87df9f",
      "7f0110cbeee7",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3032U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *epFieldName[6] = {
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  const char_T *propFieldName[5] = {"Version", "ResolvedFunctions",
                                    "EntryPoints", "CoverageInfo",
                                    "IsPolymorphic"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, (const char_T *)"Name",
                emlrtMxCreateString((const char_T *)"predictFamBT"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, (const char_T *)"FullPath",
                emlrtMxCreateString(
                    (const char_T *)"H:\\My "
                                    "Documents\\practicegroupproject\\Combinati"
                                    "ons\\Familiar\\predictFamBT.m"));
  emlrtSetField(xEntryPoints, 0, (const char_T *)"TimeStamp",
                emlrtMxCreateDoubleScalar(738621.64869212965));
  xResult =
      emlrtCreateStructMatrix(1, 1, 5, (const char_T **)&propFieldName[0]);
  emlrtSetField(
      xResult, 0, (const char_T *)"Version",
      emlrtMxCreateString((const char_T *)"9.10.0.1739362 (R2021a) Update 5"));
  emlrtSetField(xResult, 0, (const char_T *)"ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, (const char_T *)"EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_predictFamBT_info.c
 *
 * [EOF]
 */
