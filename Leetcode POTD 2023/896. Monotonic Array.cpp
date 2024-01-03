// Problem Link :- https://leetcode.com/problems/monotonic-array/

// Solved by traversing the array once
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        int n = nums.size();
        bool increasing = true, decreasing = true;

        for (int i = 1; i < n; i++) 
        {
            if (nums[i] > nums[i - 1]) 
                decreasing = false;

            else if (nums[i] < nums[i - 1])
                increasing = false;

            if (!increasing && !decreasing)
                return false;
        }

        return true;
    }
};