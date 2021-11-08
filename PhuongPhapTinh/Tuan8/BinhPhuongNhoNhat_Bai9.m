function [yc] = BinhPhuongNhoNhat_Bai9(xx, yy, xc)
    N=length(xx); X=sum(xx); Y=sum(yy);
    XX=sum(xx.*xx); XY=sum(xx.*yy);
    
    syms a b
    [a,b] = solve(XX*a + X*b == XY, X*a + N*b == Y);
    
    syms x
    R = a*x+b;
    yc = double(subs(R,x,xc));
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx, yy, '-r');
    xx = [xx xc];
    yy = [yy yc];
    xx = xx';
    yy = yy';
    T = table(xx, yy)
end

