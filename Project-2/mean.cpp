
#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

// Header file for the Data template class
#include "Data.h"

int main(int argc, char* argv[]) {
    const char* filename = argc < 2 ? "data.bin" : argv[1];

    //-----------------------------------------------------------------------
    //
    // Access our the data file through our Data C++ class.  Under the hood,
    //   this class uses an advanced file-access technique called memory
    //   mapping, which makes the file looked like an array (although our
    //   Data class makes it look more like a std::vector), allowing indexed
    //   random-access to the data.
    //
    Data<float>  data(filename);


    size_t n = data.size();
    int numThreads = 4;

    std::vector<std::thread> threads(numThreads);
    std::vector<double> partialSums(numThreads, 0.0);

    size_t chunk = (n + numThreads - 1) / numThreads;

    //-----------------------------------------------------------------------
    //
    // The computational kernel that computes the mean by summing the
    //   values in the data array. 
    //
    // now utilizing threading, lambdas, and std::accumulate
    for (int t = 0; t < numThreads; ++t) {
        size_t begin = t * chunk;
        size_t end = std::min(begin + chunk, n);

        threads[t] = std::thread([&, t, begin, end]() {
            double localSum = 0.0;
            for (size_t i = begin; i < end; ++i) {
                localSum += data[i];
            }
            partialSums[t] = localSum;
            });
    }

    for (auto &th : threads) th.join();

    double totalSum = std::accumulate(
        partialSums.begin(),
        partialSums.end(),
        0.0
    );

    double mean = totalSum / static_cast<double>(n);
    //-----------------------------------------------------------------------
    //
    // Report the results.
    //
    std::cout << "Samples = " << data.size() << "\n";
    std::cout << "Mean = " << mean / data.size() << "\n";
}

