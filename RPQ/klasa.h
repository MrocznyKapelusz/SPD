#pragma once
#define PRZYG 'R'

struct RPQ
{
	int R;
	int P;
	int Q;

	RPQ()
	{
		R = 0;
		P = 0;
		Q = 0;
	}

	RPQ(int R1, int P1, int Q1)
	{
		R = R1;
		P = P1;
		Q = Q1;
	}
};

int koniec(int n, RPQ kolejnosc[]);
void RPQ_BubbleSort(int n, RPQ* arr, char choice);
void RPQ_Sort(int n, RPQ* tab);
void RPQswap(RPQ* el1, RPQ* el2);
int stosunek(int n, RPQ* tab);