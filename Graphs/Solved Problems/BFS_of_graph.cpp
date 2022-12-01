//Problem Link :- https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        vector <int> vis (v, 0), ans;
        
        vis[0] = 1;
        queue <int> q;
        q.emplace(0);
        
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.emplace_back(node);
            
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.emplace(it);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends