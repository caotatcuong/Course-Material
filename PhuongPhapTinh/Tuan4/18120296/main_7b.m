clear all
clc
format long

syms x
f=2^x+3^x-10*x-30;
a=-4;
b=-2;
tol=2*10^(-3);
[Solution,tables] = Bai6a_b(f,a,b,tol) 