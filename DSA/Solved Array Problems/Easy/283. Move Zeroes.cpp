// Problem Link :- https://leetcode.com/problems/move-zeroes/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size(), zero_index = -1;

        for (int index = 0; index < n; index++)
        {
            if (nums[index] == 0 && zero_index == -1)
                zero_index = index;

            if (nums[index] != 0 && zero_index != -1)
            {
                swap(nums[index], nums[zero_index]);
                zero_index++;
            }
        }
    }
};

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();

        for (int index = 0, zero_index = 0; index < n; index++)
        {
            if (nums[index] != 0)
                swap(nums[index], nums[zero_index++]);
        }
    }
};