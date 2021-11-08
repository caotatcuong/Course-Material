clear all;
clc;
format long;

syms x
fprintf('Thuc hien lai cau 2:\n');
f=x+sin(x)-2;
g=2-sin(x);
a=0;
b=2;
x0=1.05;
x_ex= vpasolve(f==0,x,[a,b]);
tol=10^(-3);
[Solution,tables]=Bai6(f,g,a,b,x0,x_ex,tol)


