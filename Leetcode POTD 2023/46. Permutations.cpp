// Problem Link :- https://leetcode.com/problems/permutations/

// Solved by Backtracking
// Time Complexity :- O(n * n!)
// Space Complexity :- O(n!)

class Solution {
public:

    void solve (int index, int &n, vector<vector<int>> &perm, vector<int> &nums)
    {
        if (index == n)
        {
            perm.emplace_back(nums);
            return;
        }

        for (int i = index; i < n; i++)
        {
            swap (nums[index], nums[i]);
            solve (index + 1, n, perm, nums);
            swap (nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> perm;

        solve (0, n, perm, nums);

        return perm;
    }
};