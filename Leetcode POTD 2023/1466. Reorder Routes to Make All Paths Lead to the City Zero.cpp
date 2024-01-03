// Problem Link :- https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

// Solved by DFS

class Solution {
public:

    void DFS (int node, int &count, vector<bool> &vis, vector<pair<int, int>> adj[])
    {
        vis[node] = true;

        for (auto &child : adj[node])
        {
            if (!vis[child.first])
            {
                count += child.second;
                DFS(child.first, count, vis, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        
        int count = 0;
        vector<pair<int, int>> adj[n];
        vector<bool> vis(n, false);

        for (auto &it : connections)
        {
            adj[it[0]].emplace_back(it[1], 1);
            adj[it[1]].emplace_back(it[0], 0);
        }

        DFS (0, count, vis, adj);

        return count;
    }
};


// Solved by BFS

class Solution {
public:

    int minReorder(int n, vector<vector<int>>& connections) {
        
        int count = 0;
        vector<pair<int, int>> adj[n];
        vector<bool> vis(n, false);

        for (auto &it : connections)
        {
            adj[it[0]].emplace_back(it[1], 1);
            adj[it[1]].emplace_back(it[0], 0);
        }

        queue<int> q;
        q.emplace(0);
        vis[0] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &child : adj[node])
            {
                if (!vis[child.first])
                {
                    count += child.second;
                    q.emplace(child.first);
                    vis[child.first] = true;
                }
            }
        }

        return count;
    }
};