clear all; clc;
xx = [ 0.9; 1; 1.1; 1.2];
yy = [ 0.7833; 0.8415; 0.8912; 0.9320];
df_ = 0.5403;

fprintf("Sai phan tien\n");
[df,rEdf] = DaoHam(xx,yy,1,2,df_)

fprintf("Sai phan lui\n");
[df,rEdf] = DaoHam(xx,yy,2,2,df_)

