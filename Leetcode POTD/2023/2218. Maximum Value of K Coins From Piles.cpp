// Problem Link :- https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

// Time Complexity :- O(s*k) s -> total number of coins in all piles
// Space Complexity :- O(n*k) n -> no. of piles

// Solved by Memoization Method

class Solution {
public:

    int func (int index, int coins, vector<vector<int>>& dp, vector<vector<int>>& piles)
    {
        if (index == piles.size() || coins == 0)
            return 0;

        if (dp[index][coins] != -1)
            return dp[index][coins];

        int notPick = func(index + 1, coins, dp, piles);
        int pick = 0, sum = 0;

        for (int i = 0; i < min((int)piles[index].size(), coins); i++)
        {
            sum += piles[index][i];
            int temp = sum + func (index + 1, coins - i - 1, dp, piles);
            pick = max(pick, temp);
        }

        return dp[index][coins] = max(pick, notPick);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

       int n = piles.size();
       vector<vector<int>> dp (n, vector<int> (k + 1, -1));

       return func (0, k, dp, piles); 
    }
};


// Solved by Tabulation Method

class Solution {
public:

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        int n = piles.size();
        vector<vector<int>> dp (n + 1, vector<int> (k + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int coins = k; coins >= 0; coins--)
            {
                int sum = 0;
                
                dp[index][coins] = max(dp[index][coins], dp[index + 1][coins]);

                for (int i = 0; i < min((int)piles[index].size(), coins); i++)
                {
                    sum += piles[index][i];
                    int temp = dp[index + 1][coins - i - 1] + sum;
                    dp[index][coins] = max(dp[index][coins], temp);
                }
            }
        }

        return dp[0][k]; 
    }
};


// Solved by Tabulation Method (Space Optimized)

class Solution {
public:

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        int n = piles.size();
        vector<int> dp (k + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            vector<int> temp (k + 1, 0);

            for (int coins = k; coins >= 0; coins--)
            {
                int sum = 0;
                
                temp[coins] = max(temp[coins], dp[coins]);

                for (int i = 0; i < min((int)piles[index].size(), coins); i++)
                {
                    sum += piles[index][i];
                    int num = dp[coins - i - 1] + sum;
                    temp[coins] = max(temp[coins], num);
                }
            }

            dp = temp;
        }

        return dp[k]; 
    }
};