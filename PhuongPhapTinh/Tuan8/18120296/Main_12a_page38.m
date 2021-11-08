clear all; clc;
format long
syms x
fx=0.3*x^2+0.7*x-2.5;
xx = [2 4 7 8.5 9.5 11];
yy = double(subs(fx,x,xx));
xc = 6;

yc = BinhPhuongNhoNhat_Bai12a(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end