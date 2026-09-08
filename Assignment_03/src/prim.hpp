#ifndef PRIM_HPP
#define PRIM_HPP

#include "../../common_csr/csr.hpp"
#include "edge.hpp"
#include <vector>

using namespace std;

void prim(const CSR& csr,int vertices, vector<Edge>& mstEdges, int& totalWeight);

#endif