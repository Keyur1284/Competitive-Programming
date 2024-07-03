// Problem Link :- https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int minDifference(vector<int>& nums) {
        
        int n = nums.size();

        if (n <= 4) 
            return 0;

        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;

        for (int left = 0, right = n - 4; left < 4; left++, right++) 
        {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};



// Solved by Partial Sorting
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(), minDiff = INT_MAX;
        
        if (n <= 4) 
            return 0;

        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        nth_element(nums.begin() + 4, nums.begin() + (n - 4), nums.end());
        sort(nums.begin() + (n - 4), nums.end());

        for (int left = 0, right = n - 4; left < 4; left++, right++) 
        {
            minDiff = min(minDiff, nums[right] - nums[left]);
        }

        return minDiff;
    }
};