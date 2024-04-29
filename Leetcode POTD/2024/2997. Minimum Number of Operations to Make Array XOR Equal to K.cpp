// Problem Link :- https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

// Solved by Bit Manipulation
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int xorVal = 0;

        for (auto &it : nums)
            xorVal ^= it;

        int ops = 0;

        for (int bit = 0; bit < 32; bit++)
        {
            int bitVal = (1 << bit);

            if ((xorVal & bitVal) != (k & bitVal))
                ops++;
        }

        return ops;
    }
};



class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int xorVal = 0;

        for (auto &it : nums)
            xorVal ^= it;

        int ops = 0;

        for (int bit = 0; bit < 32; bit++)
        {
            int bitVal = (1 << bit);

            if ((xorVal ^ k) & bitVal)
                ops++;
        }

        return ops;
    }
};