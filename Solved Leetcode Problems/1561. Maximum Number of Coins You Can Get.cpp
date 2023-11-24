// Problem Link :- https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

// Solved by Sorting and Greedy Approach
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(), piles.end());
        int n = piles.size(), coins = 0;

        for (int i = n - 1; i >= n/3; i -= 2)
        {
            coins += piles[i - 1];
        }

        return coins;
    }
};