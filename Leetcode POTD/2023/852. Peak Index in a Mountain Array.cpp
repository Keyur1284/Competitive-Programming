// Problem Link :- https://leetcode.com/problems/peak-index-in-a-mountain-array/

// Solved by Binary Search
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        
        int n = nums.size();
        int low = 1, high = n - 2, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;

            else if (nums[mid - 1] > nums[mid])
                high = mid - 1;

            else
                low = mid + 1;
        } 

        return 0;
    }
};