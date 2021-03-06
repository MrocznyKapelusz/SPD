﻿#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "shrage.h"


int main(int argc, char** argv) {

    std::vector<Job> jobs, result;
    Job tmpJob;

    std::ifstream plik("schr.data.txt");
    int quantityOfData = 0;

    std::string line;

    std::cout << "Hello world!\n";

    if (!plik.is_open()) throw std::runtime_error("Could not open file");

    std::string currentDataSet;

    for (int dataSetIndex = 0; dataSetIndex <= 8; dataSetIndex++) {

        currentDataSet = "data.00" + std::to_string(dataSetIndex) + ":";

        while (getline(plik, line) && (line != currentDataSet)); // skip useless data
        plik >> quantityOfData;
        try
        {
            if (quantityOfData == 0) throw std::runtime_error(std::string("Could not read data from file. (probably inappropriate end of line character in variable currentDataSet)\n") +
                "Try \\n, \\n\\r, \\r, or none");
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << "\n";
            exit(-1);
        }

        // read data

        for (int i = 0; i < quantityOfData; i++) {
            plik >> tmpJob.R >> tmpJob.P >> tmpJob.Q;
            tmpJob.initialIndex = i;

            jobs.push_back(tmpJob);
        }

        // Sortuj vector prac po R rosnąco

        std::sort(jobs.begin(), jobs.end(), [](const Job& first, const Job& second) { return first.R < second.R; });


        // Pierwsze dostępne zadanie będzie zadaniem o najmniejszym R
        // dostępne w czasTeraz równym jego R 
        Job jobWithSmallestR = jobs[0];
        int czasTeraz = jobWithSmallestR.R;

        int iloscZadanPocz = jobs.size();
        std::vector<int> zadaniaDostepne;

        // Shrange zwykłe

        // wykonujemy dopóki w kolekcji result jest mniej prac niż prac wczytanych

        while (result.size() != iloscZadanPocz) {

            //Znajdz indeksy zadan ktorych R jest mniejsze niż czasTeraz i nie były jeszcze dodane

            zadaniaDostepne = getIndiciesAvailableJobs(jobs, czasTeraz);

            //Jeśli żadne zadanie nie jest dostępne to 'pójdź' do niego
            if (zadaniaDostepne.size() == 0) {
                // W tym przypadku znaleźć pierwsze większe R niz czasTeraz z vectora jobs i przypisac je do elapsed time
                for (int i = 0; i < jobs.size(); i++) {
                    if (jobs[i].R > czasTeraz && (jobs[i].R != std::numeric_limits<int>::max())) {
                        czasTeraz = jobs[i].R;
                        // kiedy znaleźliśmy następne czasTeraz dla którego będą jakieś zadania, to ponownie wyszukujemy dostępne zadania
                        zadaniaDostepne = getIndiciesAvailableJobs(jobs, czasTeraz);
                        break;
                    }
                }
            }

            // 
            // 1. dodajemy zadanie o najwiekszym Q do kolekcji result
            // 2. zwiększamy elapsed time o czas trwania zadania, które dodaliśmy do kolekcji result
            // 3. Wartość R zadania zmieniamy na MAX_INT, aby lądowało zawsze na końcu.
            result = addNewJobWithBiggestQ(jobs, zadaniaDostepne, result, czasTeraz);

        }



        /*
            for (auto &obj : result){
                obj.showJob();
            }
        */

        int C_max = calculateC_MAX(result);

        std::cout << "\n Current data set:" << dataSetIndex << " C_max = " << C_max << "\n";
        for (auto& obj : result) {
            std::cout << obj.initialIndex + 1 << ", ";
        }
        std::cout << "\n";

        result.clear();
        jobs.clear();
    }


    return 0;
}
