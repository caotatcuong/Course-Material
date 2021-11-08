function [yc] = BinhPhuongNhoNhat_Bai12b(xx, yy, xc)
    N=length(xx); X=sum(xx); Y=sum(yy);
    XX=sum(xx.*xx); XY=sum(xx.*yy);Xsin=sum(xx.*sin(xx));Xcos=sum(xx.*cos(xx));
    sin_2=sum(sin(xx).*sin(xx)); cos_2=sum(cos(xx).*cos(xx));
    sincos=sum(sin(xx).*cos(xx));
    Ysin=sum(sin(xx).*yy);Ycos=sum(cos(xx).*yy);
    syms a b c
    [a,b,c] = solve(XX*a + Xsin*b + Xcos*c==XY, Xsin*a + sin_2*b + sincos*c==Ysin,  Xcos*a + sincos*b + cos_2*c==Ycos);
    
    syms x
    R = a*x + b*sin(x) + c*cos(x);
    yc = double(subs(R,x,xc));
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx, yy, '-r');
    xx = [xx xc];
    yy = [yy yc];
    xx = xx';
    yy = yy';
    T = table(xx, yy)
end

