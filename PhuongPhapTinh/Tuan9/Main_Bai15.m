clear all; clc;
fprintf("Giai lai bai 5\n");
syms x
f = @(x) (exp(x));
a=[2,4];
I_ex = double(int(f(x),a))

I2 = Gauss(f,a,4)
rEI2 = abs((I_ex - I2)/I_ex)

fprintf("Giai lai bai 6\n");
f1 = @(x) (sin(x));
a1=[0,pi];
I_ex = double(int(f1(x),a1))


I2 = Gauss(f1,a1,4)
rEI = abs((I_ex - I2)/I_ex)