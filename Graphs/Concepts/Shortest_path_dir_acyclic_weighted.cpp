#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector <pair<int, int>> adj[], vector <int> &vis, stack <int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
        if (!vis[it.first])
            findTopoSort(it.first, adj, vis, st);

    st.emplace(node);
}

vector <int> Shortest_Dfs (int v, int src, vector <pair<int, int>> adj[])
{
    vector <int> vis(v+1, 0), dis(v+1, INT_MAX);
    stack <int> st;

    for (int i = 0; i<=v; i++)
        if(!vis[i])
            findTopoSort(i, adj, vis, st);

    dis[src] = 0; 

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dis[node] != INT_MAX)
        {
            for (auto it : adj[node])
            {
                if (dis[node] + it.second < dis[it.first])
                    dis[it.first] = dis[node] + it.second;
            }
        }
    }

    return dis;
}

int main()
{
    //input
    // 5 7
    // 0 1 2
    // 1 2 3
    // 2 3 6
    // 0 4 1
    // 4 2 2
    // 4 5 4
    // 5 3 1

    int n, m;
    cin >> n >> m;
    vector <pair<int, int>> adj[n+1];
    
    for (int i = 1; i<=m; i++)
    {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        adj[src].emplace_back(dest, wt);
    }

    vector <int> dis = Shortest_Dfs(n, 0, adj);

    for (auto it : dis)
        (it == INT_MAX)? cout << "INF " : cout << it << " ";

    return 0;
}