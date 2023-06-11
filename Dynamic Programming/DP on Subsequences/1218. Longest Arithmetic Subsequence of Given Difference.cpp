// Problem Link :- https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

// Solved by DP (Using unordered_map)
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int> dp;
        int maxi = INT_MIN;

        for (auto &it : arr)
        {
            if (dp.find(it - difference) != dp.end())
                dp[it] = max(dp[it], 1 + dp[it - difference]);

            else
                dp[it] = 1;

            maxi = max(dp[it], maxi);
        }

        return maxi;
    }
};


