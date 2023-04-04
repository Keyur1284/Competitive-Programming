// Problem Link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> maxi(n, 0);

        maxi[n - 1] = prices.back();

        for (int i = n - 2; i >= 0; i--)
            maxi[i] = max(maxi[i + 1], prices[i]);

        int profit = 0;

        for (int i = 0; i < n; i++)
            profit = max(profit, maxi[i] - prices[i]);

        return profit;
    }
};

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0];
        int n = prices.size();
        int profit = 0;

        for (int i = 1; i < n; i++)
        {
            int temp = prices[i] - mini;
            profit = max(profit, temp);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};