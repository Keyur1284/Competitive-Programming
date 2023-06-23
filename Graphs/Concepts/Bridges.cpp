// Bridges are those edges on whose removal the graph is broken into two or more no. of components

#include <bits/stdc++.h>
using namespace std;

void DFS(int node, int parent, vector <int> adj[], vector <int> &vis, int &timer, vector <int> &time_ins, vector <int> &lowest)
{
    vis[node] = 1;
    time_ins[node] = lowest[node] = timer++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            DFS(it, node, adj, vis, timer, time_ins, lowest);
            lowest[node] = min(lowest[node], lowest[it]);

            if (lowest[it] > time_ins[node])
                cout << node << " " << it << endl;
        }

        else
            lowest[node] = min(lowest[node], lowest[it]);
    }
}

void addEdge(vector <int> adj[], int u, int v)
{
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

int main()
{
    //input
    // 12 14
    // 1 2
    // 2 3
    // 3 4
    // 4 1
    // 4 5
    // 5 6
    // 6 7
    // 7 8
    // 8 9
    // 6 9
    // 8 10
    // 10 11
    // 11 12
    // 10 12
    
    int n, m;
    cin >> n >> m;

    vector <int> adj[n+1];

    for (int i = 1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;

        addEdge(adj, u, v);
    }

    vector <int> time_ins(n+1, -1), lowest(n+1, -1), vis(n+1, 0);
    int timer = 0;

    cout << "\nFollowing nodes are connected by bridges : " << endl;

    for (int i = 1; i<=n; i++)
        if (!vis[i])
            DFS(i, -1, adj, vis, timer, time_ins, lowest);

    return 0;
}