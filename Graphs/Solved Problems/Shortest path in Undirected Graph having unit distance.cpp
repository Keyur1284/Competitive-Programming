// Problem Link :- https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

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

    void BFS (int src, vector<int> &path, vector<int> adj[])
    {
        queue<int> q;
        q.emplace(src);
        path[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &it : adj[node])
            {
                if (path[node] + 1 < path[it])
                {
                    path[it] = path[node] + 1;
                    q.emplace(it);
                }
            }
        }
    }

    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){

        vector<int> adj[N];

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        vector<int> path (N, INT_MAX);

        BFS (src, path, adj);

        for (auto &it :path)
        {
            if (it == INT_MAX)
                it = -1;
        }

        return path;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends