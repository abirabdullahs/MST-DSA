#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100005;

vector<pair<int, int>> adj[N];
bool visited[N];

int prim(int source)
{
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    int totalCost = 0;

    
    pq.push({0, source});

    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        totalCost += weight;

        for (auto edge : adj[node])
        {
            int nextNode = edge.second;
            int nextWeight = edge.first;

            if (!visited[nextNode])
            {
                pq.push({nextWeight, nextNode});
            }
        }
    }

    return totalCost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    cout << "MST Cost = " << prim(0) << endl;

    return 0;
}
