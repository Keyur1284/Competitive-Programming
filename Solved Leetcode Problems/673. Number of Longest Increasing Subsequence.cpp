// Problem Link :- https://leetcode.com/problems/number-of-longest-increasing-subsequence/

// Solved by DP
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size(), maxi = 1;
        vector<int> dp(n, 1), count(n, 1);

        for (int index = 0; index < n; index++)
        {
            for (int prev = 0; prev < index; prev++)
            {
                if (nums[index] > nums[prev] && 1 + dp[prev] > dp[index])
                {
                    dp[index] = 1 + dp[prev];
                    count[index] = count[prev];
                }

                else if (nums[index] > nums[prev] && 1 + dp[prev] == dp[index])
                    count[index] += count[prev];
            }

            maxi = max(maxi, dp[index]);
        }

        int LIS = 0;

        for (int index = 0; index < n; index++)
        {
            if (dp[index] == maxi)
                LIS += count[index];
        }

        return LIS;
    }
};