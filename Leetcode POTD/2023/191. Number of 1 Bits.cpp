// Problem Link :- https://leetcode.com/problems/number-of-1-bits/

// Solved by builtin function
// Time Complexity :- O(log_2(n))
// Space Complexity :- O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {

        return __builtin_popcount(n);
    }
};



// Solved by Brian Kernighan’s Algorithm
// Time Complexity :- O(log_2(n))
// Space Complexity :- O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {

        int ones = 0;

        while (n)
        {
            n &= (n - 1);
            ones++;
        }

        return ones;
    }
};



// Solved by Bit Manipulation
// Time Complexity :- O(log_2(n))
// Space Complexity :- O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {

        int ones = 0;

        while(n)
        {
            ones += (n & 1);
            n >>= 1;
        }

        return ones;
    }
};