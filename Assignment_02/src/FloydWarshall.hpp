#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H
#include <iostream>
#include <vector>
#include "CSR.hpp"

using namespace std;
class FloydWarshall
{
private:
    CSR graph;
    int vertices;
public:
    FloydWarshall(CSR g, int V);
    void shortestPath();
};
#endif