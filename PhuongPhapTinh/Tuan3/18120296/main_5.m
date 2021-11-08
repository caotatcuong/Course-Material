clear all;
clc;
format long;

syms x
f=exp(x)-x-3;
fprintf('Cau a:\n');
[c,fc]=Bai5(f,0,3,10^(-3));
fprintf('Nghiem cua phuong trinh la: ');
disp(c)

fprintf('Cau b:\n');
[c,fc]=Bai5(f,0,2,5*10^(-3));
fprintf('Nghiem cua phuong trinh la: ');
disp(c)

fprintf('Cau c:\n');
[c,fc]=Bai5(f,-3,0,10^(-4));
fprintf('Nghiem cua phuong trinh la: ');
disp(c)

fprintf('Cau d:\n');
[c,fc]=Bai5(f,-3,-1,10^(-4));
fprintf('Nghiem cua phuong trinh la: ');
disp(c)



