// Problem Link :- https://leetcode.com/problems/subsets/

// Solved by Backtracking
// Time Complexity :- O(2^n)
// Space Complexity :- O(n)

class Solution {
public:
    
    void solve(int index, vector<int> &nums, int& n, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (index == n)
        {
            ans.emplace_back(ds);
            return;
        }
        
        ds.emplace_back(nums[index]);
        solve(index + 1, nums, n, ans, ds);
        ds.pop_back();
        solve(index + 1, nums, n, ans, ds);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        vector <int> ds;
        solve(0, nums, n, ans, ds);
        return ans;
    }
};



// Solved by Bit Manipulation
// Time Complexity :- O(2^n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int mask = 0; mask < (1 << n); mask++)
        {
            vector<int> ds;
           
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                    ds.emplace_back(nums[i]);
            }
           
            ans.emplace_back(ds);
        }
        return ans;
    }
};