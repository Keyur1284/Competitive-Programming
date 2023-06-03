// Problem Link :- https://leetcode.com/problems/binary-search/

// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

// Solved by Iterative Binary Searching

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low = 0, high = nums.size() - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};


// Solved by Recursive Binary Searching

class Solution {
public:

    int binarySearch (int low, int high, int &target, vector<int> &nums)
    {
        if (low > high)
            return -1;

        int mid = (low + high) >> 1;

        if (nums[mid] == target)    
            return mid;

        else if (nums[mid] < target)
            return binarySearch (mid + 1, high, target, nums);

        else
            return binarySearch (low, mid - 1, target, nums);
    }

    int search(vector<int>& nums, int target) {
        
        return binarySearch (0, nums.size() - 1, target, nums);
    }
};


// Solved by inbuilt upper_bound function

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int index = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        return (index > 0 && nums[index - 1] == target) ? index - 1 : -1;
    }
};


// Solved by inbuilt lower_bound function

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        return (index < nums.size() && nums[index] == target) ? index : -1;
    }
};