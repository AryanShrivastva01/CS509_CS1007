#ifndef CSR_HPP
#define CSR_HPP
#include <vector>
using namespace std;

struct CSR
{
    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;
};

CSR convertToCSR(const vector<vector<pair<int,int>>>& adj);

#endif