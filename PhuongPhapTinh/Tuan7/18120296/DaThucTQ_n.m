function[yc] = DaThucTQ_n(xx, yy, xc)
    format long;
    n = length(xx);
    X = zeros(n);
    for i = 1:n
        for j = 1:n
            X(i,j) = xx(i).^(j-1);
        end
    end
    Y = zeros(n, 1);
    for i = 1: n
        Y(i, 1) = yy(i);
    end
    A = inv(X)*Y;
    syms x;
    P = 0;
    for i = 1: n
        P = P + A(i)*x^(i-1);
    end
    yc = double(subs(P, x, xc));
    ezplot(P,[xx(1) xx(end)]);
    hold on; plot(xx, yy, '-r');
    
    xx = xx';
    yy = yy';
    xx(end+1) = xc;
    yy(end+1) = yc;
    T = table(xx, yy)
end