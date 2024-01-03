// Problem Link :- https://leetcode.com/problems/maximal-network-rank/

// Solved by making adjacency list
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_set<int> adj[n];
        vector<int> indegree(n, 0);

        for (auto &it : roads)
        {
            adj[it[0]].emplace(it[1]);
            adj[it[1]].emplace(it[0]);

            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        int maxRank = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int rank = indegree[i] + indegree[j] - (adj[i].count(j));
                maxRank = max(rank, maxRank);
            }
        }

        return maxRank;
    }
};



class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_set<int> adj[n];

        for (auto &it : roads)
        {
            adj[it[0]].emplace(it[1]);
            adj[it[1]].emplace(it[0]);
        }

        int maxRank = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int rank = adj[i].size() + adj[j].size() - (adj[i].count(j));
                maxRank = max(rank, maxRank);
            }
        }

        return maxRank;
    }
};