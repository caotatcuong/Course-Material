clear all; clc;
format long

xx = [1.1 3.2 5.1 7.7 9.6 12.2];
yy = [3.1 29.9 65.7 100.4 195.7 300.4];
xc = 8.5;

yc = BinhPhuongNhoNhat_Bai10(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end