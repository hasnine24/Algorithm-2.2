#include <bits/stdc++.h>
using namespace std;

int n;
int cost[20][20];
bool visited[20];

int minCost = INT_MAX;
vector<int> bestPath;
vector<int> path;

void tsp(int current, int count, int totalCost)
{
    // All cities visited
    if (count == n)
    {
        // Return to starting city
        int finalCost = totalCost + cost[current][0];

        if (finalCost < minCost)
        {
            minCost = finalCost;
            bestPath = path;
            bestPath.push_back(0);
        }

        return;
    }

    // Try all unvisited cities
    for (int next = 0; next < n; next++)
    {
        if (!visited[next])
        {
            visited[next] = true;
            path.push_back(next);

            tsp(next, count + 1,
                totalCost + cost[current][next]);

            path.pop_back();
            visited[next] = false;
        }
    }
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    // Start from city 0
    visited[0] = true;
    path.push_back(0);

    tsp(0, 1, 0);

    // Print shortest path
    cout << "\nShortest Path: ";

    for (int i = 0; i < bestPath.size(); i++)
    {
        cout << bestPath[i];

        if (i != bestPath.size() - 1)
            cout << " -> ";
    }

    // Print minimum cost
    cout << "\nMinimum Cost: " << minCost << endl;

    return 0;
}