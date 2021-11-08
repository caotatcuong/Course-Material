function [df,rEdf] = DaoHam(xx,yy,k,k1,df_)
if k == 1 % Sai phan tien
    df = (yy(k1+1) - yy(k1))/(xx(k1+1) - xx(k1));
elseif k == 2 % Sai phan lui
    df = (yy(k1) - yy(k1-1))/(xx(k1) - xx(k1-1)); 
elseif k == 3 % Sai phan 3 diem cuoi
    df = (-3*yy(k1) + 4*yy(k1+1) - yy(k1+2))/(xx(k1+1) - xx(k1-1)); 
else %(k=4) Sai phan 3 diem giua
    df = (yy(k1+1) - yy(k1-1))/(xx(k1+1) - xx(k1-1)); 
end
rEdf = abs((df_ - df)/df_);
end

