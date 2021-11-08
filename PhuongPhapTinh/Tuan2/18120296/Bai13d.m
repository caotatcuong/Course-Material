function [aEu,rEu] = Bai13d(u, n, X)
x=(sym('x',[1 n]));
u_e = double(subs(u,x,X));
u_a = round(u_e,3);
aEu = abs(u_e - u_a);
rEu = aEu / abs(u_e);
end

