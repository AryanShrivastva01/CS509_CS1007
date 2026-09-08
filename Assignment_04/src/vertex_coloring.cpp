#include "vertex_coloring.hpp"
#include <algorithm>

using namespace std;

VertexColoring::VertexColoring(CSR g, int vertices)
{
    graph = g;
    V = vertices;
}

vector<int> VertexColoring::colorGraph()
{
    // Store vertices
    vector<int> order;

    for (int i = 0; i < V; i++)
    {
        order.push_back(i);
    }

    // Sort vertices by decreasing degree
    sort(order.begin(), order.end(),
        [this](int a, int b)
        {
            int degreeA = graph.row_ptr[a + 1] - graph.row_ptr[a];
            int degreeB = graph.row_ptr[b + 1] - graph.row_ptr[b];

            return degreeA > degreeB;
        });

    // Initially no vertex has a color
    vector<int> color(V, -1);

    // Color vertices one by one
    for (int k = 0; k < V; k++)
    {
        int vertex = order[k];

        // Find colors used by neighbours
        vector<bool> used(V, false);

        for (int i = graph.row_ptr[vertex];
             i < graph.row_ptr[vertex + 1];
             i++)
        {
            int neighbour = graph.col_idx[i];

            if (color[neighbour] != -1)
            {
                used[color[neighbour]] = true;
            }
        }

        // Find smallest available color
        int c = 0;

        while (used[c])
        {
            c++;
        }

        color[vertex] = c;
    }

    return color;
}

int VertexColoring::countColors(vector<int> colors)
{
    int maxColor = -1;

    for (int i = 0; i < V; i++)
    {
        if (colors[i] > maxColor)
        {
            maxColor = colors[i];
        }
    }

    return maxColor + 1;
}