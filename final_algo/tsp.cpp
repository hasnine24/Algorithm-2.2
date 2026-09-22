#include <bits/stdc++.h>
using namespace std;

#define INF 999999

int n;
int cost[20][20];

int bestCost = INF;
vector<int> bestPath;
bool visited[20];

int reduceMatrix(int matrix[20][20])
{
    int reduction = 0;

    // Row reduction
    for (int i = 0; i < n; i++)
    {
        int mn = INF;

        for (int j = 0; j < n; j++)
            mn = min(mn, matrix[i][j]);

        if (mn != INF && mn != 0)
        {
            reduction += mn;

            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] != INF)
                    matrix[i][j] -= mn;
            }
        }
    }

    // Column reduction
    for (int j = 0; j < n; j++)
    {
        int mn = INF;

        for (int i = 0; i < n; i++)
            mn = min(mn, matrix[i][j]);

        if (mn != INF && mn != 0)
        {
            reduction += mn;

            for (int i = 0; i < n; i++)
            {
                if (matrix[i][j] != INF)
                    matrix[i][j] -= mn;
            }
        }
    }

    return reduction;
}

void TSP(int current, int level,
         int pathCost, int bound,
         int matrix[20][20],
         vector<int> path)
{
    // All cities visited
    if (level == n)
    {
        int totalCost = pathCost + cost[current][0];

        if (totalCost < bestCost)
        {
            bestCost = totalCost;

            path.push_back(0);
            bestPath = path;
        }

        return;
    }

    for (int next = 0; next < n; next++)
    {
        if (!visited[next] && matrix[current][next] != INF)
        {
            int newMatrix[20][20];

            // Copy matrix
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    newMatrix[i][j] = matrix[i][j];
                }
            }

            // IMPORTANT:
            // Take original cost, not reduced cost
            int edgeCost = cost[current][next];

            // Block current row
            for (int j = 0; j < n; j++)
                newMatrix[current][j] = INF;

            // Block next column
            for (int i = 0; i < n; i++)
                newMatrix[i][next] = INF;

            // Don't return to city 0 early
            newMatrix[next][0] = INF;

            // Reduce matrix
            int reduction = reduceMatrix(newMatrix);

            // New lower bound
            int newBound = bound + edgeCost + reduction;

            // Branch and Bound
            if (newBound < bestCost)
            {
                visited[next] = true;
                path.push_back(next);

                TSP(next,
                    level + 1,
                    pathCost + edgeCost,
                    newBound,
                    newMatrix,
                    path);

                path.pop_back();
                visited[next] = false;
            }
        }
    }
}

int main()
{
    cin >> n;

    int matrix[20][20];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (i == j)
                matrix[i][j] = INF;
            else
                matrix[i][j] = cost[i][j];
        }
    }

    // Initial reduction
    int initialBound = reduceMatrix(matrix);

    visited[0] = true;

    vector<int> path;
    path.push_back(0);

    TSP(0,
        1,
        0,              // actual path cost
        initialBound,   // lower bound
        matrix,
        path);

    cout << "Minimum Cost = " << bestCost << endl;

    cout << "Shortest Path = ";

    for (int i = 0; i < bestPath.size(); i++)
    {
        cout << bestPath[i];

        if (i != bestPath.size() - 1)
            cout << " -> ";
    }

    cout << endl;

    return 0;
}