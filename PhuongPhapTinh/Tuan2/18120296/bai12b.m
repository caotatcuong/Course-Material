function [aEy,rEy] = bai12b(y, Xa, aEX)
syms x1 x2 x3;
Df = subs(subs(subs([diff(y,x1), diff(y,x2), diff(y,x3)], x1, Xa(1)), x2, Xa(2)), x3, Xa(3));
y_a = subs(subs(subs(y,x1,Xa(1)), x2, Xa(2)),x3,Xa(3));
S=0;
for i = 1:3
    S=S+abs(Df(i))*aEX(i); 
end
aEy=S;
rEy = aEy/abs(y_a);
end


