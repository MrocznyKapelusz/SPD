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


int pomoc() {
    clock_t begin;
    clock_t end;

    std::ifstream myfile("witi.data.txt");
    int quantityOfData = 0;

    const int MAX_QUANTITY_OF_DATA = 20;
    int taskDurance[MAX_QUANTITY_OF_DATA],
        taskPriority[MAX_QUANTITY_OF_DATA],
        desirableDurance[MAX_QUANTITY_OF_DATA];

    std::string line;

    std::cout << "Hello World!" << std::endl;

    if (!myfile.is_open()) throw std::runtime_error("Could not open file");

    for (int dataIndex = 10; dataIndex <= 20; dataIndex++) {
        while (getline(myfile, line) && (line != "data." + std::to_string(dataIndex) + ":")); // skip useless data
        myfile >> quantityOfData;
        try
        {
            if (quantityOfData == 0) throw std::runtime_error(std::string("Could not read data from file. (probably inappropriate end of line character)\n") +
                "Try \\n, \\n\\r, \\r, or none");
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << "\n";
            exit(-1);
        }
        for (int i = 0; i < quantityOfData; i++) {
            myfile >> taskDurance[i]
                >> taskPriority[i]
                >> desirableDurance[i];
        }

        // estimate subsets quantity
        int subSetQuantity = static_cast<int>(pow(2.0, static_cast<double>(quantityOfData)));

        std::vector<int> subSetVector(subSetQuantity);

        subSetVector[0] = 0; // first element has to be equal zero

        int sumOfTasksDuranceInSubSet = 0;

        begin = clock();

        for (int subSetIndex = 1; subSetIndex < subSetQuantity; subSetIndex++) {
            sumOfTasksDuranceInSubSet = 0;

            for (int i = 0, b = 1; i < quantityOfData; i++, b *= 2) {
                /*
                parameter i is task index in tables,
                parameter b is consecutive power of 2  (eg. for 10 input data: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024)
                */

                if (subSetIndex & b) sumOfTasksDuranceInSubSet += taskDurance[i];
            }
            std::cout << sumOfTasksDuranceInSubSet << "\n";

            subSetVector[subSetIndex] = std::numeric_limits<int>::max();

            for (int i = 0, b = 1; i < quantityOfData; i++, b *= 2) {
                if (subSetIndex & b) {
                    // PD algorithm
                    subSetVector[subSetIndex] = std::min(
                        subSetVector[subSetIndex],
                        subSetVector[subSetIndex - b] + taskPriority[i] * std::max(0, sumOfTasksDuranceInSubSet - desirableDurance[i]));
                }
            }
        }
        end = clock();
        double elapsedTimeInMiliSeconds = double(end - begin) / (CLOCKS_PER_SEC / 1000);
        std::cout << "data." << dataIndex
            << "      Optimal time: " << subSetVector.back()
            << "      elapsed time: " << elapsedTimeInMiliSeconds << " mili-sec.\n";
        subSetVector.clear();
    }


    myfile.close();
       
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
