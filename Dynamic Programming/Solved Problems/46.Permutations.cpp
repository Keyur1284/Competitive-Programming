//Problem Link :- https://leetcode.com/problems/permutations/

class Solution {
public:
    
    void Recc (vector<int>& nums, vector <vector<int>> &ans, vector <int> &ds, vector <int> &map)
    {
        if (ds.size() == nums.size())
        {
            ans.emplace_back(ds);
            return;
        }
        
        for (int i = 0; i<nums.size(); i++)
        {
            if (!map[i])
            {
                map[i] = 1;
                ds.emplace_back(nums[i]);
                Recc(nums, ans, ds, map);
                ds.pop_back();
                map[i] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector <vector<int>> ans;
        vector <int> ds, map(nums.size(), 0);
        Recc (nums, ans, ds, map);
        return ans;
    }
};