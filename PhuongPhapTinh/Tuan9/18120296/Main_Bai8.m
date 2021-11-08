clear all; clc;
xx = [ 0.9; 1; 1.1; 1.2];
yy = [ 0.7833; 0.8415; 0.8912; 0.9320];
df_ = 0.5403;

fprintf("Sai phan 3 diem cuoi\n");
[df,rEdf] = DaoHam(xx,yy,3,2,df_)

fprintf("Sai phan 3 diem giua\n");
[df,rEdf] = DaoHam(xx,yy,4,2,df_)