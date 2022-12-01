//Problem Link :- https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    
    void DFS (int node, vector <int> adj[], vector <int> &vis)
    {
        vis[node] = 1;
        
        for (auto it : adj[node])
        {
            if (!vis[it])
                DFS(it, adj, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v = isConnected.size();
        
        vector <int> vis (v, 0);
        int count = 0;
        
        vector <int> adj[v];
        
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }    
            }
        }
        
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                {
                    DFS(i, adj, vis);
                    count++;
                    
                }
        }
        
        return count;  
    }
};