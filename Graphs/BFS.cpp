#include <bits/stdc++.h>
using namespace std;

vector <int> bfsOfGraph (int v, vector <int> adj[])
{
    vector <int> storeBfs, vis(v+1, 0);

    for (int i = 1; i<=v; i++)
    {
        if(!vis[i])
        {
            queue <int> q;
            q.emplace(i);
            vis[i] = 1;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                storeBfs.emplace_back(node);

                for (auto it : adj[node])
                    if(!vis[it])
                    {
                        q.emplace(it);
                        vis[it] = 1;
                    }
            }
        }
    }

    return storeBfs;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

int main()
{
    int n = 5;

    vector<int> adj[n+1], ans;
    
    //add edges of the graph

    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,2);
    addEdge(adj,5,1);

    ans = bfsOfGraph(n, adj);

    for (auto it : ans)
        cout << it << " ";

    return 0;
}