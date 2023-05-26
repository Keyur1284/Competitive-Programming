// Problem Link :- https://leetcode.com/problems/stone-game-ii/

// Solved by Memoization Method
// Time Complexity :- O(n^3)
// Space Complexity :- O(n^2)


class Solution {
public:

    int func (int index, int turn, int m, int n, vector<vector<vector<int>>> &dp, vector<int>& piles)
    {
        if (index == n)
            return 0;

        if (dp[turn][index][m] != -1)
            return dp[turn][index][m];

        int ans = (turn == 0) ? INT_MIN : INT_MAX;
        int sum = 0;

        for (int k = 1; k <= min(2 * m, n - index); k++)
        {
            sum += piles[index + k - 1];

            if (turn == 0)
                ans = max(ans, sum + func (index + k, 1, max(k, m), n, dp, piles));

            else
                ans = min(ans, func (index + k, 0, max(k, m), n, dp, piles));
        }

        return dp[turn][index][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<vector<int>>> dp (2, vector<vector<int>> (n + 1, vector<int> (n + 1, -1))) ;

        return func(0, 0, 1, n, dp, piles);
    }
};



// Solved by Tabulation Method


class Solution {
public:

    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<vector<int>>> dp (2, vector<vector<int>> (n + 1, vector<int> (n + 1, 0)));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int m = 1; m <= n; m++)
            {
                for (int turn = 0; turn < 2; turn++)
                {
                    int ans = (turn == 0) ? INT_MIN : INT_MAX;
                    int sum = 0;

                    for (int k = 1; k <= min(2 * m, n - index); k++)
                    {
                        sum += piles[index + k - 1];

                        if (turn == 0)
                            ans = max(ans, sum + dp[1][index + k][max(k, m)]);

                        else
                            ans = min(ans, dp[0][index + k][max(k, m)]);
                    }

                    dp[turn][index][m] = ans;
                }
            }
            
        }

        return dp[0][0][1];
    }
};
