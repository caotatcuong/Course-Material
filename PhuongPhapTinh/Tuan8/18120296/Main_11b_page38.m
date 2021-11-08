clear all; clc;
format long
syms x
fx=2*x^1.3;
xx = [2 4 7 8.5 9.5 11];
yy = double(subs(fx,x,xx));
xc = 6;

yc = BinhPhuongNhoNhat_Bai11b(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end