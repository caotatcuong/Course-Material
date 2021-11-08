clear all; clc;
format long;

A = [5 1 1;1 10 1;1 1 20];
C = [7;12;22];
tol = 10^(-3);

fprintf("Phuong phap seidel\n");
[Xn,fX,rEx] = seidel_n_an(A,C,tol)

