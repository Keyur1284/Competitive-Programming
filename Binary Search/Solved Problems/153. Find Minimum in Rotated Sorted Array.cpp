// Problem Link :- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Solved by Binary Search
// Time Complexity : O(log_2 n)
// Space Complexity : O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size();
        int low = 0, high = n - 1, mid, ans = INT_MAX; 

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (nums[low] <= nums[mid])
            {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }

            else if (nums[high] >= nums[mid])
            {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};