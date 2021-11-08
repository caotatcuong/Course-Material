clear all
clc
format long

syms x
f=log(x-1)+cos(x-1);
a=1.2;
b=2;
tol=10^(-3);
[Solution,tables] = Bai6a_b(f,a,b,tol) 
