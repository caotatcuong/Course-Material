function [Solution,f_Solution] = Bai5(f,a,b,Df)
format long
syms x
k=1;
N0=[];
c=[];
fc=[];
rEc=[];
condition=[];
a_1=a;
b_1=b;
while 1;
    Solution=vpa((a_1+b_1)/2);
    c=double([c;Solution]);
    f_Solution=vpa(subs(f,x,Solution));
    fc=double([fc;f_Solution]);
    rEc=double([rEc;abs((a_1-Solution)/a_1)]);
    N0=[N0;k];
    if abs(f_Solution) <= Df
        condition=[condition;1];
        break; 
    else
        condition=[condition;0];
    end
    if subs(f,x,a_1)*subs(f,x,Solution)>0,a_1=Solution; else b_1=Solution; end;
    a=double([a;a_1]);
    b=double([b;b_1]);
    k=k+1;
end
condition=logical(condition);
tables = table(N0,a,b, c, fc, condition, rEc);
disp(tables)
end


