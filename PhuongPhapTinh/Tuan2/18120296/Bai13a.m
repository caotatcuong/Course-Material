clear all;
clc;

syms x y
u = log(2*y + x^2);
u_e = double(subs(u,[x,y],[1.976,0.532]));
u_a = round(u_e,3);
aEu = abs(u_e - u_a);
rEu = aEu / abs(u_e);

fprintf('Sai so tuyet doi gioi han: %f\n', aEu);
fprintf('Sai so tuong doi gioi han: %f\n', rEu);