clear all; clc;
format long

xx = [1 1.6 2.1 3 3.3 3.7 4.1 4.9 6.2];
yy = [1.1 2.2 3.5 4.9 7.2 7.8 7.9 8.5 10];
xc = 3.5;

yc = BinhPhuongNhoNhat_Bai9(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end