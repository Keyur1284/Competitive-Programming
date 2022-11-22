//Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

//Solved by Memoization Method

class Solution {
public:
    
    int func (int index, int buy, vector <vector <int>> &dp, vector<int>& prices)
    {
        if (index >= prices.size())
            return 0;
        
        if (dp[index][buy] != -1)
            return dp[index][buy];
        
        int profit;
        
        if (buy)
            profit = max (-prices[index] + func (index + 1, 0, dp, prices), func (index + 1, 1, dp, prices)); 
                      
        else
            profit = max (+prices[index] + func (index + 2, 1, dp, prices), func (index + 1, 0, dp, prices));
                          
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
        vector <vector <int>> dp(n + 2, vector <int> (2, 0));
        dp[n][0] = 0, dp[n][1] = 0, dp[n + 1][0] = 0, dp[n + 1][1] = 0;     //  This initialization can be omitted as we have already assigned 0 to all
        
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit;
                
                if (buy)
                    profit = max (-prices[index] + dp[index + 1][0], dp[index + 1][1]);
                
                else
                    profit = max (+prices[index] + dp[index + 2][1], dp[index + 1][0]);
                
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
        vector <int> dp(2, 0), front1 (2, 0), front2 (2, 0);
        dp[0] = 0, dp[1] = 0;     //  This initialization can be omitted as we have already assigned 0 to all
        
        for (int index = n - 1; index >= 0; index--)
        {            
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit;
                
                if (buy)
                    profit = max (-prices[index] + front1[0], front1[1]);
                
                else
                    profit = max (+prices[index] + front2[1], front1[0]);
                
                dp[buy] = profit;
            }
            
            front2 = front1;
            front1 = dp;
            
        }
        
        //Liberty to buy --> 1
        //Else buy --> 0
        
        return dp[1];
    }
};