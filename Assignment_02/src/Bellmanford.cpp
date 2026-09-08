#include "Bellmanford.hpp"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

#define INF 1000000000

Bellmanford::Bellmanford(CSR g, int V)
{
    graph = g;
    vertices = V;
}

void Bellmanford::shortestPath(int source)
{
    vector<int> dist(vertices, INF);
    dist[source] = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < vertices - 1; i++)
    {
        bool updated = false;

        for (int u = 0; u < vertices; u++)
        {
            for (int j = graph.row_ptr[u];
                 j < graph.row_ptr[u + 1];
                 j++)
            {
                int v = graph.col_idx[j];
                int w = graph.values[j];

                if (dist[u] != INF &&
                    dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
        }

        if (!updated)
            break;
    }

    bool negativeCycle = false;

    for (int u = 0; u < vertices; u++)
    {
        for (int j = graph.row_ptr[u];
             j < graph.row_ptr[u + 1];
             j++)
        {
            int v = graph.col_idx[j];
            int w = graph.values[j];

            if (dist[u] != INF &&
                dist[u] + w < dist[v])
            {
                negativeCycle = true;
                break;
            }
        }

        if (negativeCycle)
            break;
    }

    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<microseconds>(stop - start);

    double time_ms = duration.count() / 1000.0;

    cout << "\nAlgorithm: Bellman-Ford" << endl;
    cout << "Source: " << source << endl;

    if (negativeCycle)
    {
        cout << "\nNegative cycle: detected" << endl;
        cout << "Execution time: " << time_ms << " ms" << endl;
        return;
    }

    cout << "\nVertex Distance" << endl;

    for (int i = 0; i < vertices; i++)
    {
        cout << i << " ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    cout << "\nNegative cycle: none" << endl;
    cout << "Execution time: " << time_ms << " microsecond" << endl;
}