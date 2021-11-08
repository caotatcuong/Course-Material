clear all;
clc;
format long;

syms x
f=exp(x)+2^(-x)+2*cos(x)-6;
df=diff(f,x);
a=1;
b=2;
x0=1.5;
x_ex= vpasolve(f==0,x,[a,b]);
tol=10^(-3);
[Solution,tables]=Bai4a_b(f,df,a,b,x0,x_ex,tol)