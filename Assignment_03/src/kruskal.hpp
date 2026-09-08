#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP
#include "../../common_csr/csr.hpp"
#include "edge.hpp"
#include <vector>
using namespace std;

void kruskal(const CSR& csr,int vertices, vector<Edge>& mstEdges, int& totalWeight);
#endif