#include "dane.h"

void wczytaj(int* n,RPQ* tab, std::string wybor) //do n zapisujemy liczbę danych, zwracamy wskaźnik na tablicę obiektów RPQ
{
	//RPQ tab[99];
	std::fstream dane("data.txt");
	std::string s;
	while (s != wybor)dane >> s;
	dane >> *n;
	for (int i = 0; i < *n; i++)
	{
		dane >> (tab+i)->R;
		//std::cout << tab[i].R << " ";
		dane >> (tab + i)->P;
		//std::cout << tab[i].P << " ";
		dane >> (tab + i)->Q;
		//std::cout << tab[i].Q << "\n";
	}
}

void wypisz(int *n,RPQ* tab)
{
	for (int i = 0; i < *n; i++)
	{
		std::cout << (*(tab + i)).R << " " << (tab + i)->P << " " << (tab + i)->Q << "\n";
	}
}
