// Problem Link :- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

// Solved by Iterative Binary Search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int first = -1, last = -1, low = 0, high = n - 1, ans = n, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (nums[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }

            else 
                low = mid + 1;
        }

        if (ans == n || nums[ans] != target)
            return {first, last};

        first = ans;

        low = 0, high = n - 1, ans = n;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (nums[mid] <= target)
            {
                ans = mid;
                low = mid + 1;
            }

            else 
                high = mid - 1;
        }

        last = ans;

        return {first, last};
    }
};

// Solved by inbuilt lower_bound and upper_bound functions

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = lower_bound (nums.begin(), nums.end(), target) - nums.begin();
        
        if (first >= nums.size() || nums[first] != target)
            return {-1, -1};

        int last = upper_bound (nums.begin(), nums.end(), target) - nums.begin();

        return {first, last - 1};
    }
};