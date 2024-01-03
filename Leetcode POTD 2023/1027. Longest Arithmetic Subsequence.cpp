// Problem Link :- https://leetcode.com/problems/longest-arithmetic-subsequence/

// Solved by DP
// Time Complexity :- O(n^2)
// Space Complexity :- O(n * 2 * (maxElement - minElement))

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size(), maxi = 0;
        auto bounds = minmax_element(nums.begin(), nums.end());
        int minEle = *bounds.first, maxEle = *bounds.second;
        int range = maxEle - minEle;

        vector<vector<int>> dp (n, vector<int> (2 * range + 1, 0));

        for (int end = 0; end < n; end++)
        {
            for (int start = 0; start < end; start++)
            {
                int diff = nums[end] - nums[start] + range;

                dp[end][diff] = max(1 + dp[start][diff], 2);
                maxi = max(maxi, dp[end][diff]);
            }
        }

        return maxi;
    }
};