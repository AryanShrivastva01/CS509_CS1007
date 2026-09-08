#include "kruskal.hpp"
#include <algorithm>
using namespace std;

int findParent(vector<int>& parent, int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;
    return findParent(parent, parent[vertex]);
}

void unionSet(vector<int>& parent,vector<int>& rank, int a, int b)
{
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (a == b)
        return;
    if (rank[a] < rank[b])
        parent[a] = b;
    else if (rank[a] > rank[b])
        parent[b] = a;
    else
    {
        parent[b] = a;
        rank[a]++;
    }
}

void kruskal(const CSR& csr, int vertices, vector<Edge>& mstEdges, int& totalWeight)
{
    vector<Edge> edges;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = csr.row_ptr[i];
             j < csr.row_ptr[i + 1];
             j++)
        {
            int destination = csr.col_idx[j];
            int weight = csr.values[j];
            if (i < destination)
            {
                edges.push_back({i, destination, weight});
            }
        }
    }

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b)
         {
             return a.weight < b.weight;
         });

    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);
    for (int i = 0; i < vertices; i++)
        parent[i] = i;
    mstEdges.clear();
    totalWeight = 0;

    for (const Edge& edge : edges)
    {
        int p1 = findParent(parent, edge.source);
        int p2 = findParent(parent, edge.destination);
        if (p1 != p2)
        {
            mstEdges.push_back(edge);
            totalWeight += edge.weight;
            unionSet(parent, rank, edge.source, edge.destination);
            if ((int)mstEdges.size() == vertices - 1)
                break;
        }
    }
}