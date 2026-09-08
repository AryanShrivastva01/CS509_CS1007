#ifndef PAGERANK_HPP
#define PAGERANK_HPP

#include "../../common_csr/csr.hpp"
#include <vector>

using namespace std;

class PageRank
{
private:
    CSR graph;
    int V;

public:
    PageRank(CSR g, int vertices);

    vector<double> calculate(
        double damping,
        double tolerance,
        int maxIterations,
        int &iterations,
        bool &converged
    );
};

#endif