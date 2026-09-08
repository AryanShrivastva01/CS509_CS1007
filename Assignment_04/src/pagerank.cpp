#include "pagerank.hpp"
#include <cmath>

using namespace std;

PageRank::PageRank(CSR g, int vertices)
{
    graph = g;
    V = vertices;
}

vector<double> PageRank::calculate(
    double damping,
    double tolerance,
    int maxIterations,
    int &iterations,
    bool &converged)
{
    // Initial rank
    vector<double> rank(V);

    for (int i = 0; i < V; i++)
    {
        rank[i] = 1.0 / V;
    }

    vector<double> newRank(V);

    iterations = 0;
    converged = false;

    // Repeat
    for (int iteration = 1;
         iteration <= maxIterations;
         iteration++)
    {
        // Basic PageRank value
        for (int i = 0; i < V; i++)
        {
            newRank[i] = (1.0 - damping) / V;
        }

        // Calculate total rank from dangling vertices
        double danglingRank = 0.0;

        for (int vertex = 0; vertex < V; vertex++)
        {
            int degree =
                graph.row_ptr[vertex + 1]
                - graph.row_ptr[vertex];

            if (degree == 0)
            {
                danglingRank += rank[vertex];
            }
        }

        // Distribute dangling rank
        double danglingContribution =
            damping * danglingRank / V;

        for (int i = 0; i < V; i++)
        {
            newRank[i] += danglingContribution;
        }

        // Distribute rank through outgoing edges
        for (int vertex = 0; vertex < V; vertex++)
        {
            int degree =
                graph.row_ptr[vertex + 1]
                - graph.row_ptr[vertex];

            if (degree > 0)
            {
                double contribution =
                    damping * rank[vertex] / degree;

                for (int j = graph.row_ptr[vertex];
                     j < graph.row_ptr[vertex + 1];
                     j++)
                {
                    int neighbour = graph.col_idx[j];

                    newRank[neighbour] += contribution;
                }
            }
        }

        // Calculate difference
        double difference = 0.0;

        for (int i = 0; i < V; i++)
        {
            difference +=
                abs(newRank[i] - rank[i]);
        }

        // Copy new ranks
        for (int i = 0; i < V; i++)
        {
            rank[i] = newRank[i];
        }

        iterations = iteration;

        // Check convergence
        if (difference <= tolerance)
        {
            converged = true;
            break;
        }
    }

    return rank;
}