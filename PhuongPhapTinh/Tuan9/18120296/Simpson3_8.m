function [I,rEI] = Simpson3_8(xx,yy,I_)

I = 0;
n = length(xx);
for i = 4:3:n
    I = I + ((xx(i) - xx(i-3))/8)*(yy(i-3) + 3*yy(i-2) + 3*yy(i-1) + yy(i));
end
rEI = abs((I_ - I)/I_);
end

