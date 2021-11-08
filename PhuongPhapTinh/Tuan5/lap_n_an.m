function[Xn,fX,rEx] = lap_n_an(A,C,tol)
n=size(C,1);
B=-A./diag(A) +eye(n);
G=C./diag(A);
Xo =G;
k = 1;
while 1
    Xn = B*Xo + G;
    rEx = norm((Xn-Xo)./Xo);
    fX = norm(A*Xn - C);
    if abs(fX) <= tol, break, end;
    Xo = Xn;
    k = k+1;
end;