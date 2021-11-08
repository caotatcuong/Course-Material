function [yc] = BinhPhuongNhoNhat_Bai11b(xx, yy, xc)   
    temp=xx;
    syms a b
    xx=xx.^b;
    N=length(xx); X=sum(xx); Y=sum(yy);
    XX=sum(xx.*xx); XY=sum(xx.*yy);
    
    [a,b] = solve(XX*a == XY);

    syms x
    R = a*x^b;
    yc = double(subs(R,x,xc));
    
    ezplot(R,[temp(1) temp(end)]);
    hold on; plot(temp, yy, '-r');
    temp = [temp xc];
    yy = [yy yc];
    temp = temp';
    yy = yy';
    T = table(temp, yy)
end

