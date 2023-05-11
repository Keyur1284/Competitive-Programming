// Problem Link :- https://leetcode.com/problems/uncrossed-lines/

// Time Complexity :- O(nm)
// Space Complexity :- O(nm)

// Solved by Memoization Method

class Solution {
public:

    int solve (int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (nums1[i] == nums2[j])
            return dp[i][j] = 1 + solve(i - 1, j - 1, nums1, nums2, dp);

        else
            return dp[i][j] = 0 + max(solve(i - 1, j, nums1, nums2, dp), solve(i, j - 1, nums1, nums2, dp));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp (n, vector<int> (m, -1));

        return solve(n - 1, m - 1, nums1, nums2, dp);
    }
};


//Solved by Memoization Method  (Shifting of index to right by 1)

class Solution {
public:

    int solve (int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (nums1[i - 1] == nums2[j - 1])
            return dp[i][j] = 1 + solve(i - 1, j - 1, nums1, nums2, dp);

        else
            return dp[i][j] = 0 + max(solve(i - 1, j, nums1, nums2, dp), solve(i, j - 1, nums1, nums2, dp));
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));

        return solve(n, m, nums1, nums2, dp);
    }
};


// Solved by Tabulation Method

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
};


// Solved by Tabulation Method (Space Optimized)

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        vector<int> dp (m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            vector<int> temp (m + 1, 0);

            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    temp[j] = 1 + dp[j - 1];

                else
                    temp[j] = 0 + max(dp[j], temp[j - 1]);
            }

            dp = temp;
        }

        return dp[m];
    }
};