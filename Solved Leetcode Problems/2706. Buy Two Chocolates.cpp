// Problem Link :- https://leetcode.com/problems/buy-two-chocolates/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        sort(prices.begin(), prices.end());

        if (prices[0] + prices[1] > money)
            return money;

        else
            return money - (prices[0] + prices[1]);
    }
};



// Solved using nth_element() function
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        nth_element(prices.begin(), prices.begin() + 1, prices.end());
        
        if (prices[0] + prices[1] > money)
            return money;
        
        else
            return money - (prices[0] + prices[1]);
    }
};