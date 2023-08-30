// Problem Link :- https://leetcode.com/problems/minimum-replacements-to-sort-the-array/

// Solved by Math 
// Time Complexity :- O(N)
// Space Complexity :- O(1)

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int n = nums.size();
        long long ops = 0;
        int maxMin = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            int parts = ceil(nums[i] * 1.0/maxMin);
            ops += parts - 1;
            maxMin = nums[i]/parts;
        }

        return ops;
    }
};