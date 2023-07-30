// Problem Link :- https://leetcode.com/problems/strange-printer/

// Solved by DP
// Time Complexity :- O(n^3)
// Space Complexity :- O(n^2)

class Solution {
public:

    int solve (int left, int right, int n, vector<vector<int>> &dp, string &s)
    {
        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = n;
        int j = -1;

        for (int index = left; index < right; index++)
        {
            if (s[index] != s[right] && j == -1)
                j = index;

            if (j != -1)
            {
                int res = 1 + solve (j, index, n, dp, s) + solve (index + 1, right, n, dp, s);
                ans = min(res, ans);
            }
        }

        if (j == -1)
            ans = 0;

        return dp[left][right] = ans;
    }

    int strangePrinter(string s) {
        
        int n = s.length();
        vector<vector<int>> dp (n, vector<int> (n, -1));
        return solve (0, n - 1, n, dp, s) + 1;
    }
};