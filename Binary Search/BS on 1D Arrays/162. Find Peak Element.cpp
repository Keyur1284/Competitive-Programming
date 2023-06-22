// Problem Link :- https://leetcode.com/problems/find-peak-element/

// Solved by Binary Search
// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size();

        if (n == 1 || nums[0] > nums[1])
            return 0;

        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;

            else if (nums[mid] < nums[mid - 1])
                high = mid - 1;

            else
                low = mid + 1;
        }

        return 0;
    }
};