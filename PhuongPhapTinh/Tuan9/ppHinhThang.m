function [I,rEI] = ppHinhThang(xx,yy,I_)

I = 0;
n = length(xx);
for i = 2:n
    I = I + ((xx(i) - xx(i-1))/2)*(yy(i-1) + yy(i));
end
rEI = abs((I_ - I)/I_);
end

