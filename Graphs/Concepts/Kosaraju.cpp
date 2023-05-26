//This algorithm is for finding the different strongly connected components of the given graph
// Strongly Connected Components (SCC) are only valid for directed graph

// Algorithm:
// 1. Do a DFS traversal of the graph and push the nodes in a stack after visiting all the adjacent nodes
// 2. Reverse the graph
// 3. Pop the nodes from the stack and do a DFS traversal of the graph
// 4. The nodes visited in the DFS traversal are the strongly connected components of the graph


#include <bits/stdc++.h>
using namespace std;

void Toposort(int node, vector <int> adj[], vector <int> &vis, stack <int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if(!vis[it])
            Toposort(it, adj, vis, st);
    }

    st.emplace(node);
}

void Kosaraju(int node, vector <int> transpose[], vector <int> &vis)
{
    vis[node] = 1;
    cout << node << " ";

    for (auto it : transpose[node])
    {
        if(!vis[it])
            Kosaraju(it, transpose, vis);
    }
}

int main()
{
    //input 
    // 5 5
    // 1 2
    // 2 3
    // 3 1
    // 2 4
    // 4 5
    
    int n, m;
    cin >> n >> m;

    vector<int> adj[n+1], transpose[n+1], vis(n+1, 0);
    stack <int> st;

    for(int i = 1; i <= m; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].emplace_back(dest);
        //transpose[dest].emplace_back(src);
    }

    for (int i = 1; i<=n; i++)
    {
        if(!vis[i])
            Toposort(i, adj, vis, st);
    }

    for (int i = 1; i<=n; i++)
    {
        vis[i] = 0;

        for (auto it : adj[i])
            transpose[it].emplace_back(i);
    }

    cout << "Following are the strongly connected components of the graph : " << endl;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!vis[node])
        {
            Kosaraju(node, transpose, vis);       //Reverse Dfs
            cout << endl;
        }
    }

    return 0;
}