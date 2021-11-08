function [aEy,rEy] = bai12c(y, n, Xa, aEX)
x=(sym('x',[1 n]));
Df=[];
for i = 1:n 
    Df = [Df,diff(y,x(i))];
end
df=[];
for i = 1:n 
    df = [df,subs(Df(i),x,Xa)];
end
Df=df;
S=0;
for i = 1:n
    S=S+abs(Df(i))*aEX(i); 
end
y_a=subs(y,x,Xa);
aEy=S;
rEy = aEy/abs(y_a);



