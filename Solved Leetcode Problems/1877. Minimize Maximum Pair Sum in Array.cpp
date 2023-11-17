// Problem Link :- https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        int n = nums.size(), maxSum = 0;
        sort (nums.begin(), nums.end());
        
        for (int i = 0; i < n/2; i++)
        {
            int sum = nums[i] + nums[n - i - 1];
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};