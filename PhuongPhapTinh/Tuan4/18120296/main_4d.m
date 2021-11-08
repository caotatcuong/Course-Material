clear all;
clc;
format long;

syms x
f=x^3-6*x^2+2*x+25;
df=diff(f,x);
a=-5;
b=5;
x0=0;
x_ex= vpasolve(f==0,x,[a,b]);
tol=10^(-3);
[Solution,tables]=Bai4a_b(f,df,a,b,x0,x_ex,tol)


