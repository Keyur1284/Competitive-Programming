#include <bits/stdc++.h>
using namespace std;

vector <int> Shortest_Bfs (int v, int src, vector <int> adj[])
{
    vector <int> dis(v+1, INT_MAX);
    queue <int> q;
    dis[src] = 0;
    q.emplace(src);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (dis[node] + 1 < dis[it])
            {
                dis[it] = dis[node] + 1;
                q.emplace(it);
            }
        }
    }

    return dis;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

int main()
{

    // input
    // 8 10
    // 0 1
    // 0 3
    // 1 2
    // 2 6
    // 3 4
    // 4 5
    // 5 6
    // 6 7
    // 6 8
    // 7 8
    
    int v, e;
    cin >> v >> e;

    vector<int> adj[v+1], dis;

    for(int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        addEdge(adj, a, b);
    }

    dis = Shortest_Bfs(v, 0, adj);

    for (auto it : dis)
        cout << it << " ";

    return 0;
}