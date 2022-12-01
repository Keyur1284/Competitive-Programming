//Problem Link :- https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


//Solved by BFS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool checkForCycle (int node, vector <int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        queue <pair<int, int>> q;
        q.emplace(node, -1);
        
        while (!q.empty())
        {
            int cur = q.front().first;
            int prev = q.front().second;
            q.pop();
            
            for (auto it : adj[cur])
            {
                if (!vis[it])
                {
                    vis[it] = 1; 
                    q.emplace(it, cur);
                }
                
                else if (it != prev)
                    return true;
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int v, vector<int> adj[]) {
        
        vector <int> vis (v, 0);
        
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, vis, adj))
                    return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends


//Solved by DFS

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool checkForCycle (int node, int parent, vector <int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
    
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if(checkForCycle(it, node, vis, adj))
                    return true;
            }
            
            else if (it != parent)
                return true;
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int v, vector<int> adj[]) {
        
        vector <int> vis (v, 0);
        
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, -1, vis, adj))
                    return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends