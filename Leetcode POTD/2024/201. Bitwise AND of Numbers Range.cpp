// Problem Link :- https://leetcode.com/problems/bitwise-and-of-numbers-range/

// Solved by Bit Manipulation
// Time Complexity :- O(32)
// Space Complexity :- O(1)

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int mask = 1 << 30, andVal = 0;

        while (mask && (left & mask) == (right & mask))
        {
            andVal |= (left & mask);
            mask >>= 1;
        }

        return andVal;
    }
};



class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int bit = 0;

        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            bit++;
        }

        return (left << bit);
    }
};



class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        while (right > left)
        {
            right = right & (right - 1);
        }

        return right;
    }
};