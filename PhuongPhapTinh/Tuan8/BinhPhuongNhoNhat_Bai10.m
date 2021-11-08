function [yc] = BinhPhuongNhoNhat_Bai10(xx, yy, xc)
    N=length(xx); X=sum(xx); lY=sum(log(yy));
    XX=sum(xx.*xx); XlY=sum(xx.*log(yy));
    
    syms a b
    [a,b] = solve(XX*a + X*b == XlY, X*a + N*b == lY);
    
    syms x
    R = exp(b)*exp(a*x);
    yc = double(subs(R,x,xc));
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx, yy, '-r');
    xx = [xx xc];
    yy = [yy yc];
    xx = xx';
    yy = yy';
    T = table(xx, yy)
end

