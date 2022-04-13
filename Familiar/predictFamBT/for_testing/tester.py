# -*- coding: utf-8 -*-
"""
Created on Mon Apr 11 21:59:56 2022

@author: mhb17177
"""
from __future__ import print_function
import predictFamBT
import matlab


my_predictFamBT = predictFamBT.initialize()

sensorDataIn = matlab.double([0.02, 0.01, 0.0, 0.0, 0.74, 0.0, 0.75, 1.12, 0.01, 1.52, 0.1, 0.0, 1.17], size=(1, 13))
labelOut = my_predictFamBT.predictFamBT(sensorDataIn)
print(labelOut, sep='\n')

my_predictFamBT.terminate()