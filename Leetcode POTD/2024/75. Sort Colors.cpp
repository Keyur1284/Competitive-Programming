// Problem Link :- https://leetcode.com/problems/sort-colors/

// Solved using Counting Sort
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> count(3, 0);
        
        for (auto &it : nums)
            count[it]++;

        int index = 0;

        for (int i = 0; i < 3; i++)
        {
            while (count[i]--)
                nums[index++] = i;
        }
    }
};



// Solved using Dutch National Flag's Algorithm
// arr[0 ... low - 1] = 0
// arr[low ... mid - 1] = 1
// arr[mid ... high] = unsorted
// arr[high + 1 ... n - 1] = 2

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
                swap(nums[low++], nums[mid++]);

            else if (nums[mid] == 1)
                mid++;

            else if (nums[mid] == 2)
                swap(nums[mid], nums[high--]);
        }
    }
};