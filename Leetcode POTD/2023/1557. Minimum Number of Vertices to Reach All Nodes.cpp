// Problem Link :- https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

// Time Complexity :- O(N + E)
// Space Complexity :- O(N)

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector<int> indegree(n, 0), ans;

        for (auto &it : edges)
            indegree[it[1]]++;

        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                ans.emplace_back(i);

        return ans;
    }
};