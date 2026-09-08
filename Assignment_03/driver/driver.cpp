#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <chrono>
#include <string>
#include <filesystem>
#include "../../common_csr/csr.hpp"
#include "../src/kruskal.hpp"
#include "../src/prim.hpp"

using namespace std;
using namespace chrono;
namespace fs = std::filesystem;

string getOutputName(string inputFile)
{
    size_t slash = inputFile.find_last_of("/\\");
    string fileName;
    if (slash == string::npos)
    {
        fileName = inputFile;
    }
    else
    {
        fileName = inputFile.substr(slash + 1);
    }

    size_t dot = fileName.find_last_of(".");

    if (dot != string::npos)
    {
        fileName = fileName.substr(0, dot);
    }

    return "Assignment_03/output/" + fileName +"_output.txt";
}


int main()
{
    string testFolder = "Assignment_03/tests";
    if (!fs::exists(testFolder))
    {
        cout << "Tests folder not found." << endl;
        return 1;
    }

    for (const auto& entry : fs::directory_iterator(testFolder))
    {
        if (entry.path().extension() != ".txt")
        {
            continue;
        }

        string inputFile = entry.path().string();

        ifstream file(inputFile);
        if (!file)
        {
            cout << "Cannot open file: " << inputFile << endl;
            continue;
        }
        int vertices;
        int edges;
        file >> vertices >> edges;
        vector<vector<pair<int, int>>> adj(vertices);

        for (int i = 0; i < vertices; i++)
        {
            int vertex;
            int degree;
            file >> vertex >> degree;
            for (int j = 0; j < degree; j++)
            {
                int neighbour;
                int weight;

                file >> neighbour >> weight;

                adj[vertex].push_back({neighbour, weight});
            }
        }

        file.close();
        CSR csr = convertToCSR(adj);
        vector<Edge> kruskalEdges;
        int kruskalWeight;
        auto startKruskal = high_resolution_clock::now();

        kruskal( csr, vertices, kruskalEdges, kruskalWeight );

        auto endKruskal = high_resolution_clock::now();
        double kruskalTime = duration<double, milli>(endKruskal - startKruskal).count();
        vector<Edge> primEdges;
        int primWeight;
        auto startPrim = high_resolution_clock::now();

        prim(csr,vertices,primEdges, primWeight);
        auto endPrim = high_resolution_clock::now();


        double primTime = duration<double, milli>( endPrim - startPrim).count();
        string outputFile = getOutputName(inputFile);
        ofstream output(outputFile);
        if (!output)
        {
            cout << "Cannot create output file: "<< outputFile << endl;
            continue;
        }
        output << "Algorithm: Kruskal's MST\n";
        output << "MST edges:\n";

        for (const Edge& edge : kruskalEdges)
        {
            output << edge.source << " "<< edge.destination << " " << edge.weight << "\n";
        }


        output << "Total MST weight: " << kruskalWeight << "\n";
        output << "Execution time: " << kruskalTime << " ms\n\n";
        output << "Algorithm: Prim's MST\n";
        output << "MST edges:\n";

        for (const Edge& edge : primEdges)
        {
            output << edge.source << " " << edge.destination << " " << edge.weight << "\n";
        }

        output << "Total MST weight: " << primWeight << "\n";
        output << "Execution time: "<< primTime<< " ms\n";
        output.close();
    }
    return 0;
}
  
