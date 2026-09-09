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
    if (argc < 2)
    {
        cout << "Usage: ./pagerank input.txt" << endl;
        return 1;
    }

    string filename = argv[1];

    ifstream file(filename);

    if (!file)
    {
        cout << "Cannot open file." << endl;
        return 1;
    }

    int V, E;

    file >> V >> E;

    if (V <= 0 || E < 0)
    {
        cout << "Invalid graph." << endl;
        return 1;
    }

    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < V; i++)
    {
        int vertex;
        int degree;

        file >> vertex >> degree;

        if (vertex < 0 || vertex >= V || degree < 0)
        {
            cout << "Invalid graph input." << endl;
            return 1;
        }

        for (int j = 0; j < degree; j++)
        {
            int neighbour;

            file >> neighbour;

            if (neighbour < 0 || neighbour >= V)
            {
                cout << "Invalid edge." << endl;
                return 1;
            }

            adj[vertex].push_back({neighbour, 1});
        }
    }

    string word;

    double damping;
    double tolerance;
    int maxIterations;

    file >> word >> damping;
    file >> word >> tolerance;
    file >> word >> maxIterations;

    file.close();

    if (damping <= 0.0 || damping >= 1.0)
    {
        cout << "Invalid damping factor." << endl;
        return 1;
    }

    if (tolerance <= 0.0)
    {
        cout << "Invalid tolerance." << endl;
        return 1;
    }

    if (maxIterations <= 0)
    {
        cout << "Invalid maximum iterations." << endl;
        return 1;
    }

    CSR graph = convertToCSR(adj);

    PageRank pr(graph, V);

    int iterations;
    bool converged;

    auto start = high_resolution_clock::now();

    vector<double> ranks =
        pr.calculate( damping,tolerance,maxIterations,iterations,converged);

    auto end = high_resolution_clock::now();

    auto time = duration_cast<microseconds>(end - start);

    cout << "Algorithm: PageRank" << endl;

    cout << "Damping: " << damping << endl;

    cout << "Vertex ranks:" << endl;

    for (int i = 0; i < V; i++)
    {
        cout << i << " " << ranks[i] << endl;
    }

    double sum = 0.0;

    for (int i = 0; i < V; i++)
    {
        sum += ranks[i];
    }

    cout << "Sum of ranks: " << sum << endl;

    cout << "Iterations: " << iterations << endl;

    cout << "Converged: ";

    if (converged)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "Execution time: "<< time.count()<< " microseconds"<< endl;

    return 0;
}

