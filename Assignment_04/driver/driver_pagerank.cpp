#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

#include "../../common_csr/csr.hpp"
#include "../src/pagerank.hpp"

using namespace std;
using namespace chrono;

int main(int argc, char* argv[])
{
    // Check input
    if (argc < 2)
    {
        cout << "Usage: ./pagerank input.txt" << endl;
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

    // Read directed edges
    for (int i = 0; i < E; i++)
    {
        int u, v;

        file >> u >> v;

        // Directed graph
        adj[u].push_back({v, 1});
    }

    // Read PageRank parameters
    string word;

    double damping;
    double tolerance;
    int maxIterations;

    file >> word >> damping;
    file >> word >> tolerance;
    file >> word >> maxIterations;

    file.close();

    // Convert to CSR
    CSR graph = convertToCSR(adj);

    // Create PageRank object
    PageRank pr(graph, V);

    int iterations;
    bool converged;

    // Start timer
    auto start = high_resolution_clock::now();

    // Run PageRank
    vector<double> ranks =
        pr.calculate(
            damping,
            tolerance,
            maxIterations,
            iterations,
            converged
        );

    // Stop timer
    auto end = high_resolution_clock::now();

    auto time =
        duration_cast<microseconds>(end - start);

    // Print result
    cout << "Algorithm: PageRank" << endl;

    cout << "Damping: "
         << damping << endl;

    cout << "Vertex ranks:" << endl;

    for (int i = 0; i < V; i++)
    {
        cout << i << " "
             << ranks[i] << endl;
    }

    // Sum of ranks
    double sum = 0.0;

    for (int i = 0; i < V; i++)
    {
        sum += ranks[i];
    }

    cout << "Sum of ranks: "
         << sum << endl;

    cout << "Iterations: "
         << iterations << endl;

    cout << "Converged: ";

    if (converged)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "Execution time: "
         << time.count()
         << " microseconds"
         << endl;

    return 0;
}
//g++ Assignment_04\src\pagerank.cpp Assignment_04\driver\driver_pagerank.cpp common_csr\csr.cpp -o Assignment_04\pagerank.exe 