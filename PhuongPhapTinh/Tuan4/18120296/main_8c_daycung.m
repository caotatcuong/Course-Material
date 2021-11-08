clear all
clc
format long

syms x
f=(x-2)^2-log(x);
a=1;
b=2;
tol=10^(-3);
[Solution,tables] = Bai6a_b(f,a,b,tol) 
