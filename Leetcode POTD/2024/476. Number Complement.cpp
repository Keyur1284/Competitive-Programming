// Problem Link :- https://leetcode.com/problems/number-complement/

// Solved by Bit Manipulation
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    int findComplement(int num) {
        
        return (unsigned)~0 >> __builtin_clz(num) ^ num;
    }
};



class Solution {
public:
    int findComplement(int num) {
        
        return INT_MAX >> (__builtin_clz(num) - 1) ^ num;
    }
};



class Solution {
public:
    int findComplement(int num) {
        
        unsigned mask = ~0;
        
        while (num & mask) 
            mask <<= 1;
        
        return ~mask & ~num;
    }
};