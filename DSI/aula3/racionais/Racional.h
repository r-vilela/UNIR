typedef struct{
    int Num, Den;
}Racional;

Racional Define(int N, int D);

Racional Soma(Racional R1, Racional R2);

Racional Multiplica(Racional R1, Racional R2);

int TestaIgualdade(Racional R1, Racional R2);

void Exibir(Racional r);
