#include "csr.hpp"

CSR convertToCSR(const vector<vector<pair<int,int>>>& adj)
{
    CSR csr;
    csr.row_ptr.push_back(0);
    for (const auto &row : adj)
    {
        for (const auto &edge : row)
        {
            csr.col_idx.push_back(edge.first);
            csr.values.push_back(edge.second);
        }
        csr.row_ptr.push_back(csr.col_idx.size());
    }
    return csr;
}