//Problem Link :- https://leetcode.com/problems/subsets/

class Solution {
public:
    
    void Recc (int index, vector <int> &nums, int N, vector <vector<int>> &ans, vector<int> &ds)
    {
        if (index == N)
        {
            ans.emplace_back(ds);
            return;
        }
        
        ds.emplace_back(nums[index]);
        Recc (index + 1, nums, N, ans, ds);
        ds.pop_back();
        Recc (index + 1, nums, N, ans, ds);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int N = nums.size();
        vector <vector <int>> ans;
        vector <int> ds;
        Recc (0, nums, N, ans, ds);
        return ans;
    }
};