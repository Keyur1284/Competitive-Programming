//Topological sort is valid only for directed acyclic graphs
//Defination : Linear ordering of vertices such that if there is an edge u -> v then u appears before v in that ordering

#include <bits/stdc++.h>
using namespace std;

void findTopoSort(int node, vector <int> adj[], vector <int> &vis, stack <int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
        if (!vis[it])
            findTopoSort(it, adj, vis, st);

    st.emplace(node);
}

vector <int> TopoSort (int v, vector <int> adj[])
{
    vector <int> topo, vis(v+1, 0);
    stack <int> st;

    for (int i = 1; i<=v; i++)
    {
        if (!vis[i])
            findTopoSort(i, adj, vis, st);
    }

    while(!st.empty()) 
    {
        topo.emplace_back(st.top()); 
        st.pop(); 
	}
	
    return topo; 
}

//Function to check if elements returned by user
// contains the elements in topological sorted form
bool check (int v, vector<int> adj[], vector <int> ans)
{
    vector<int> map(v+1, -1);

    for (int i = 0; i < v; i++) 
    {
        map[ans[i]] = i;
    }

    for (int i = 1; i <= v; i++) 
    {
        for (auto node : adj[i]) 
            if (map[i] > map[node]) 
                return false;
    }

    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> adj[v+1], ans;

    for(int i = 1; i <= e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        adj[src].emplace_back(dest);
    }

    ans = TopoSort(v, adj);

    for (auto it : ans)
        cout << it << " ";

    cout << endl;

    bool result = check(v, adj, ans);

    cout << result << endl;

    return 0;
}
