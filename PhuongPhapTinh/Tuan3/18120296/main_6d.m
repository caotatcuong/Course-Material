clear all;
clc;
format long;

syms x
fprintf('Thuc hien lai cau 3:\n');
f=x^2+x-5;
g=sqrt(5-x);
a=0;
b=2;
x0=1.5;
x_ex= vpasolve(f==0,x,[a,b]);
tol=10^(-3);
[Solution,tables]=Bai6(f,g,a,b,x0,x_ex,tol)