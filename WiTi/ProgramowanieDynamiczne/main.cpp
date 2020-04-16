// ProgramowanieDynamiczne.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <ctime>

int Solve(int* pi, int* wi, int* di,int iloscDanych)
{
    // 2^n podzbiorow zbioru n elementowego
    int iloscPodzbiorow = static_cast<int>(pow(2.0, static_cast<double>(iloscDanych)));

    std::vector<int> Podzbiory(iloscPodzbiorow);

    Podzbiory[0] = 0; // first element has to be equal zero

    int CzasTrwaniaWPodzbiorze = 0;

    for (int subSetIndex = 1; subSetIndex < iloscPodzbiorow; subSetIndex++) {
        CzasTrwaniaWPodzbiorze = 0;

        for (int i = 0, b = 1; i < iloscDanych; i++, b *= 2) {
            /*
            parameter i is task index in tables,
            parameter b is consecutive power of 2  (eg. for 10 input data: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024)
            */
            if (subSetIndex & b) CzasTrwaniaWPodzbiorze += *(pi+i); // porównanie bitowe - dodajemy tylko te, które są w podzbiorze (nie odejmujemy tych, których nie ma)
        }
        //std::cout << CzasTrwaniaWPodzbiorze << "\n";

        Podzbiory[subSetIndex] = std::numeric_limits<int>::max();

        for (int i = 0, b = 1; i < iloscDanych; i++, b *= 2) {
            if (subSetIndex & b) {
                // PD algorithm
                Podzbiory[subSetIndex] = std::min(
                    Podzbiory[subSetIndex],
                    Podzbiory[subSetIndex - b] + *(wi+i) * std::max(0, CzasTrwaniaWPodzbiorze - *(di+i)));
            }
        }
    }
    
    int solution = Podzbiory.back();
    Podzbiory.clear();
    return solution;
}



int main() {
    clock_t poczatek=0;
    clock_t koniec=0;

    std::ifstream plik("witi.data.txt");
    int iloscDanych = 0;

    const int MAX_ILOSC_DANYCH = 20;
    int Pi[MAX_ILOSC_DANYCH],
        Wi[MAX_ILOSC_DANYCH],
        Di[MAX_ILOSC_DANYCH];

    std::string line;

    std::cout << "Hello World!" << std::endl;

    if (!plik.is_open()) throw std::runtime_error("Nie mozna otworzyc pliku");

    for (int dataIndex = 10; dataIndex <= 20; dataIndex++) {
        while (getline(plik, line) && (line != "data." + std::to_string(dataIndex) + ":")); // skip useless data
        plik >> iloscDanych;
        try
        {
            if (iloscDanych == 0) throw std::runtime_error(std::string("Nie mozna odczytac danych z pliku"));
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << "\n";
            exit(-1);
        }
        for (int i = 0; i < iloscDanych; i++) {
            plik >> Pi[i]
                >> Wi[i]
                >> Di[i];
        }

        
        int rozw = Solve(Pi, Wi, Di, iloscDanych);

        koniec = clock();
        double czasDzialania = double(koniec - poczatek) / (CLOCKS_PER_SEC / 1000);
        std::cout << "data." << dataIndex
            << "      Rozwiązanie optymalne: " << rozw
            << "      Czas działania algorytmu: " << czasDzialania << " mili-sec.\n";
        //Podzbiory.clear();
    }


    plik.close();
       
}
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
