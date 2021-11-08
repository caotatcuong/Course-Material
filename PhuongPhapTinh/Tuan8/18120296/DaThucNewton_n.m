function [yc] = DaThucNewton_n(xx, yy, xc)
    n = length(xx);
    TSP = [];
    TSP(1,:) = yy;
    for i=2:n
        for j=1:(n-i+1)
            TSP(i,j) = (TSP(i-1,j+1)-TSP(i-1,j)) / (xx(j+i-1)-xx(j));
        end
    end
    
    syms x;
    N = TSP(1,1);
    
    for i = 2:n
        tmp = 1;
        for j = 1:(i-1)
            tmp = tmp*(x-xx(j));
        end
        N = N + TSP(i,1)*tmp;
    end
    yc = double(subs(N, x, xc));
    ezplot(N,[xx(1) xx(end)]);
    hold on; plot(xx, yy, '-r');
        
    xx = [xx xc];
    yy = [yy yc];
    xx = xx';
    yy = yy';
    T = table(xx, yy)
end

