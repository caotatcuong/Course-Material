clear all; clc;
format long
syms x
fx=3*x+1.5*sin(x)-3.5*cos(x);
xx = [2 4 7 8.5 9.5 11];
yy = double(subs(fx,x,xx));
xc = 6;

yc = BinhPhuongNhoNhat_Bai12b(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end