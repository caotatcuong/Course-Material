clear all; clc;
format long;

xx = [1, 2.2, 3.2, 4];
yy = [1.678, 3.267, 2.198, 3.787];
xc = 2.5;
[y] = DathucLagrange(xx, yy, xc)
