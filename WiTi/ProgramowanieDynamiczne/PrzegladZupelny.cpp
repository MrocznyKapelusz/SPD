#include "PrzegladZupelny.h"

 void swap(int& a, int& b)
{
    int c = a; a = b; b = c;
}

int Kara(int* P, int* W, int* D, int T[])
{
    int kara = 0;
    for (int i = 0; i < N; ++i)
    {
        int j = T[i];
        int tmp = 0;
        if ((tmp + (*(P + j)))-(*(D+j)))
        {
            kara += ((tmp + (*(P + j))) - (*(D + j))) * (*(W + j));
        }
        tmp += *(P + j);
    }
    return kara;
}

void out(int T[], int *min,int *P, int* W, int* D, int rozw[])
{
    if (Kara(P, W, D, T) < *min)
    {
        *min = Kara(P, W, D, T);
        for (int i = 0; i < N; i++)
        {
            rozw[i] = T[i];

        }
    }
    
}

void permutacje(int T[N], int ix,int *min,int *P,int* W,int *D,int rozw[]) // ix = 0..N-1
{
    if (ix < N - 1)
    {
        for (int i = ix; i < N; i++)
        {
            swap(T[ix], T[i]); // zamienia dwa elementy miejscami
            permutacje(T, ix + 1,min,P,W,D,rozw);
            swap(T[ix], T[i]); // przywracamy
        }
    }
    else out(T,min,P,W,D,rozw); // drukujemy wszystkie elementy

}

void SolvePZ(int* pi, int* wi, int* di)
{
    int T[N];
    int rozw[N];
    for (int i = 0; i < N; ++i)
    {
        T[i] = i;
    }
    int MIN = INT_MAX;
    permutacje(T, 0, &MIN, pi, wi, di, rozw);
    std::cout << "ROZWIĄZANIE OPTYMALNE:";
    for (int i = 0; i < N; i++)
    {
        std::cout << rozw[i] << " ";
    }
    std::cout << "Koszt: " << MIN<<"\n";
}