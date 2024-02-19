// Problem Link :- https://leetcode.com/problems/power-of-two/

// Solved by taking log2
// Time Complexity :- O(log2(n))
// Space Complexity :- O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n <= 0)
            return false;

        int x = log2(n);
        return (1 << x == n);
    }
};



// Solved by using Bit Manipulation
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n <= 0)
            return false;

        return (n & (n - 1)) == 0;
    }
};



class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n <= 0)
            return false;

        return (n & -n) == n;
    }
};