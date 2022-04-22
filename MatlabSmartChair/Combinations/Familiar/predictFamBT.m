function label = predictFamBT(sensorData)

 load('familiarBT.mat','familiarBT')
 label = predict(familiarBT,sensorData);
end