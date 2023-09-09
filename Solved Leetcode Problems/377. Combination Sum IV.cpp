// Problem Link :- https://leetcode.com/problems/combination-sum-iv/

// Solved by Memoization Method
// Time Complexity :- O(n*target)
// Space Complexity :- O(target)

class Solution {
public:

    int solve (int target, vector<int> &dp, vector<int> &nums)
    {
        if (target == 0)
            return 1;

        if (dp[target] != -1)
            return dp[target];

        int ways = 0;

        for (auto &it : nums)
        {
            if (it <= target)
                ways += solve(target - it, dp, nums);
        }

        return dp[target] = ways;
    }

    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> dp (target + 1, -1);

        return solve(target, dp, nums); 
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n*target)
// Space Complexity :- O(target)

class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<uint> dp (target + 1, 0);
        dp[0] = 1;

        for (int tar = 1; tar <= target; tar++)
        {
            for (auto it : nums)
            {
                if (it <= tar)
                    dp[tar] += dp[tar - it];
            }
        } 

        return dp[target];
    }
};