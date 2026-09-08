#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "../../common_csr/csr.hpp"
#include "../src/vertex_coloring.hpp"

using namespace std;
using namespace chrono;

int main(int argc, char* argv[])
{
    // Check input file
    if (argc < 2)
    {
        cout << "Usage: ./vertex_coloring input.txt" << endl;
        return 1;
    }

    string filename = argv[1];

    // Open file
    ifstream file(filename);

    if (!file)
    {
        cout << "Cannot open file." << endl;
        return 1;
    }

    // Read V and E
    int V, E;

    file >> V >> E;

    // Create adjacency list
    vector<vector<pair<int, int>>> adj(V);

    // Read edges
    for (int i = 0; i < E; i++)
    {
        int u, v;

        file >> u >> v;

        // Undirected graph
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }

    file.close();

    // Convert adjacency list to CSR
    CSR graph = convertToCSR(adj);

    // Create Vertex Coloring object
    VertexColoring vc(graph, V);

    // Start timer
    auto start = high_resolution_clock::now();

    // Run algorithm
    vector<int> colors = vc.colorGraph();

    // Stop timer
    auto end = high_resolution_clock::now();

    auto time = duration_cast<microseconds>(end - start);

    // Print result
    cout << "Algorithm: Welsh-Powell Vertex Coloring" << endl;

    cout << "Vertex colors:" << endl;

    for (int i = 0; i < V; i++)
    {
        cout << i << " " << colors[i] << endl;
    }

    cout << "Colors used: "
         << vc.countColors(colors)
         << endl;

    cout << "Execution time: "
         << time.count()
         << " microseconds"
         << endl;

    return 0;
}