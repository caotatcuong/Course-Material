function [Solution,tables] = Bai6a_b(f,a,b,tol)
format long
syms x
k=1;
N0=[];
c=[];
fc=[];
rEc=[];
condition=[];
list_a=a;
list_b=b;
while 1;
    Solution=vpa(a-((b-a)/(subs(f,x,b)-subs(f,x,a)))*subs(f,x,a));
    c=double([c;Solution]);
    f_Solution=vpa(subs(f,x,Solution));
    fc=double([fc;f_Solution]);
    rEc=double([rEc;abs((a-Solution)/Solution)]);
    N0=[N0;k];
    if abs(f_Solution) <= tol
        condition=[condition;1];
        break; 
    else
        condition=[condition;0];
    end
    if subs(f,x,a)*subs(f,x,Solution)>0,a=Solution; else b=Solution; end;
    list_a=double([list_a;a]);
    list_b=double([list_b;b]);
    k=k+1;
end
condition=logical(condition);
tables = table(N0,list_a,list_b, c, fc, condition, rEc);

hold on 
grid on
for i = 1:length(c)
    if (i==length(c))
        plot(c(i), fc(i),'r*','LineWidth',1.5);
    end
    plot(c(i), fc(i),'g*');
end
grp1=fplot(f,'c');
grp2=plot([0 0],'b--');
xlabel('x-axis');
ylabel('y-axis');
legend([grp1 grp2], {'f-function', 'line y = 0'});
end


