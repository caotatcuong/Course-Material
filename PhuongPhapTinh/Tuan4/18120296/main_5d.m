clear all;
clc;
format long;

syms x
f=x+log(x+2)-10;
df=diff(f,x);
a=1;
b=10;
x0=3;
x_ex= vpasolve(f==0,x,[a,b]);
tol=5*10^(-3);
[Solution,tables]=Bai4a_b(f,df,a,b,x0,x_ex,tol)


