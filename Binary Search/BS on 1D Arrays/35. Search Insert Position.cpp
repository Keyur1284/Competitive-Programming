// Problem Link :- https://leetcode.com/problems/search-insert-position/

// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

// Solved by Iterative Binary Search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1, mid, ans = nums.size();

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

        return ans;
    }
};


// Solved by inbuilt lower_bound function

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        return index;
    }
};