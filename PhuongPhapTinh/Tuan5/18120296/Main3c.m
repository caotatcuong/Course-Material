clear all; clc;
format long;

A = [5 1 1;1 10 1;1 1 20];
C = [7;12;22];
tol = 10^(-3);
fprintf("Phuong phap lap\n");
[Xn,fX,rEx] = lap_n_an(A,C,tol)


