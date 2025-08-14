#include "Racional.h"
#include <stdio.h>

Racional Define(int N, int D){
    Racional r;
    r.Den = D;
    r.Num = N;
    return r;
};

Racional Soma(Racional R1, Racional R2){
    Racional r;
    r.Num=R1.Num*R2.Den+R1.Den*R2.Num;
    r.Den=R2.Den*R1.Den;

    return r;
};

Racional Multiplica(Racional R1, Racional R2){
    Racional r;
    r.Num=R1.Num*R2.Num;
    r.Den=R1.Den*R2.Den;

    return r;
};

int TestaIgualdade(Racional R1, Racional R2){
    return (R1.Num==R2.Num && R1.Den==R2.Den);
};

void Exibir(Racional R){
    printf("%d/%d\n", R.Num, R.Den);
}
