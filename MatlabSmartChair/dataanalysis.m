% clear;close all;
% createDatasets

% Seperating Sensors into groups for easier analysis
right=[perfData(:,[2 4 5 8 11]);badData(:,[2 4 5 8 11])];
left=[perfData(:,[1 3 7 10 13]);badData(:,[1 3 7 10 13])];
bottomright=[perfData(:,[5 8 11]);badData(:,[5 8 11])];
bottomleft=[perfData(:,[7 10 13]);badData(:,[7 10 13])];
back=[perfData(:,[1 2 3 4]);badData(:,[1 2 3 4])];

figure(1)
plot(right)
title('Right Sensors Throughout Full Dataset')
xlabel('Sample n');ylabel('Voltage'); xlim([1 length(right)]);
xline([37 48 60 72],'--','Change in Position')
legend('Sensor2','Sensor4','Sensor5','Sensor8','Sensor11','location','Northwest')

figure(2)
plot(left)
title('Left Sensors Throughout Full Dataset')
xlabel('Sample n');ylabel('Voltage'); xlim([1 length(left)]);
xline([37 48 60 72],'--','Change in Position')
legend('Sensor1','Sensor3','Sensor7','Sensor10','Sensor13','location','Northwest')

figure(3)
plot(bottomleft)
title('Bottom Left Sensors Throughout Full Dataset')
xlabel('Sample n');ylabel('Voltage'); xlim([1 length(bottomleft)]);
xline([37 48 60 72],'--','Change in Position')
legend('Sensor7','Sensor10','Sensor13','location','Northwest')

figure(4)
plot(bottomright)
title('Bottom Right Sensors Throughout Full Dataset')
xlabel('Sample n');ylabel('Voltage'); xlim([1 length(bottomright)]);
xline([37 48 60 72],'--','Change in Position')
legend('Sensor5','Sensor8','Sensor11','location','Northwest')

figure(5)
plot(back)
title('Back Sensors Throughout Full Dataset')
xlabel('Sample n');ylabel('Voltage'); xlim([1 length(back)]);
xline([37 48 60 72],'--','Change in Position')
legend('Sensor1','Sensor2','Sensor3','Sensor4','location','Northwest')

figure(6)
s1=scatter(1:13,badData(1:11,:),'r','filled');
hold on
s2=scatter(1:13,badData(12:23,:),'b','filled');
hold on
s3=scatter(1:13,badData(25:35,:),'g','filled');
hold on 
s4=scatter(1:13,badData(36:end,:),'m','filled');
legend([s1(1) s2(1) s3(1) s4(1)],{'Position 1- Leaning Forward',...
    'Position 2- Leaning Right','Position 3- Leaning Left','Position 4- Crossed Legs'})

% figure(2)
% subplot(1,2,1)
% boxplot(badData)
% ylim([-0.1 2.6]);title('Bad Data for Weights Above 90kg');
% xlabel('Sensor');ylabel('Voltage')
% subplot(1,2,2)
% boxplot(perfData)
% ylim([-0.1 2.6]);title('Perfect Data for Weights Above 90kg');
% xlabel('Sensor');ylabel('Voltage')
