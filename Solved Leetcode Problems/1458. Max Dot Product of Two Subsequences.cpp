// Problem Link :- https://leetcode.com/problems/max-dot-product-of-two-subsequences/

// Solved by Memoization Method
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    int solve (int ind1, int ind2, vector<vector<int>> &dp, vector<int>& nums1, vector<int>& nums2)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        int take = nums1[ind1] * nums2[ind2] + solve(ind1 - 1, ind2 - 1, dp, nums1, nums2);
        int notTake1 = solve(ind1 - 1, ind2, dp, nums1, nums2);
        int notTake2 = solve(ind1, ind2 - 1, dp, nums1, nums2);

        return dp[ind1][ind2] = max({take, notTake1, notTake2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp (n, vector<int> (m, -1));

        auto it1 = minmax_element(nums1.begin(), nums1.end());
        auto it2 = minmax_element(nums2.begin(), nums2.end());
        int min1 = *it1.first, max1 = *it1.second;
        int min2 = *it2.first, max2 = *it2.second;

        if (min1 > 0 && max2 < 0)
            return min1 * max2;

        if (min2 > 0 && max1 < 0)
            return min2 * max1;

        return solve(n - 1, m - 1, dp, nums1, nums2);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));

        auto it1 = minmax_element(nums1.begin(), nums1.end());
        auto it2 = minmax_element(nums2.begin(), nums2.end());
        int min1 = *it1.first, max1 = *it1.second;
        int min2 = *it2.first, max2 = *it2.second;

        if (min1 > 0 && max2 < 0)
            return min1 * max2;

        if (min2 > 0 && max1 < 0)
            return min2 * max1;

        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                int take = nums1[ind1 - 1] * nums2[ind2 - 1] + dp[ind1 - 1][ind2 - 1];
                int notTake1 = dp[ind1 - 1][ind2];
                int notTake2 = dp[ind1][ind2 - 1];

                dp[ind1][ind2] = max({take, notTake1, notTake2});
            }
        }

        return dp[n][m];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * m)
// Space Complexity :- O(m)

class Solution {
public:

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();
        vector<int> dp (m + 1, 0);

        auto it1 = minmax_element(nums1.begin(), nums1.end());
        auto it2 = minmax_element(nums2.begin(), nums2.end());
        int min1 = *it1.first, max1 = *it1.second;
        int min2 = *it2.first, max2 = *it2.second;

        if (min1 > 0 && max2 < 0)
            return min1 * max2;

        if (min2 > 0 && max1 < 0)
            return min2 * max1;

        for (int ind1 = 1; ind1 <= n; ind1++)
        {
            vector<int> temp (m + 1, 0);

            for (int ind2 = 1; ind2 <= m; ind2++)
            {
                int take = nums1[ind1 - 1] * nums2[ind2 - 1] + dp[ind2 - 1];
                int notTake1 = dp[ind2];
                int notTake2 = temp[ind2 - 1];

                temp[ind2] = max({take, notTake1, notTake2});
            }
            
            dp = temp;
        }

        return dp[m];
    }
};