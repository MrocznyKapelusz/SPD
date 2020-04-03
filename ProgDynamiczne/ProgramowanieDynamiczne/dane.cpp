#include "dane.h"

void wczytaj_dane(std::string plik,int zestaw,int* n, int* p, int* w, int* d)
{
	std::fstream plik_z_danymi;
	plik_z_danymi.open(plik);
	std::string s;
	while (getline(plik_z_danymi, s) && (s != "data." + std::to_string(zestaw) + ":")); //pomiń dane z innych zestawów
	plik_z_danymi >> *n;
	try
	{
		if (*n == 0)throw std::logic_error("Niepoprawna liczba zadan\n");
	}
	catch (std::logic_error& e)
	{
		std::cout << "Blad w zestawie danych:\n"<<e.what();
		exit(-1);
	}
	for (int i = 0; i < *n; ++i)
	{
		plik_z_danymi >>*(p+i)>> *(w+i) >> *(d+i);
	}
	plik_z_danymi.close();
}