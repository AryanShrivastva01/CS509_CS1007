#include "FloydWarshall.hpp"
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
#define INF 1000000000

FloydWarshall::FloydWarshall(CSR g, int V)
{
    graph = g;
    vertices = V;
}

void FloydWarshall::shortestPath()
{
    vector<vector<int>> dist(vertices, vector<int>(vertices, INF));
    for (int i = 0; i < vertices; i++)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = graph.row_ptr[i]; j < graph.row_ptr[i + 1]; j++)
        {
            int v = graph.col_idx[j];
            int w = graph.values[j];

            dist[i][v] = w;
        }
    }

    auto start = high_resolution_clock::now();
    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nAlgorithm: FloydWarshall" << endl;
    cout << "\nShortest Distance Matrix\n\n";
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nExecution Time : "
         << duration.count()
         << " microseconds" << endl;
}