// Problem Link :- https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Solved using STL function
// Time Complexity : O(n)
// Space Complexity : O(1)


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        nums.resize(unique(nums.begin(), nums.end()) - nums.begin()); 

        // nums.resize(distance(nums.begin(), unique(nums.begin(), nums.end())));

        return nums.size();
    }
};


// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size(), index = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
                nums[index++] = nums[i];
        }

        return index;        
    }
};