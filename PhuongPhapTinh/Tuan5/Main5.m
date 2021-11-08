clear all; clc;
format long;

A = [6 1 1 1;2 9 3 1;2 1 10 4; 1 2 1 8];
C = [9;1;-12;-12];
tol = 10^(-3);
fprintf("Giai 4 phuong trinh 4 an\n");

fprintf("Phuong phap lap\n");
[Xn,fX,rEx] = lap_n_an(A,C,tol)

fprintf("Phuong phap seidel\n");
[Xn,fX,rEx] = seidel_n_an(A,C,tol)