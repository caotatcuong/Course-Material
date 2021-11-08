clear all; clc;
xx = [ 1; 2; 3; 4; 5; 6; 7];
yy = [ 4; -6; -14; -14; 0; 34; 94];
I_ = 42;
xx1 = [-2; -1; 0; 1; 2; 3; 4];
yy1 = [24; 1; 4; 3; -8; -11; 36];
I_1 = 7.2;

fprintf("Giai lai bai 3\n");
[I,rEdf] = Simpson3_8(xx,yy,I_)

fprintf("Giai lai bai 4\n");
[I,rEdf] = Simpson3_8(xx1,yy1,I_1)