// Problem Link :- https://leetcode.com/problems/missing-number/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size(), xor1 = 0, xor2 = 0;

        for (int i = 1; i <= n; i++)
            xor1 ^= i;

        for (int i = 0; i < n; i++)
            xor2 ^= nums[i];
        
        return (xor1 ^ xor2);
    }
};