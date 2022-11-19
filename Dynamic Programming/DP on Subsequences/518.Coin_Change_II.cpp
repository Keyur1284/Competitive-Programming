//Problem Link :- https://leetcode.com/problems/coin-change-2/

//Solved by Memoization Method

class Solution {
public:
    
    int func (int index, int target, vector <vector <int>> &dp, vector<int>& coins)
    {
        if (index == 0)
            return (target % coins[index] == 0);
        
        if (dp[index][target] != -1)
            return dp[index][target];
        
        int notTake = func (index - 1, target, dp, coins);
        int take = 0;
        
        if (coins[index] <= target)
            take += func (index, target - coins[index], dp, coins);
        
        return dp[index][target] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector <vector <int>> dp (n, vector <int> (amount + 1, -1));
        
        return func (n - 1, amount, dp, coins);
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector <vector <int>> dp (n, vector <int> (amount + 1, 0));
        
        for (int k = 0; k <= amount; k++)
            dp[0][k] = (k % coins[0] == 0);
        
        for (int index = 1; index < n; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notTake = dp[index - 1][target];
                int take = 0;

                if (coins[index] <= target)
                    take += dp[index][target - coins[index]];

                dp[index][target] = take + notTake;
            }
        }
        
        return dp[n - 1][amount];
    }
};


//Solved by Tabulation Method (Less Space Optimized) (Using 2 rows)
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector <int> dp (amount + 1, 0);
        
        for (int k = 0; k <= amount; k++)
            dp[k] = (k % coins[0] == 0);
        
        for (int index = 1; index < n; index++)
        {
            vector <int> temp (amount + 1, 0);
            
            for (int target = 0; target <= amount; target++)
            {
                int notTake = dp[target];
                int take = 0;

                if (coins[index] <= target)
                    take += temp[target - coins[index]];

                temp[target] = take + notTake;
            }
            
            dp = temp;
        }
        
        return dp[amount];
    }
};


//Solved by Tabulation Method (Best Space Optimized) (Using 1 row)
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector <int> dp (amount + 1, 0);
        
        for (int k = 0; k <= amount; k++)
            dp[k] = (k % coins[0] == 0);
        
        for (int index = 1; index < n; index++)
        {            
            for (int target = 0; target <= amount; target++)
            {
                int notTake = dp[target];
                int take = 0;

                if (coins[index] <= target)
                    take += dp[target - coins[index]];

                dp[target] = take + notTake;
            }
        }
        
        return dp[amount];
    }
};