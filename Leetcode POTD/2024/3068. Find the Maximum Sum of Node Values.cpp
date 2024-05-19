// Problem Link :- https://leetcode.com/problems/find-the-maximum-sum-of-node-values/

// Solved by Bitmanipulation + Math
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        long long maxSum = 0;
        int minSacrifice = INT_MAX, count = 0;

        for (auto &it : nums)
        {
            if ((it ^ k) > it)
            {
                count++;
                maxSum += it ^ k;
                minSacrifice = min(minSacrifice, (it ^ k) - it);
            }

            else
            {
                maxSum += it;
                minSacrifice = min(minSacrifice, it - (it ^ k));
            }
        }

        return (count & 1) ? maxSum - minSacrifice : maxSum;
    }
};