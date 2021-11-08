%Test lai cac cau a, b, c trong bai 13
clear all;
clc;

%Cau a
syms(sym('x',[1 4]))
y1 = x1 + x2
[aEy,rEy]=bai12a(y1,[5,3],[0.03,0.06])

%Cau b
y2 = x1 + x2 + x3
[aEy,rEy]=bai12b(y2,[5,3,4],[0.03,0.06,0.09])

%Cau c
y3 = x1 + x2 + x3 + x4
[aEy,rEy]=bai12c(y3,4,[5,3,4,7],[0.03,0.06,0.09,0.05])