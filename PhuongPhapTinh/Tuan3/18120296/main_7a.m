clear all;
clc;
format long;

syms x
fprintf('Cau 7a:\n');
f=x - x/2 - 1/x;
g=x/2 + 1/x;
a=0;
b=2;
x0=1;
x_ex= vpasolve(f==0,x,[a,b]);
tol=10^(-3);
[Solution,tables]=Bai6(f,g,a,b,x0,x_ex,tol)