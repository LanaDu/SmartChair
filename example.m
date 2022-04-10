function labels = example(data, svm)
    load('svm.mat')
    % use svm model to predict labels
    labels = predict(svm,data);
end