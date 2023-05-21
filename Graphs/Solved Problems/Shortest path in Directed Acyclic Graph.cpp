// Problem Link :- https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

// Time Complexity :- O(N + E)
// Space Complexity :- O(N + E)


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    void TopoSortDFS (int node, vector<bool> &vis, stack<int> &st, vector<pair<int, int>> adj[])
    {
        vis[node] = true;
        
        for (auto &it : adj[node])
        {
            if (!vis[it.first])
                TopoSortDFS (it.first, vis, st, adj);
        }
        
        st.emplace(node);
    }
  
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<pair<int, int>> adj[N];
        
        for (auto &it : edges)
            adj[it[0]].emplace_back(it[1], it[2]);
            
        vector<bool> vis(N, false);
        stack<int> st;
        
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                TopoSortDFS (i, vis, st, adj);
            }
        }
        
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for (auto &it : adj[node])
            {
                if (dist[node] + it.second < dist[it.first])
                    dist[it.first] = dist[node] + it.second;
            }
        }
        
        for (auto &it : dist)
        {
            if (it == 1e9)
                it = -1;
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends