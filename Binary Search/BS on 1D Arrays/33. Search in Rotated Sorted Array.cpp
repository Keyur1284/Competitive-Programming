// Problem Link :- https://leetcode.com/problems/search-in-rotated-sorted-array/

// Solved by Binary Search
// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (nums[mid] == target)    
                return mid;

            // Left is sorted
            else if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                    high = mid - 1;

                else
                    low = mid + 1;
            }

            // Right is sorted
            else if (nums[high] >= nums[mid])
            {
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1;

                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};