#include "prim.hpp"
#include <queue>
#include <tuple>
#include <functional>
using namespace std;

void prim(const CSR& csr,int vertices,vector<Edge>& mstEdges,int& totalWeight)
{
    vector<bool> visited(vertices, false);
    priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>,greater<tuple<int, int, int>> > pq;
    mstEdges.clear();
    totalWeight = 0;
    if (vertices == 0)
        return;
    pq.push({0, 0, -1});
    while (!pq.empty())
    {
        int weight = get<0>(pq.top());
        int vertex = get<1>(pq.top());
        int parent = get<2>(pq.top());
        pq.pop();
        if (vertex < 0 || vertex >= vertices)
            continue;
        if (visited[vertex])
            continue;
        visited[vertex] = true;
        if (parent != -1 &&
            parent >= 0 &&
            parent < vertices)
        {
            mstEdges.push_back({parent,vertex,weight });
            totalWeight += weight;
        }

        for (int i = csr.row_ptr[vertex]; i < csr.row_ptr[vertex + 1]; i++)
        {
            int neighbour = csr.col_idx[i];
            int edgeWeight = csr.values[i];
            if (neighbour >= 0 &&neighbour < vertices && !visited[neighbour])
            {
                pq.push({edgeWeight, neighbour, vertex});
            }
        }
    }
}