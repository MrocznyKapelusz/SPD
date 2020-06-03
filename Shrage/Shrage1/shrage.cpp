#include "shrage.h"
#include <algorithm>




int calculateC_MAX(std::vector<Job>& tasks) {
    int m = 0, c = 0;
    for (int i = 0; i < tasks.size(); i++) {
        m = std::max(tasks[i].R, m) + tasks[i].P;
        c = std::max(c, m + tasks[i].Q);
    }
    return c;
}




/*
 Funkcja znajduje indexy dostępnych zadań w danym przedziale czasu
 do tej fuunkcji trzeba przekazać vector prac z usunietymi pracami które zostały wykonane
*/

std::vector<int> getIndiciesAvailableJobs(std::vector<Job>& jobs, int czasTeraz) {
    std::vector<int> result;
    for (int i = 0; i < jobs.size(); i++) {
        if (jobs[i].R <= czasTeraz) {
            result.push_back(i);
        }
    }

    return result;
}

// Funkcja dodaje zadanie o największym Q do vectora result
// zwraca kolejność uszeregowania
        // TODO: to nie musi nic zwracać bo i tak operuje na refernecji
std::vector<Job>& addNewJobWithBiggestQ(std::vector<Job>& jobs, std::vector<int>& availbleTasksIndices,
    std::vector<Job>& resultJobs, int& czasTeraz) {

    int biggestQIndex = availbleTasksIndices[0];
    int biggestQ = jobs[biggestQIndex].Q;

    for (int index : availbleTasksIndices) {
        if (biggestQ < jobs[index].Q) {
            biggestQ = jobs[index].Q;
            biggestQIndex = index;

        }
        else if (biggestQ == jobs[index].Q) { // jeżeli takie same Q to bierzemy o mniejszym indexie początkowym

            if (jobs[biggestQIndex].initialIndex > jobs[index].initialIndex) {
                biggestQ = jobs[index].Q;
                biggestQIndex = index;
            }
        }
    }




    resultJobs.push_back(jobs[biggestQIndex]);
    czasTeraz += jobs[biggestQIndex].P;

    //jobs.erase(jobs.begin() + biggestQIndex -1);  // munmap_chunk(): invalid pointer // to przez tą minus jedynke

    jobs[biggestQIndex].R = std::numeric_limits<int>::max(); // podmieniamy wartość R zadania które własnie dodaliśmy do kolekcji result.
    // powodem tej podmiany jest to że keidy usuwaliśmy za pomocą erase() to wylatywał nam wyjątek munmap_chunk();

    return resultJobs;
}