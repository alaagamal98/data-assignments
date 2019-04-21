#include "ecg.hpp"     // for ecg::analyzeECG
#include "helpers1.hpp" // for helpers::loadECG

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Invalid usage!" << std::endl;
        return 1;
    }
    else
    {
        int size = 0;
        double *ecgArray = helpers::getECG(argv[1], size);

        // 1. declare `ecg::ECGArray` variable with name ecg, and initialize it with {ecgArray,size}
        ecg::ECGArray ecg{ecgArray, size};

        // 2. declare `ecg::Statistics` variable with name stats, and initialize it with the results of `analyzeECG( ecg )`
        ecg::Statistics stats{ecg::analyzeECG(ecg)};
        std::cout << "ECG average : " << stats.mean << std::endl
                  << "ECG variance: " << stats.variance << std::endl
                  << "ECG range   : (" << stats.min << "," << stats.max << ")" << std::endl;
        delete[] ecgArray;

        return 0;
    }
}
