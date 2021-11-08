clear all;
clc;
format long;

syms x
f=sin(x)-exp(-x);
df=diff(f,x);
a=0;
b=1;
x0=0.5;
x_ex= vpasolve(f==0,x,[a,b]);
tol=10^(-3);
[Solution,tables]=Bai4a_b(f,df,a,b,x0,x_ex,tol)


