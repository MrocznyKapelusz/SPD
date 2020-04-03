#include "klasa.h"
#include <algorithm>

int koniec(int n, RPQ* kolejnosc) //obliczanie wyniku końcowego
{
	int *a = new int;
	int *c = new int;
	*a = 0;
	*c = 0;
	for(int i = 0; i < n; ++i)
	{
		*a = std::max((kolejnosc + i)->R, * a) + (kolejnosc + i)->P;
		*c = std::max(*c, *a + (kolejnosc + i)->Q);
	}
	int koniec = *c;
	delete a;
	delete c;
	return koniec;
}

void RPQswap(RPQ* el1, RPQ* el2) //swap dla obiektów klasy RPQ
{
	RPQ pom(0, 0, 0);
	pom.R = el1->R;
	pom.P = el1->P;
	pom.Q = el1->Q;
	el1->R = el2->R;
	el1->P = el2->P;
	el1->Q = el2->Q;
	el2->R = pom.R;
	el2->P = pom.P;
	el2->Q = pom.Q;
}

void RPQ_BubbleSort(int n, RPQ* arr,char choice)//choice - po jakim kryterium sortujemy 
{
	switch (choice)
	{
	case 'R':
		for (int i = 0; i < n - 1; i++)
		{
			// Last i elements are already in place  
			for (int j = 0; j < n - 1; j++)
			{
				if ((arr+j)->R > (arr+j + 1)->R)
					RPQswap(&arr[j], &arr[j + 1]);
			}
		}
		break;

	case 'Q': //od wartości stosunek sortujemy malejąco po Q

		for (int i = stosunek(n,arr); i < n - 1; i++)
		{
			// Last i elements are already in place  
			for (int j = stosunek(n,arr); j < n - 1; j++)
			{
				if ((arr + j)->Q < (arr + j + 1)->Q)
					RPQswap(&arr[j], &arr[j + 1]);
			}
		}
		break;
	}
}

/*
stosunek zlicza wszystkie czasy oczekiwania i stygnięcia z zestawu danych i oblicza gdzie zrobić "punkt przegięcia", 
gdzie zaczynamy sortować po Q
*/
int stosunek(int n, RPQ* tab) 
{
	int sum_R = 0;
	int sum_Q = 0;
	for (int i = 0; i < n; i++)
	{
		sum_R += (tab + i)->R;
		sum_Q += (tab + i)->Q;
	}
	double zwr = double(sum_R) / double(sum_Q)* n/2;
	return (int)zwr;
}

void RPQ_Sort(int n, RPQ* tab)
{	
	RPQ_BubbleSort(n, tab, 'R');
	RPQ_BubbleSort(n, tab, 'Q');
}
