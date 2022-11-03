#include <bits/stdc++.h>
using namespace std;

bool checkForCycle (int node, int parent, vector <int> adj[], vector <int> &vis)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if(checkForCycle(it, node, adj, vis))
                return true;
        }

        else if (it != parent)
            return true;
    }

    return false;
}

bool isCycle (int v, vector <int> adj[])
{
    vector <int> vis(v+1, 0);

    for (int i = 1; i<=v; i++)
    {
        if(!vis[i])
        {
            if(checkForCycle (i, -1, adj, vis))
                return true;
        }
    }

    return false;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

int main()
{
    int n = 5;

    vector<int> adj[n+1];
    
    //add edges of the graph

    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,2,5);
    addEdge(adj,5,4);
    //addEdge(adj,3,4);

    bool ans = isCycle(n, adj);

    if (ans == true)
        cout << "YES" << endl;

    else    
        cout << "NO" << endl;

    return 0;
}