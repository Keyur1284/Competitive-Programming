// Problem Link :- https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// Solved by DP
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size(), count = 0;
        vector<unordered_map<long, int>> dp(n);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long diff = (long)nums[i] - nums[j];
                dp[i][diff]++;

                if (dp[j].count(diff))
                {
                    dp[i][diff] += dp[j][diff];
                    count += dp[j][diff];
                }
            }
        }

        return count;
    }
};