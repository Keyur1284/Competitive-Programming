// Problem Link :- https://leetcode.com/problems/binary-search/

// Time Complexity :- O(logn)
// Space Complexity :- O(1)

// Solved using Binary Search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
                high = mid - 1;

            else
                low = mid + 1;
        }

        return -1;
    }
};


// Solved using inbuilt upper_bound function

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
            int index = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            
            return (index > 0 && nums[index - 1] == target) ? index - 1 : -1;
    }
};