#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#include <iostream>
#include <vector>
#include "CSR.hpp"

using namespace std;
class Bellmanford
{
private:
    CSR graph;
    int vertices;

public:
    Bellmanford(CSR g, int V);

    void shortestPath(int source);
};
#endif