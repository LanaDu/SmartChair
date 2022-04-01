function [CF_data] = curvefit(data)

%% CF for Machine Learning 
%Curve Fitting For Sesnsor Sheet A

%Import and Reshape Data
%Sensor Sheet B
%Load Testing Table
Sen_A=importdata('Sensor_Sheet_A.mat');
Load=Sen_A(:,1);
R11_A=Sen_A(:,4);
R12_A=Sen_A(:,6);
R21_A=Sen_A(:,8);
R22_A=Sen_A(:,10);

%X Series
x=[0:1:120]';
%Apply Curve Fitting Functions
[R11_lin_A,gof7]=fit(Load,R11_A,'linearinterp');
[R11_exp2_A,gof1]=fit(Load,R11_A,'exp2');
R11_lin_x_A=R11_lin_A(x);
R11_exp_x_A=R11_exp2_A(x);
R11_ens_A=(R11_lin_x_A+R11_exp_x_A)/2;

[R12_lin_A,gof7]=fit(Load,R12_A,'linearinterp');
[R12_exp2_A,gof1]=fit(Load,R12_A,'exp2');
R12_lin_x_A=R12_lin_A(x);
R12_exp_x_A=R12_exp2_A(x);
R12_ens_A=(R12_lin_x_A+R12_exp_x_A)/2;

[R21_lin_A,gof7]=fit(Load,R21_A,'linearinterp');
[R21_exp2_A,gof1]=fit(Load,R21_A,'exp2');
R21_lin_x_A=R21_lin_A(x);
R21_exp_x_A=R21_exp2_A(x);
R21_ens_A=(R21_lin_x_A+R21_exp_x_A)/2;

[R22_lin_A,gof7]=fit(Load,R22_A,'linearinterp');
[R22_exp2_A,gof1]=fit(Load,R22_A,'exp2');
R22_lin_x_A=R22_lin_A(x);
R22_exp_x_A=R22_exp2_A(x);
R22_ens_A=(R22_lin_x_A+R22_exp_x_A)/2;

%% Curve Fitting For Sesnsor Sheet C

%Import and Reshape Data
%Sensor Sheet B
%Load Testing Table
Sen_B_Table=importdata('Sensor_Sheet_C.mat');
Sen_B=Sen_B_Table.Variables;
Load=Sen_B(:,1);
R11=Sen_B(:,4);
R12=Sen_B(:,6);
R13=Sen_B(:,8);
R21=Sen_B(:,10);
R22=Sen_B(:,12);
R23=Sen_B(:,14);
R31=Sen_B(:,16);
R32=Sen_B(:,18);
R33=Sen_B(:,20);

x=[0:1:120]';

[R11_lin,gof7]=fit(Load,R11,'linearinterp');
[R11_exp,gof9]=fit(Load,R11,'exp2');
R11_exp_x=R11_exp(x);
R11_lin_x=R11_lin(x);
R11_ens_C=(R11_exp_x+R11_lin_x)/2;


[R12_lin,gof7]=fit(Load,R12,'linearinterp');
[R12_exp,gof9]=fit(Load,R12,'exp2');
R12_exp_x=R12_exp(x);
R12_lin_x=R12_lin(x);
R12_ens_C=(R12_exp_x+R12_lin_x)/2;

[R12_lin,gof7]=fit(Load,R12,'linearinterp');
[R12_exp,gof9]=fit(Load,R12,'exp2');
R12_exp_x=R12_exp(x);
R12_lin_x=R12_lin(x);
R12_ens_C=(R12_exp_x+R12_lin_x)/2;

[R13_lin,gof7]=fit(Load,R13,'linearinterp');
[R13_exp,gof9]=fit(Load,R13,'exp2');
R13_exp_x=R13_exp(x);
R13_lin_x=R13_lin(x);
R13_ens_C=(R13_exp_x+R13_lin_x)/2;

[R21_lin,gof7]=fit(Load,R21,'linearinterp');
[R21_exp,gof9]=fit(Load,R21,'exp2');
R21_exp_x=R21_exp(x);
R21_lin_x=R21_lin(x);
R21_ens_C=(R21_exp_x+R21_lin_x)/2;

[R22_lin,gof7]=fit(Load,R22,'linearinterp');
[R22_exp,gof9]=fit(Load,R22,'exp2');
R22_exp_x=R22_exp(x);
R22_lin_x=R22_lin(x);
R22_ens_C=(R22_exp_x+R22_lin_x)/2;

[R23_lin,gof7]=fit(Load,R23,'linearinterp');
[R23_exp,gof9]=fit(Load,R23,'exp2');
R23_exp_x=R23_exp(x);
R23_lin_x=R23_lin(x);
R23_ens_C=(R23_exp_x+R23_lin_x)/2;

[R31_lin,gof7]=fit(Load,R31,'linearinterp');
[R31_exp,gof9]=fit(Load,R31,'exp2');
R31_exp_x=R31_exp(x);
R31_lin_x=R31_lin(x);
R31_ens_C=(R31_exp_x+R31_lin_x)/2;

[R32_lin,gof7]=fit(Load,R32,'linearinterp');
[R32_exp,gof9]=fit(Load,R32,'exp2');
R32_exp_x=R32_exp(x);
R32_lin_x=R32_lin(x);
R32_ens_C=(R32_exp_x+R32_lin_x)/2;

[R33_lin,gof7]=fit(Load,R33,'linearinterp');
[R33_exp,gof9]=fit(Load,R33,'exp2');
R33_exp_x=R33_exp(x);
R33_lin_x=R33_lin(x);
R33_ens_C=(R33_exp_x+R33_lin_x)/2;

%% Apply CF

A1 = data(:,1);
A2 = data(:,2);
A3 = data(:,3);
A4 = data(:,4);
A5 = data(:,5);
A6 = data(:,6);
A7 = data(:,7);
A8 = data(:,8);
A9 = data(:,9);
A10 = data(:,10);
A11 = data(:,11);
A12 = data(:,12);
A13 = data(:,13);


A1_cf = interp1(R11_ens_A,x,A1);
A2_cf = interp1(R12_ens_A,x,A2);
A3_cf = interp1(R21_ens_A,x,A3);
A4_cf = interp1(R22_ens_A,x,A4);
A5_cf = interp1(R11_ens_C,x,A5);
A6_cf = interp1(R12_ens_C,x,A6);
A7_cf = interp1(R13_ens_C,x,A7);
A8_cf = interp1(R21_ens_C,x,A8);
A9_cf = interp1(R22_ens_C,x,A9);
A10_cf = interp1(R23_ens_C,x,A10);
A11_cf = interp1(R31_ens_C,x,A11);
A12_cf = interp1(R32_ens_C,x,A12);
A13_cf = interp1(R33_ens_C,x,A13);

CF_data=[A1_cf A2_cf A3_cf A4_cf A5_cf A6_cf A7_cf A8_cf A9_cf A10_cf A11_cf A12_cf A13_cf]


