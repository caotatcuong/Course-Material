%Thuc hien lai cac cau a, b, c trong bai 13
clear all;
clc;

%Cau a
syms(sym('x',[1 2]))
u1 = log(2*x2 + x1^2)
[aEu,rEu] = Bai13d(u1,2,[1.976, 0.532]);

fprintf('Sai so tuyet doi gioi han: %f\n', aEu);
fprintf('Sai so tuong doi gioi han: %f\n', rEu);

% Cau b
u2 = x2 * exp(x1) - x1^2
[aEu,rEu] = Bai13d(u2,2,[1.675, 1.073]);

fprintf('Sai so tuyet doi gioi han: %f\n', aEu);
fprintf('Sai so tuong doi gioi han: %f\n', rEu);

% Cau c
u3 = x1 * tan(x2) + (x1 + x2)^2
[aEu,rEu] = Bai13d(u3,2,[-1.395, 1.643]);

fprintf('Sai so tuyet doi gioi han: %f\n', aEu);
fprintf('Sai so tuong doi gioi han: %f\n', rEu);
