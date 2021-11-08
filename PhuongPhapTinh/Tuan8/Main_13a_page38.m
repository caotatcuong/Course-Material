clear all; clc;
format long

xx = [2; 4; 7; 8];
yy = [2.2; 1.8; 2.7; 3.1];
xc = [3; 7.5];

yc = Spline_13a(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end