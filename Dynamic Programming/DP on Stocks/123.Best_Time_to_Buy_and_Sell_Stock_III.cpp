//Problem link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

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
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector <vector <vector <int>>> dp (n, vector <vector <int>> (2 , vector <int> (3, -1)));

        //Liberty to buy --> 1
        //Else buy --> 0
        //Max no. of transactions allowed --> 2
        
        return func (0, 1, 2, dp, prices);
    }
};


//Solved by Tabulation Method

class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector <vector <vector <int>>> dp (n + 1, vector <vector <int>> (2 , vector <int> (3, 0)));
        
        for (int buy = 0; buy <= 1; buy++)              //  This initialization can be omitted as we have already assigned 0 to all
        {
            for (int cap = 0; cap <=2; cap++)
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
                for (int cap = 1; cap <= 2; cap++)
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
        //Max no. of transactions allowed --> 2
        
        return dp[0][1][2];
    }
};


//Solved by Tabulation Method (Space Optimized)

class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector <vector <int>> dp (2 , vector <int> (3, 0));
        
        for (int buy = 0; buy <= 1; buy++)          //  This initialization can be omitted as we have already assigned 0 to all
        {
            dp[buy][0] = 0;
        }
        
        for (int index = n - 1; index >= 0; index--)
        {
            vector <vector <int>> temp (2 , vector <int> (3, 0));
            
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
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
        //Max no. of transactions allowed --> 2

        return dp[1][2];
    }
};



//Another approach

//Solved by Memoization Method

class Solution {
public:
    
    int func (int index, int transaction, vector <vector <int>> &dp , vector<int>& prices)
    {
        if (index == prices.size() || transaction == 4)
            return 0;
        
        if (dp[index][transaction] != -1)
            return dp[index][transaction];
        
        int profit;
        
        if (transaction % 2 == 0)       //  Buying is allowed
            profit = max (-prices[index] + func (index + 1, transaction + 1, dp, prices), func (index + 1, transaction, dp, prices));
        
        else                           //   Selling is allowed
            profit = max (+prices[index] + func (index + 1, transaction + 1, dp, prices), func (index + 1, transaction, dp, prices));
        
        return dp[index][transaction] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector <vector <int>> dp (n, vector <int> (4, -1));
        
        //  0   1   2   3
        //  B   S   B   S

        return func (0, 0, dp, prices);
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector <vector <int>> dp (n + 1, vector <int> (5, 0));
        
        for (int transaction = 0; transaction <= 4; transaction++)       //  This initialization can be omitted as we have already assigned 0 to all
            dp[n][transaction] = 0;
        
        for (int index = 0; index <=n; index++)                         //  This initialization can be omitted as we have already assigned 0 to all
            dp[index][4] = 0;
        
        for (int index = n - 1; index >= 0; index--)
        {
            for (int transaction = 3; transaction >= 0; transaction--)
            {
                int profit;
                
                if (transaction % 2 == 0)           //  Buying is allowed
                    profit = max (-prices[index] + dp[index + 1][transaction + 1],  dp[index + 1][transaction]);
                                  
                else                                //   Selling is allowed
                    profit = max (+prices[index] + dp[index + 1][transaction + 1],  dp[index + 1][transaction]);
                                  
                dp[index][transaction] = profit;
            }
        }
        
        //  0   1   2   3
        //  B   S   B   S

        return dp[0][0];
    }
};


//Solved by Tabulation Method (Space Optimized)

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector <int> dp (5, 0);
        
        for (int transaction = 0; transaction <= 4; transaction++)      //  This initialization can be omitted as we have already assigned 0 to all
            dp[transaction] = 0;
        
        
        for (int index = n - 1; index >= 0; index--)
        {
            vector <int> temp (5, 0);
            
            for (int transaction = 3; transaction >= 0; transaction--)
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
        
        //  0   1   2   3
        //  B   S   B   S

        return dp[0];
    }
};
