// Problem Link :- https://leetcode.com/problems/stone-game/

// Solved by Memoization Method
// Time Complexity :- O(N^3)
// Space Complexity :- O(N^2)

class Solution {
public:

    int func (int turn, int start, int end, vector<vector<int>> &dp, vector<int>& piles)
    {
        if (start > end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int front, back;

        if (turn == 0)
        {
            front = piles[start] + func (!turn, start + 1, end, dp, piles);
            back = piles[end] + func (!turn, start, end - 1, dp, piles);
        }

        else
        {
            front = - piles[start] + func (!turn, start + 1, end, dp, piles);
            back = - piles[end] + func (!turn, start, end - 1, dp, piles);
        }

        return dp[start][end] = max(front, back);
    }

    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<int>> dp (n, vector<int> (n, -1));

        return func (0, 0, n - 1, dp, piles);
    }
};


// Solved by Tabulation Method
// Time Complexity :- O(N^2)
// Space Complexity :- O(N^2)

class Solution {
public:

    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<int>> dp (n + 2, vector<int> (n + 2, 0));

        for (int start = n; start >= 1; start--)
        {
            for (int end = 1; end <= n; end++)
            {
                if (start > end)
                {
                    dp[start][end] = 0;
                    continue;
                }

                for (int turn = 0; turn < 1; turn++)
                {
                    int front, back;

                    if (turn == 0)
                    {
                        front = piles[start - 1] + dp[start + 1][end];
                        back = piles[end - 1] + dp[start][end - 1];
                    }

                    else
                    {
                        front = - piles[start - 1] + dp[start + 1][end];
                        back = - piles[end - 1] + dp[start][end - 1];
                    }

                    dp[start][end] = max(front, back);
                }
            }
        }

        return dp[1][n];
    }
};


// Trick Solution

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        return true;
    }
};