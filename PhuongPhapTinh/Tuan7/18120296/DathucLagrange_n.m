function [yc] = DathucLagrange_n(xx, yy, xc)
format long;
syms x;

n = length(xx);
L = 0;
for i = 0: n-1
    L0 = 1;
    for j = 1: n
        if i+1 == j
            continue;
        end
        L0 = (L0*(x-xx(j)))/((xx(i+1)-xx(j)));
    end
    L = L + yy(i+1)*L0;
end

yc = double(subs(L,x,xc));
ezplot(L, [xx(1), xx(end)]);
hold on
plot(xx, yy, '-r');

xx = xx';
yy = yy';
xx(end+1) = xc;
yy(end+1) = yc;
T = table(xx, yy)
end