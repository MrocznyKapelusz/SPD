#include<iostream>
#include<fstream>
#include<string>
#include "dane.h"

int main()
{
	const int LICZBA_ZESTAWOW = 1;
	const int MAX_LICZBA_ZADAN = 100;
	
	int liczba_zadan;
	int Pi[MAX_LICZBA_ZADAN], //czas trwania zadania
		Wi[MAX_LICZBA_ZADAN], //waga zadania
		Di[MAX_LICZBA_ZADAN]; //zadany czas zakończenia
	for (int k = 10; k < LICZBA_ZESTAWOW+10; k++)
	{
		wczytaj_dane("witi.data.txt", k, &liczba_zadan, Pi, Wi, Di);
		for (int i = 0; i < liczba_zadan; ++i)
		{
			std::cout << Pi[i] << " " << Wi[i] << " " << Di[i] << "\n";
		}
	}	
	return 0;
}