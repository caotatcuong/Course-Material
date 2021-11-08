function [aEy,rEy] = bai12a(y, Xa, aEX)
syms x1 x2;
Df = subs(subs([diff(y,x1), diff(y,x2)], x1, Xa(1)), x2, Xa(2));
y_a = subs(subs(y,x1,Xa(1)), x2, Xa(2));
S=0;
for i = 1:2
    S=S+abs(Df(i))*aEX(i); 
end
aEy=S;
rEy = S/abs(y_a);
end

