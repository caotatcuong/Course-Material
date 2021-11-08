% Thuc hien lai bai tap 7
clear all;
clc;

syms(sym('x',[1 3]))
y1 = x1 + x2 * x3
[aEy,rEy]=bai12c(y1,3,[5,3,7],[0.03,0.06,0.04])

y2 = x1^2 + x2 * x3^3
[aEy,rEy]=bai12c(y2,3,[2,4,6],[0.05,0.02,0.03])

y3 = x3 * sqrt(x1 + x2)
[aEy,rEy]=bai12c(y3,3,[3,7,3],[0.05,0.07,0.02])

y4 = x1 * (x2 / x3)
[aEy,rEy]=bai12c(y4,3,[3,7,10],[0.08,0.03,0.1])

y5 = x1 * (x2 + x3) - x2 * x3
[aEy,rEy]=bai12c(y5,3,[8,4,3],[0.09,0.02,0.04])

y6 = log(x1 * x2 - x3)
[aEy,rEy]=bai12c(y6,3,[7,5,2],[0.05,0.02,0.03])

y7 = x1 * sin(x2) - cos(x3)
[aEy,rEy]=bai12c(y7,3,[3,0,1],[0.06,0.02,0.04])
