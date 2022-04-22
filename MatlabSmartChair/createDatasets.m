clear; close all;

% Select Data to form datasets
[badfile, badpath] = uigetfile('*.xlsm','Select Bad Data','Multiselect','on');
[perffile, perfpath] = uigetfile('*.xlsm','Select Perfect Data','Multiselect','on');
badSensor = [];
perfSensor = [];
perfTxt = [];
badTxt = [];
tf = iscell(badfile);

% Take table data and put into array
if tf==0
    bad = readtable(fullfile(badpath,badfile));
    perf = readtable(fullfile(perfpath,perffile));
    badSensor = table2array(bad(:,3));
    badTxt = table2array(bad(:,2));
    perfSensor = table2array(perf(:,3));
    perfTxt = table2array(perf(:,2));
else
    for p=1:1:numel(badfile)
        bad = readtable(fullfile(badpath,badfile{p}));
        perf = readtable(fullfile(perfpath,perffile{p}));
        badSensor = [badSensor; table2array(bad(:,3))];
        badTxt = [badTxt; table2array(bad(:,2))];
        perfSensor = [perfSensor; table2array(perf(:,3))];
        perfTxt = [perfTxt; table2array(perf(:,2))];
    end
end

% Sorting Data
[badData,badLabels] = sortData(badTxt,badSensor,"Bad");
[perfData,perfLabels] = sortData(perfTxt,perfSensor,"Perfect");

% testingData=[badData;perfData];
% testingLabels=[badLabels;perfLabels];
% save('badData.mat','badData')
% save('perfData.mat','perfData')
