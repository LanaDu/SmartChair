#!/usr/bin/env python
"""
Sample script that uses the predictFamBT module created using
MATLAB Compiler SDK.

Refer to the MATLAB Compiler SDK documentation for more information.
"""

from __future__ import print_function
import predictFamBT
import matlab

my_predictFamBT = predictFamBT.initialize()

sensorDataIn = matlab.double([0.02, 0.01, 0.0, 0.0, 0.74, 0.0, 0.75, 1.12, 0.01, 1.52, 0.1, 0.0, 1.17], size=(1, 13))
postureOut = my_predictFamBT.predictFamBT(sensorDataIn)
print(postureOut, sep='\n')

my_predictFamBT.terminate()
