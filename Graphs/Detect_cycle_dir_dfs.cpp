#include <bits/stdc++.h>
using namespace std;

bool checkCycle (int node, vector <int> adj[], vector <int> &vis, vector <int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for (auto it : adj[node])
    {
        if(!vis[it])
        {
            if(checkCycle(it, adj, vis, dfsVis))
                return true;
        }

        else if (vis[it] == 1 && dfsVis[it] == 1)
            return true;
    }

    dfsVis[node] = 0;
    return false;
}

bool isCyclic(int v, vector<int> adj[])
{
    vector <int> vis(v+1, 0), dfsVis(v+1, 0);

    for (int i = 1; i<=v; i++)
    {
        if (!vis[i])
            if(checkCycle(i, adj, vis, dfsVis))
                return true;
    }

    return false;
}

int main()
{
    //input 
    // 9 10
    // 1 2
    // 2 3
    // 3 4
    // 4 5
    // 3 6 
    // 6 5
    // 7 2
    // 7 8
    // 8 9
    // 9 7
    
    int v, e;
    cin >> v >> e;

    vector<int> adj[v+1];

    for(int i = 1; i <= e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].emplace_back(dest);
    }

    if(isCyclic(v, adj))
        cout << "YES" << endl;

    else
        cout << "NO" << endl;

    return 0;
}