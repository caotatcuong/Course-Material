clear all; clc;
format long

xx = [-3.2 -2.5 -1.7 -0.8 0.3 1.5];

yy = [-8.982 -5.831 -4.261 -1.837 -3.298 -0.249];
xc = [-2 0];
yc = DaThucNewton_n(xx,yy,xc);
for i=1:length(xc)
    fprintf('Tai xc = %f thi yc = %f\n',xc(i),yc(i));
end
