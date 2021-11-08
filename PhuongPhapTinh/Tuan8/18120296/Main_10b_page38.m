clear all; clc;
format long

xx = [2 4 7 8.5 9.5 11];
yy = [2.2 2.5 2.7 3.1 3.2 3.5];
xc = 7.7;

yc = BinhPhuongNhoNhat_Bai10(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end