clear all; clc;
format long

xx = [3 3.4 4.1 4.3 4.7 5.3 5.3 6 6.4];
yy = [1.23 1.40 1.69 1.79 2.13 2.52 2.45 2.97 3.44];
xc = 5;

yc = BinhPhuongNhoNhat_Bai10(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end