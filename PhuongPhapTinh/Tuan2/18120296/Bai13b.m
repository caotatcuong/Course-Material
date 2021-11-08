clear all;
clc;

syms x y
u = y * exp(x) - x^2;
u_e = double(subs(u,[x,y],[1.675,1.073]));
u_a = round(u_e,3);
aEu = abs(u_e - u_a);
rEu = aEu / abs(u_e);

fprintf('Sai so tuyet doi gioi han: %f\n', aEu);
fprintf('Sai so tuong doi gioi han: %f\n', rEu);