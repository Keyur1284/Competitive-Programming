//Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

//Solved by Memoization Method

class Solution {
public:
    
    int func (int index, int buy, int cap, vector <vector <vector <int>>> &dp, vector<int>& prices)
    {
        if (index == prices.size() || cap == 0)
            return 0;
        
        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];
        
        int profit;
        
        if (buy)
            profit = max (-prices[index] + func (index + 1, 0, cap, dp, prices), func (index + 1, 1, cap, dp, prices));
        
        else
            profit = max (+prices[index] + func (index + 1, 1, cap - 1, dp, prices), func (index + 1, 0, cap, dp, prices));
        
        return dp[index][buy][cap] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        vector <vector <vector <int>>> dp (n, vector <vector <int>> (2 , vector <int> (k + 1, -1)));

        //Liberty to buy --> 1
        //Else buy --> 0
        //Max no. of transactions allowed --> k
        
        return func (0, 1, k, dp, prices);
        
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
                
        int n = prices.size();
        
        vector <vector <vector <int>>> dp (n + 1, vector <vector <int>> (2 , vector <int> (k + 1, 0)));
        
        for (int buy = 0; buy <= 1; buy++)              //  This initialization can be omitted as we have already assigned 0 to all
        {
            for (int cap = 0; cap <=k; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }
        
        for (int index = 0; index <=n; index++)         //  This initialization can be omitted as we have already assigned 0 to all
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                dp[index][buy][0] = 0;
            }
        }
        
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
                {
                    int profit;
                    
                    if (buy)
                        profit = max (-prices[index] + dp[index + 1][0][cap], dp[index + 1][1][cap]);
                    
                    else
                        profit = max (+prices[index] + dp[index + 1][1][cap - 1], dp[index+1][0][cap]);
                    
                    dp[index][buy][cap] = profit;
                }
            }
        }

        //Liberty to buy --> 1
        //Else buy --> 0
        //Max no. of transactions allowed --> k
        
        return dp[0][1][k];
    }
};


//Solution by Tabulation Method (Space Optimized)

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
                
        int n = prices.size();
        
        vector <vector <int>> dp (2 , vector <int> (k + 1, 0));
        
        for (int buy = 0; buy <= 1; buy++)          //  This initialization can be omitted as we have already assigned 0 to all
        {
            dp[buy][0] = 0;
        }
        
        for (int index = n - 1; index >= 0; index--)
        {
            vector <vector <int>> temp (2 , vector <int> (k + 1, 0));
            
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
                {
                    int profit;
                    
                    if (buy)
                        profit = max (-prices[index] + dp[0][cap], dp[1][cap]);
                    
                    else
                        profit = max (+prices[index] + dp[1][cap - 1], dp[0][cap]);
                    
                    temp[buy][cap] = profit;
                }
            }
            
            dp = temp;
        }
        
        //Liberty to buy --> 1
        //Else buy --> 0
        //Max no. of transactions allowed --> k

        return dp[1][k];
    }
};


//Another approach

//Solved by Memoization Method

class Solution {
public:
    
    int func (int index, int transaction, int k, vector <vector <int>> &dp , vector<int>& prices)
    {
        if (index == prices.size() || transaction == 2 * k)
            return 0;
        
        if (dp[index][transaction] != -1)
            return dp[index][transaction];
        
        int profit;
        
        if (transaction % 2 == 0)       //  Buying is allowed
            profit = max (-prices[index] + func (index + 1, transaction + 1, k, dp, prices), func (index + 1, transaction, k, dp, prices));
        
        else                           //   Selling is allowed
            profit = max (+prices[index] + func (index + 1, transaction + 1, k, dp, prices), func (index + 1, transaction, k, dp, prices));
        
        return dp[index][transaction] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
                
        int n = prices.size();
        
        vector <vector <int>> dp (n, vector <int> (2 * k, -1));
        
        //  0   1   2   3   ...     k - 1     k
        //  B   S   B   S   ...      B        S

        return func (0, 0, k, dp, prices);
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
                
        int n = prices.size();
        
        vector <vector <int>> dp (n + 1, vector <int> (2 * k + 1, 0));
        
        for (int transaction = 0; transaction <= 2 * k; transaction++)       //  This initialization can be omitted as we have already assigned 0 to all
            dp[n][transaction] = 0;
        
        for (int index = 0; index <=n; index++)                         //  This initialization can be omitted as we have already assigned 0 to all
            dp[index][2 * k] = 0;
        
        for (int index = n - 1; index >= 0; index--)
        {
            for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
            {
                int profit;
                
                if (transaction % 2 == 0)           //  Buying is allowed
                    profit = max (-prices[index] + dp[index + 1][transaction + 1],  dp[index + 1][transaction]);
                                  
                else                                //   Selling is allowed
                    profit = max (+prices[index] + dp[index + 1][transaction + 1],  dp[index + 1][transaction]);
                                  
                dp[index][transaction] = profit;
            }
        }
        
        //  0   1   2   3   ...     k - 1     k
        //  B   S   B   S   ...      B        S

        return dp[0][0];
    }
};


//Solution by Tabulation Method (Space Optimized)

class Solution {
public:
    
    int maxProfit(int k, vector<int>& prices) {
                
        int n = prices.size();
        
        vector <int> dp (2 * k + 1, 0);
        
        for (int transaction = 0; transaction <= 2 * k; transaction++)      //  This initialization can be omitted as we have already assigned 0 to all
            dp[transaction] = 0;
        
        
        for (int index = n - 1; index >= 0; index--)
        {
            vector <int> temp (2 * k + 1, 0);
            
            for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
            {
                int profit;
                
                if (transaction % 2 == 0)           //  Buying is allowed
                    profit = max (-prices[index] + dp[transaction + 1],  dp[transaction]);
                                  
                else                               //   Selling is allowed
                    profit = max (+prices[index] + dp[transaction + 1],  dp[transaction]);
                                  
                temp[transaction] = profit;
            }
            
            dp = temp;
        }
        
        //  0   1   2   3   ...     k - 1     k
        //  B   S   B   S   ...      B        S

        return dp[0];
    }
};