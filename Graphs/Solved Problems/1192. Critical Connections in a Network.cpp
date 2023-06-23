// Problem Link :- https://leetcode.com/problems/critical-connections-in-a-network/

// Solved by Bridges Concept (Tarjan's Algorithm)
// Time Complexity :- O(E + V)
// Space Complexity :- O(E + V)

class Solution {
public:

    void DFS (int node, int parent, int &clock, vector<int> &insertTime, vector<int> &lowestTime, vector<bool> &vis, vector<vector<int>> &bridges, vector<int> adj[])
    {
        vis[node] = true;
        insertTime[node] = lowestTime[node] = clock++;

        for (auto &it : adj[node])
        {
            if (it == parent)
                continue;

            if (!vis[it])
            {
                DFS (it, node, clock, insertTime, lowestTime, vis, bridges, adj);
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);

                if (lowestTime[it] > insertTime[node])
                {
                    bridges.push_back({node, it});
                }
            }

            else
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];

        for (auto &it : connections)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        vector<int> insertTime(n), lowestTime(n);
        vector<bool> vis (n, false);
        vector<vector<int>> bridges;
        int clock = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                DFS (i, -1, clock, insertTime, lowestTime, vis, bridges, adj);
            }
        }

        return bridges;
    }   
};