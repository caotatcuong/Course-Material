clear all; clc;
format long

xx = [1 2.2 3.1 4];
yy = [1.678 3.267 2.198 3.787];
xc = 2.5;
yc = DaThucNewton_n(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end
