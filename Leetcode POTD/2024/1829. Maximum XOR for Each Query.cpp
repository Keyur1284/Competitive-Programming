// Problem Link :- https://leetcode.com/problems/maximum-xor-for-each-query/

// Solved by prefix xor and bit masking
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int n = nums.size(), prefXor = (1 << maximumBit) - 1;
        vector<int> getMaxXor(n);

        for (int val : nums)
            prefXor ^= val;

        for (int i = 0; i < n; i++)
        {
            getMaxXor[i] = prefXor;
            prefXor ^= nums[n - i - 1];
        }

        return getMaxXor;
    }
};