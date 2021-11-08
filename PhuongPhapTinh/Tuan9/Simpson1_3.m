function [I,rEI] = Simpson1_3(xx,yy,I_)

I = 0;
n = length(xx);
for i = 3:2:n
    I = I + ((xx(i) - xx(i-2))/6)*(yy(i-2) + 4*yy(i-1) + yy(i));
end
rEI = abs((I_ - I)/I_);
end