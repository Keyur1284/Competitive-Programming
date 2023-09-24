// Problem Link :- https://leetcode.com/problems/champagne-tower/

// Solved by Tabulation Method
// Time Complexity :- O(query_row^2)
// Space Complexity :- O(query_row^2)

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<vector<double>> dp(query_row + 2, vector<double> (query_row + 2, 0));
        dp[0][0] = 1.0 * poured;

        for (int row = 0; row <= query_row; row++)
        {
            for (int col = 0; col <= row; col++)
            {
                double rem = (dp[row][col] - 1)/2.0;

                if (rem > 0)
                {
                    dp[row + 1][col] += rem;
                    dp[row + 1][col + 1] += rem;
                }
            }
        }

        return min(1.0, dp[query_row][query_glass]);
    }
};