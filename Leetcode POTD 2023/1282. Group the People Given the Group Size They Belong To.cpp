// Problem Link :-  https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

// Solved by making adj list
// Time Complexity :- O(N)
// Space Complexity :- O(N)

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n = groupSizes.size();
        vector<vector<int>> ans;
        
        vector<int> groups[n + 1];

        for (int i = 0; i < n; i++) 
        {
            groups[groupSizes[i]].emplace_back(i);
            
            if (groups[groupSizes[i]].size() == groupSizes[i]) 
            {
                ans.emplace_back(groups[groupSizes[i]]);
                groups[groupSizes[i]].clear();
            }
        }

        return ans;
    }
};