//Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector <int> dp(n, 0);
        dp[0] = 0;
        int mini = prices[0];
        
        for(int i=1; i<n; i++)
        {
            int cost = prices[i] - mini;
            dp[i] = max (dp[i - 1], cost);
            mini = min (mini, prices[i]);
        }

        return dp[n-1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0], maxProfit = 0;
        
        for (int i = 1; i < prices.size(); i++)
        {
            int cost = prices[i] - mini;
            maxProfit = max (maxProfit, cost);
            mini = min(mini, prices[i]);
        }
        
        return maxProfit;
    }
};