// Articulation points are those nodes on whose removal the graph is broken into two or more no. of components

#include <bits/stdc++.h>
using namespace std;

void DFS(int node, int parent, vector <int> adj[], vector <int> &vis, int &timer, vector <int> &time_ins, vector <int> &lowest, vector <int> &articulation_points)
{
    vis[node] = 1;
    time_ins[node] = lowest[node] = timer++;
    int child = 0;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            DFS(it, node, adj, vis, timer, time_ins, lowest, articulation_points);
            lowest[node] = min(lowest[node], lowest[it]);
            child++;

            if (lowest[it] >= time_ins[node] && parent != -1)
                articulation_points[node] = 1;
        }

        else
            lowest[node] = min(lowest[node], time_ins[it]);
    }

    if(parent == -1 && child > 1)
        articulation_points[node] = 1; 
}

void addEdge(vector <int> adj[], int u, int v)
{
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

int main()
{
    //input1        
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

    //input2
    // 11 13
    // 1 2
    // 1 3
    // 1 4
    // 2 5
    // 2 6
    // 5 6
    // 3 7
    // 3 8
    // 7 8
    // 4 9
    // 4 11
    // 9 10
    // 10 11
    
    int n, m;
    cin >> n >> m;

    vector <int> adj[n+1], articulation_points(n+1, 0);

    for (int i = 1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;

        addEdge(adj, u, v);
    }

    vector <int> time_ins(n+1, -1), lowest(n+1, -1), vis(n+1, 0);
    int timer = 0;

    for (int i = 1; i<=n; i++)
        if (!vis[i])
            DFS(i, -1, adj, vis, timer, time_ins, lowest, articulation_points);

    cout << "\nFollowing nodes are articulation points : " << endl;
    for (int i = 1; i<=n; i++)
        if(articulation_points[i] == 1)
            cout << i << " ";

    cout << endl;

    return 0;
}