#include <iostream>
#include <fstream>
#include <vector>
#include "../src/csr.hpp"
using namespace std;

int main()
{
    ifstream fin("tests/csr_input_03.txt");
    if (!fin)
    {
        cout << "Unable to open file!" << endl;
        return 1;
    }
    int V;
    fin >> V;
    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < V; i++)
    {
        int k;
        fin >> k;
        while (k--)
        {
            int dest, weight;
            fin >> dest >> weight;
            adj[i].push_back({dest, weight});
        }
    }
    fin.close();
    CSR csr = convertToCSR(adj);
    cout << "row_ptr: ";
    for (int x : csr.row_ptr)
        cout << x << " ";
        cout << "\ncol_idx: ";
    for (int x : csr.col_idx)
        cout << x << " ";
    cout << "\nvalues : ";
    for (int x : csr.values)
        cout << x << " ";
        cout << endl;
    return 0;
}   