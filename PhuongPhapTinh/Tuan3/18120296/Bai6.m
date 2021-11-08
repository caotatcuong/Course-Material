function [Solution,tables] = Bai6(f,g,a,b,x0,x_ex,tol)
format long
syms x
k=1;
N0 = k;
xn=x0;
rEx=abs((x_ex-x0)/x_ex);
f_xn=double(subs(f,x,x0));
if (abs(subs(f,x,x0))<=tol)
    condition=1;
else
    condition=0;
end
while(abs(subs(f,x,x0)) > tol && k<=200)
    x0=subs(g,x,x0);
    k=k+1;
    N0 = double([N0;k]);
    xn=double([xn;x0]);
    f_xn=double([f_xn; subs(f,x,x0)]);
    if(abs(subs(f,x,x0))<=tol)
        condition=double([condition; 1]);
    else
        condition=double([condition; 0]);
    end
    rEx=double([rEx;abs((x_ex-x0)/x_ex)]);
end
Solution = double(x0);
condition=logical(condition);
tables = table(N0,xn,f_xn, condition, rEx);
hold on 
grid on
for i = 1:length(xn)
    if (i==length(xn))
        plot(xn(i), f_xn(i),'r*','LineWidth',1.5);
    end
    plot(xn(i), f_xn(i),'g*');
end
grp1=fplot(f,[a,b],'c');
grp2=plot([a,b],[0 0],'b--');
xlabel('x-axis');
ylabel('y-axis');
legend([grp1 grp2], {'f-function', 'line y = 0'});
end


