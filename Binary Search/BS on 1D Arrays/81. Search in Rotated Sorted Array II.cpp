// Problem Link :- https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// Solved by Binary Search
// Worst Case Time Complexity :- O(n)
// Average Time Complexity : O(log_2 n)
// Space Complexity :- O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0, high = n - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (nums[mid] == target)
                return true;

            if (nums[low] == nums[mid] && nums[high] == nums[mid])
            {
                low++;
                high--;
                continue;
            }

            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                    high = mid - 1;

                else
                    low = mid + 1;
            }

            else if (nums[high] >= nums[mid])
            {
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1;

                else
                    high = mid - 1;
            }
        }

        return false;
    }
};