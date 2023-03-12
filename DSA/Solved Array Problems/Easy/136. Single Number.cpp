// Problem Link :- https://leetcode.com/problems/single-number/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int XOR = 0;

        for (auto &it : nums)
            XOR ^= it;

        return XOR;
    }
};