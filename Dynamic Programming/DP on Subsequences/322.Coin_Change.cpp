//Problem Link :- https://leetcode.com/problems/coin-change/


//Solved by Memoization Method

class Solution {
public:
    
    int func (int index, int amount, vector<int>& coins, vector <vector <int>> &dp)
    {
        if (index == 0)
        {
            if (amount % coins[index] == 0)
                return amount / coins[index];
            
            else
                return 1e9;
        }
        
        if (dp[index][amount] != -1)
            return dp[index][amount];
        
        int notTake = 0 + func (index - 1, amount, coins, dp);
        int take = 1e9;
        
        if (coins[index] <= amount)
            take = 1 + func (index, amount - coins[index], coins, dp);
        
        return dp[index][amount] = min (take, notTake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector <vector <int>> dp (n, vector <int> (amount + 1, -1));
        
        int ans = func (n - 1, amount, coins, dp);
        
        return (ans >= 1e9) ? -1 : ans;
    }
};


//Solved by Tabulation Method

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector <vector <int>> dp (n, vector <int> (amount + 1, -1));
        
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            
            else
                dp[0][i] = 1e9;
        }
        
        for (int index = 1; index < n; index++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notTake = 0 + dp[index - 1][target];
                int take = 1e9;
                
                if (coins[index] <= target)
                    take = 1 + dp[index][target - coins[index]];
                
                dp[index][target] = min (take, notTake);
            }
        }
                
        return (dp[n - 1][amount] >= 1e9) ? -1 : dp[n - 1][amount];
    }
};


//Solved by Tabulation Method (Little Space Optimized) (using 2 rows)
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector <int> dp (amount + 1, -1);
        
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[i] = i / coins[0];
            
            else
                dp[i] = 1e9;
        }
        
        for (int index = 1; index < n; index++)
        {
            vector <int> temp (amount + 1, -1);
            
            for (int target = 0; target <= amount; target++)        
            {                                                       
                int notTake = 0 + dp[target];                       
                int take = 1e9;                                     
                
                if (coins[index] <= target)
                    take = 1 + temp[target - coins[index]];
                
                temp[target] = min (take, notTake);
            }
            
            dp = temp;
        }
                
        return (dp[amount] >= 1e9) ? -1 : dp[amount];
    }
};


//Solved by Tabulation Method (Best Space Optimized) (using only 1 row)
class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector <int> dp (amount + 1, -1);
        
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[i] = i / coins[0];
            
            else
                dp[i] = 1e9;
        }
        
        for (int index = 1; index < n; index++)
        {
            for (int target = 0; target <= amount; target++)        //  Here we went from left to right because we wanted to get minimum no. of coins.
            {                                                       //  For example, if we want to know how many coins are required for amount 5 
                int notTake = 0 + dp[target];                       //  we must have the no. of coins required for 1, 2, 3 and 4. 
                int take = 1e9;                                     // dp[ind][target] =  min (dp[ind-1][target] , dp[ind-1][target-arr[ind]])
                
                if (coins[index] <= target)
                    take = 1 + dp[target - coins[index]];
                
                dp[target] = min (take, notTake);
            }
        }
                
        return (dp[amount] >= 1e9) ? -1 : dp[amount];
    }
};


//Solved by Backtracking (Fastest solution)
class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector <int> dp (amount + 1, INT_MAX);
        dp[0] = 0;
        
        sort (coins.begin(), coins.end());
        
        for (int steps = 1; steps <= amount; steps++)
        {
            for (auto it : coins)
            {
                if (it > steps)
                    break;
                
                if (dp[steps - it] != INT_MAX)
                    dp[steps] = min (dp[steps], 1 + dp[steps - it]);
            }
        }
        
        return (dp[amount] >= 1e9) ? -1 : dp[amount];

    }
};