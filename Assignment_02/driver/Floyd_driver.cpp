#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

#include "csr.hpp"
#include "FloydWarshall.hpp"

using namespace std;
namespace fs = std::filesystem;

int main()
{
    string inputFolder = "./tests/Floyd_test";
    string outputFolder = "./output/Floyd_output";

 
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
        cout << "Error: Floyd-Warshall input folder not found!"<< endl;
        return 1;
    }

 
    // Process every .txt file
 

    for (const auto& entry : fs::directory_iterator(inputFolder))
    {
        // Skip non-text files
        if (!entry.is_regular_file())
        {
            continue;
        }

        if (entry.path().extension() != ".txt")
        {
            continue;
        }

     
        // Get input and output file names
     

        string inputFile = entry.path().string();
        string fileName = entry.path().stem().string();

        string outputFile =outputFolder + "/" + fileName + "_output.txt";

     
        // Open input file
     

        ifstream fin(inputFile);

        if (!fin)
        {
            cout << "Error opening input file: "<< inputFile << endl;
            continue;
        }

     
        // Read number of vertices
     

        int vertices;

        fin >> vertices;

     
        // Create adjacency list
     

        vector<vector<pair<int, int>>> adj(vertices);

     
        // Read adjacency matrix
     

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                string value;

                fin >> value;

                if (value != "INF" && i != j)
                {
                    int weight = stoi(value);

                    adj[i].push_back({j, weight});
                }
            }
        }

        fin.close();

     
        // Convert adjacency list to CSR
     

        CSR graph = convertToCSR(adj);

     
        // Create Floyd-Warshall object
     

        FloydWarshall fw(graph, vertices);

     
        // Create output file
     

        ofstream fout(outputFile);

        if (!fout)
        {
            cout << "Error creating output file: "
                 << outputFile << endl;
            continue;
        }

     
        // Redirect cout to output file
     

        streambuf* oldCout = cout.rdbuf(fout.rdbuf());

     
        // Run Floyd-Warshall
     

        fw.shortestPath();

     
        // Restore cout
     

        cout.rdbuf(oldCout);

        fout.close();

     
        // Display progress
     

        cout << "Processed: " << fileName << endl;
    }

 
    // Finished
 

    cout << "\nAll Floyd-Warshall input files processed."<< endl;

    return 0;
}
