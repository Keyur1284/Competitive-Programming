// Problem Link :- https://leetcode.com/problems/longest-arithmetic-subsequence/

// Solved by DP (Using unordered_map)
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size(), maxi = 0;

        if (n == 0)
            return maxi;

        vector<unordered_map<int, int>> dp(n);

        for (int right = 0; right < n; right++)
        {
            for (int left = 0; left < right; left++)
            {
                int diff = nums[right] - nums[left];

                dp[right][diff] = max(1 + dp[left][diff], 2);
                maxi = max (maxi, dp[right][diff]);
            }
        }

        return maxi;
    }
};



class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size(), maxi = 0;
        vector<vector<int>> dp(n, vector<int>(2000, 0));

        for (int right = 0; right < n; right++)
        {
            for (int left = 0; left < right; left++)
            {
                int diff = nums[right] - nums[left] + 1000;

                dp[right][diff] = max(1 + dp[left][diff], 2);
                maxi = max (maxi, dp[right][diff]);
            }
        }

        return maxi;
    }
};