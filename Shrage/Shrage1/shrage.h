#include <vector>
#include <iostream>


class Job
{
public:
    // R - dostarczenia
    // P - Trwania
    // Q - stygnięcia
    int R;
    int P;
    int Q;
    int initialP;

    int initialIndex;

    Job job() {};

    void showJob() {
        std::cout << "R: " << R << " P: " << P << " Q: " << Q << " init index: " << initialIndex + 1 << "\n";
    }
};


int calculateC_MAX(std::vector<Job>& );

std::vector<int> getIndiciesAvailableJobs(std::vector<Job>&, int);

std::vector<Job>& addNewJobWithBiggestQ(std::vector<Job>&, std::vector<int>&,
    std::vector<Job>&, int&);