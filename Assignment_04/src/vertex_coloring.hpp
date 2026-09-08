#ifndef VERTEX_COLORING_HPP
#define VERTEX_COLORING_HPP

#include "../../common_csr/csr.hpp"
#include <vector>

using namespace std;

class VertexColoring
{
private:
    CSR graph;
    int V;

public:
    VertexColoring(CSR g, int vertices);

    vector<int> colorGraph();

    int countColors(vector<int> colors);
};

#endif