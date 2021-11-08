function [Xn,fX,rEx] = seidel_n_an(A,C,tol)
n=size(C,1);
B = -A./diag(A)+eye(n);
G = C./diag(A);
Xo = G;
k = 1;
Xn=Xo;
while 1
    Xn(1) = B(1,:)*Xo+G(1);
    for i = 2:length(Xn)
        X_temp=Xn;
        Xn(i)=0;
        for j = 1:length(B)
            Xn(i) = Xn(i) + B(i,j)*X_temp(j);
        end;
        Xn(i) = Xn(i)+G(i);
    end;   
    rEx = norm((Xn-Xo)./Xo);
    fX = norm(A*Xn-C);
    if abs(fX)<=tol, break, end
    Xo = Xn;
    k = k+1;
end