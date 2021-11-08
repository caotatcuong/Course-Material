function [yc] = BinhPhuongNhoNhat_Bai12a(xx, yy, xc)
    N=length(xx); X=sum(xx); Y=sum(yy);
    XX=sum(xx.*xx); XY=sum(xx.*yy);
    XXX=sum(xx.^3);XXXX=sum(xx.^4);
    XXY=sum(xx.^2.*yy);
    
    syms a b c
    [a,b,c] = solve(XX*a + X*b + N*c==Y, XXX*a + XX*b + X*c==XY,  XXXX*a + XXX*b + XX*c==XXY);
    
    syms x
    R = a*x^2 + b*x + c;
    yc = double(subs(R,x,xc));
    
    ezplot(R,[xx(1) xx(end)]);
    hold on; plot(xx, yy, '-r');
    xx = [xx xc];
    yy = [yy yc];
    xx = xx';
    yy = yy';
    T = table(xx, yy)
end

