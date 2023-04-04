// Problem Link :- https://leetcode.com/problems/next-permutation/description/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int index = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > index; i--)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[index], nums[i]);
                break;
            }
        }

        reverse (nums.begin() + index + 1, nums.end());
    }
};


// Solved using inbuilt next_permutation function

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        next_permutation(nums.begin(), nums.end());
    }
};