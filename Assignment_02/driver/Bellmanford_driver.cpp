#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

#include "csr.hpp"
#include "Bellmanford.hpp"

using namespace std;
namespace fs = std::filesystem;

int main()
{
    string inputFolder = "./tests/Bellmanford_test";
    string outputFolder = "./output/Bellmanford_output";

 
    // Delete previous output folder completely
 

    if (fs::exists(outputFolder))
    {
        fs::remove_all(outputFolder);
    }

    // Create fresh output folder
    fs::create_directories(outputFolder);

 
    // Check input folder
 

    if (!fs::exists(inputFolder))
    {
        cout << "Error: Bellman-Ford input folder not found!" << endl;
        return 1;
    }

 
    // Process every .txt file
 

    for (const auto& entry : fs::directory_iterator(inputFolder))
    {
        if (!entry.is_regular_file())
        {
            continue;
        }

        if (entry.path().extension() != ".txt")
        {
            continue;
        }

        string inputFile = entry.path().string();
        string fileName = entry.path().stem().string();

        // Ubuntu/Linux path separator
        string outputFile = outputFolder + "/" + fileName + "_output.txt";

     
        // Open input file
     

        ifstream fin(inputFile);

        if (!fin)
        {
            cout << "Error opening input file: "<< inputFile << endl;
            continue;
        }

        int vertices;
        int edges;

        fin >> vertices >> edges;

     
        // Create adjacency list
     

        vector<vector<pair<int, int>>> adj(vertices);

        for (int i = 0; i < vertices; i++)
        {
            int u;
            int degree;

            fin >> u >> degree;

            for (int j = 0; j < degree; j++)
            {
                int v;
                int w;

                fin >> v >> w;

                adj[u].push_back({v, w});
            }
        }

     
        // Read source
     

        string word;
        int source;

        fin >> word >> source;

        fin.close();

     
        // Convert to CSR
     

        CSR graph = convertToCSR(adj);

     
        // Create Bellman-Ford object
     

        Bellmanford bf(graph, vertices);

     
        // Create output file
     

        ofstream fout(outputFile);

        if (!fout)
        {
            cout << "Error creating output file: "<< outputFile << endl;
            continue;
        }

     
        // Redirect cout to output file
     

        streambuf* oldCout = cout.rdbuf(fout.rdbuf());

     
        // Run Bellman-Ford
     

        bf.shortestPath(source);

     
        // Restore cout
     

        cout.rdbuf(oldCout);

        fout.close();

        cout << "Processed: " << fileName << endl;
    }

 
    // Finished
 

    cout << "\nAll Bellman-Ford input files processed." << endl;

    return 0;
}
