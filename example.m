clear; close all;
load('svm.mat')
load('testingdata.mat')
% use svm model to predict labels
labels = predict(svm,testingData);