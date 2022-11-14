//Problem Link :- https://leetcode.com/problems/subsets-ii/

class Solution {

public:
    void Recc (int index, vector<int>& nums, vector <vector<int>> &ans, vector <int> &ds)
    {
        ans.emplace_back(ds);
        
        for (int i = index; i<nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i-1])
                continue;
            
            ds.emplace_back(nums[i]);
            Recc (i+1, nums, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort (nums.begin(), nums.end());
        vector <vector<int>> ans;
        vector <int> ds;
        Recc(0, nums, ans, ds);
        
        return ans;
    }
};
