// Problem Link :- https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

// Solved by DFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    void DFS (int node, int prev, vector<int> &nums, unordered_map<int, vector<int>> &adj)
    {
        nums.emplace_back(node);

        for (auto &it : adj[node])
        {
            if (it != prev)
                DFS (it, node, nums, adj);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

        unordered_map<int, vector<int>> adj;

        for (auto &it : adjacentPairs)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }

        int root = -1;

        for (auto &it : adj)
        {
            if (it.second.size() == 1)
            {
                root = it.first;
                break;
            }    
        }

        vector<int> nums;
        DFS (root, -1, nums, adj);

        return nums;
    }
};