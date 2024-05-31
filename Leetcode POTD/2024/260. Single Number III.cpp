// Problem Link :- https://leetcode.com/problems/single-number-iii/

// Solved by Bit Manipulation
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long xorVal = 0;

        for (auto &it : nums)
            xorVal ^= it;

        int rightSetBitMask = (xorVal & -xorVal);
        // int rightSetBitMask = (xorVal ^ (xorVal & (xorVal - 1)));

        // (xorVal & -xorVal) will give the rightmost set bit of xorVal
        // (xorVal ^ (xorVal & (xorVal - 1))) will also give the rightmost set bit of xorVal

        int set = 0, unset = 0;

        for (auto &it : nums)
        {
            (it & rightSetBitMask) ? set ^= it : unset ^= it;
        }

        return {set, unset};
    }
};