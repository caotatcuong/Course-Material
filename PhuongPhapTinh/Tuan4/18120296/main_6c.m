clear all;
clc;
format long;

syms x
f=x^2-sin(x)-50;
df=diff(f,x);
a=0;
b=8;
x0=2;
x_ex= vpasolve(f==0,x,[a,b]);
tol=3*10^(-3);
[Solution,tables]=Bai6a_b(f,a,b,tol)


