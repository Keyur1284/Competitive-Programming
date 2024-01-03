// Problem Link :- https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size(), curr = 0, ops = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
                curr++;

            ops += curr;
        }

        return ops;
    }
};