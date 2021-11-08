clear all
clc
format long

syms x
f=sin(x)-exp(-x);
a=0;
b=1;
tol=10^(-3);
[Solution,tables] = Bai6a_b(f,a,b,tol) 
