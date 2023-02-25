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

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<int> maxi (n, 0);
        
        maxi[n - 1] = prices[n - 1];
        int maxProfit = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            maxi[i] = max(maxi[i + 1], prices[i]);
        }

        for (int i = 0; i < n; i++)
        {
            maxProfit = max(maxProfit, maxi[i] - prices[i]);
        }

        return maxProfit;   
    }
};