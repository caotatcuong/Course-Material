clear all
clc
format long

syms x
f=exp(x)+2^(-x)+2*cos(x)-6;
a=1;
b=2;
tol=10^(-3);
[Solution,tables] = Bai6a_b(f,a,b,tol) 
