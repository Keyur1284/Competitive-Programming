//Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Solved by greedy approach

class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), profit = 0;

        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }

        return profit;
    }
};

//Solved by Memoization Method

class Solution {
public:
    
    int func (int index, int buy, vector <vector <int>> &dp, vector<int>& prices)
    {
        if (index == prices.size())
            return 0;
        
        if (dp[index][buy] != -1)
            return dp[index][buy];
        
        int profit;
        
        if (buy)
            profit = max (-prices[index] + func (index + 1, 0, dp, prices), func (index + 1, 1, dp, prices)); 
                      
        else
            profit = max (+prices[index] + func (index + 1, 1, dp, prices), func (index + 1, 0, dp, prices));
                          
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector <vector <int>> dp(n , vector <int> (2, -1));
        
        //Liberty to buy --> 1
        //Else buy --> 0
        
        return func (0, 1, dp, prices);
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector <vector <int>> dp(n + 1, vector <int> (2, 0));
        dp[n][0] = 0, dp[n][1] = 0;
        
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit;
                
                if (buy)
                    profit = max (-prices[index] + dp[index + 1][0], dp[index + 1][1]);
                
                else
                    profit = max (+prices[index] + dp[index + 1][1], dp[index + 1][0]);
                
                dp[index][buy] = profit;
            }
        }
        
        //Liberty to buy --> 1
        //Else buy --> 0
        
        return dp[0][1];
    }
};


//Solved by Tabulation Method (Space Optimized)

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector <int> dp(2, 0);
        dp[0] = 0, dp[1] = 0;
        
        for (int index = n - 1; index >= 0; index--)
        {
            int oldBuy = dp[1];
            int oldSell = dp[0];
            
            dp[1] = max (-prices[index] + oldSell, oldBuy);
            dp[0] = max (+prices[index] + oldBuy, oldSell);
        }
        
        //Liberty to buy --> 1
        //Else buy --> 0
        
        return dp[1];
    }
};

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector <int> dp(2, 0);
        dp[0] = 0, dp[1] = 0;
        
        for (int index = n - 1; index >= 0; index--)
        {
            vector <int> temp (2, 0);
            
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit;
                
                if (buy)
                    profit = max (-prices[index] + dp[0], dp[1]);
                
                else
                    profit = max (+prices[index] + dp[1], dp[0]);
                
                temp[buy] = profit;
            }
            
            dp = temp;
        }
        
        //Liberty to buy --> 1
        //Else buy --> 0
        
        return dp[1];
    }
};