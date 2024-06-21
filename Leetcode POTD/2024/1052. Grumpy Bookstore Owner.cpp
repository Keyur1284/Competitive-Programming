// Problem Link :- https://leetcode.com/problems/grumpy-bookstore-owner/

// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n = customers.size(), maxSadCount = 0, sadCount = 0;

        for (int i = 0; i < n; i++)
        {
            sadCount += customers[i] * grumpy[i];

            if (i >= minutes)
                sadCount -= customers[i - minutes] * grumpy[i - minutes];

            maxSadCount = max(sadCount, maxSadCount);
        }

        int totalSatisfied = maxSadCount;

        for (int i = 0; i < n; i++)
        {
            totalSatisfied += customers[i] * (1 - grumpy[i]);
        }

        return totalSatisfied;
    }
};