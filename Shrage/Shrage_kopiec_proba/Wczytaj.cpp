#include "Wczytaj.h"


Job* wczytaj(int set)
{
    std::ifstream myfile("schr.data.txt");
    int quantityOfData = 0;
    //Job** _JOBS = new Job * [8];

    Job temporaryJob;
    std::string line;

    std::cout << "Hello world!\n";

    if (!myfile.is_open()) throw std::runtime_error("Could not open file");

    std::string currentDataSet;

    //for (int dataSetIndex = 0; dataSetIndex < 8; dataSetIndex++) {

        currentDataSet = "data.00" + std::to_string(set) + ":\r";

        while (getline(myfile, line) && (line != currentDataSet)); // skip useless data
        myfile >> quantityOfData;
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
        //_JOBS[dataSetIndex] = new Job[quantityOfData];
        Job* jobs = new Job[quantityOfData];//_JOBS[dataSetIndex];
        for (int i = 0; i < quantityOfData; i++) {
            myfile >> temporaryJob.R >> temporaryJob.P >> temporaryJob.Q;
            temporaryJob.initialIndex = i;

            (*(jobs + i)) = temporaryJob;
        }
    //}
    return jobs;
}