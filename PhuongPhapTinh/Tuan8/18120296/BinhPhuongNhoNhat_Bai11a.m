function [yc] = BinhPhuongNhoNhat_Bai11a(xx, yy, xc)
    temp=xx;
    xx=xx.^2;
    N=length(xx); X=sum(xx); Y=sum(yy);
    XX=sum(xx.*xx); XY=sum(xx.*yy);
    
    syms a b
    [a,b] = solve(XX*a + X*b == XY, X*a + N*b == Y);
    
    syms x
    R = a*x^2 + b;
    yc = double(subs(R,x,xc));
    
    ezplot(R,[temp(1) temp(end)]);
    hold on; plot(temp, yy, '-r');
    temp = [temp xc];
    yy = [yy yc];
    temp = temp';
    yy = yy';
    T = table(temp, yy)
end

