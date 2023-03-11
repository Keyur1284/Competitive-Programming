//Problem Link :- https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size(), count = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
                count++;
        }

        return (count <= 1);        
    }
};