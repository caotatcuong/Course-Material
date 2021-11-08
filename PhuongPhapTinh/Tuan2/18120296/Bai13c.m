clear all;
clc;

syms x y
u = x * tan(y) + (x + y)^2;
u_e = double(subs(u,[x,y],[-1.395,1.643]));
u_a = round(u_e,3);
aEu = abs(u_e - u_a);
rEu = aEu / abs(u_e);

fprintf('Sai so tuyet doi gioi han: %f\n', aEu);
fprintf('Sai so tuong doi gioi han: %f\n', rEu);