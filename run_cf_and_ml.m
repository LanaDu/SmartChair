[bad_cf_data] = curvefit(allBad);
[perf_cf_data] = curvefit(allPerf);

badLabels = [badLabels;badLabels1;badLabels2];
perfLabels = [perfLabels;perfLabels1;perfLabels2];
Labels = [badLabels;perfLabels];
Data = [bad_cf_data;perf_cf_data];

