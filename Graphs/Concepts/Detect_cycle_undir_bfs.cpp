#include <bits/stdc++.h>
using namespace std;

bool checkForCycle (int node, vector <int> adj[], vector <int> &vis)
{
    queue <pair<int, int>> q;
    q.emplace(node, -1);
    vis[node] = 1;

    while (!q.empty())
    {
        int curr = q.front().first;
        int prev = q.front().second;
        q.pop();

        for (auto it : adj[curr])
        {
            if(!vis[it])
            {
                q.emplace(it, curr);
                vis[it] = 1;
            }

            else if (it != prev)
                return true;
        }
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
            if(checkForCycle (i, adj, vis))
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
    addEdge(adj,1,3);
    addEdge(adj,3,4);
    addEdge(adj,1,3);
    addEdge(adj,3,5);

    bool ans = isCycle(n, adj);

    if (ans == true)
        cout << "YES" << endl;

    else    
        cout << "NO" << endl;

    return 0;
}