clear all; clc;
format long

xx = [2 4 7 8.5 9.5 11];
yy = [2.2 4.2 6.8 8.1 9.7 10.5];
xc = 6;

yc = BinhPhuongNhoNhat_Bai9(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end