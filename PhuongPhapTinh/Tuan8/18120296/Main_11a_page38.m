clear all; clc;
format long
syms x
fx=0.5*x^2+1.5;
xx = [2 4 7 8.5 9.5 11];
yy = double(subs(fx,x,xx));
xc = 6;

yc = BinhPhuongNhoNhat_Bai11a(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end