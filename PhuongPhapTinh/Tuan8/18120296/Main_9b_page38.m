clear all; clc;
format long

xx = [1 2.1 2.9 3.8 5 6.2];
yy = [3.021 4.219 5.018 5.986 7.139 8.138];
xc = 4.5;

yc = BinhPhuongNhoNhat_Bai9(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end