//Defination : Graphs which can be colored using 2 colors such that no two adjacent nodes have same color

#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs (int node, vector <int> adj[], vector <int> &color)
{
    queue <int> q;
    color[node] = 1;
    q.emplace(node);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (auto it : adj[temp])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[temp];
                q.emplace(it);
            }

            else if (color[it] == color[temp])
                return false;
        }
    }

    return true;
}

bool checkBipartite(vector <int> adj[], int v)
{
    vector <int> color(v+1, -1);

    for (int i = 1; i<=v; i++)
    {
        if (color[i] == -1)
            if (bipartiteBfs(i, adj, color) == false)
                return false;
    }

    return true;
}

void addEdge (vector <int> adj[], int u, int v)
{
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

int main ()
{
    int n = 8;
    vector <int> adj[n+1];

    // bipartite graph example 
    // addEdge(adj, 9, 8);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 4);
    // addEdge(adj, 4, 5);
    // addEdge(adj, 5, 7);
    // addEdge(adj, 7, 8);
    // addEdge(adj, 2, 8);
    // addEdge(adj, 5, 6);

    // not bipartite example
    // addEdge(adj, 1, 2);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 3, 4);
    // addEdge(adj, 4, 5);
    // addEdge(adj, 5, 7);
    // addEdge(adj, 7, 2);
    // addEdge(adj, 5, 6);

    if(checkBipartite(adj, n))
	    cout << "YES"; 
	
    else 
	    cout << "NO"; 
	
	return 0;

}