// Problem Link :- https://leetcode.com/problems/power-of-four/

// Solved by Bit Manipulation
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        int mask = 0;

        // Setting alternate bits to 1

        for (int i = 0; i < 32; i += 2)
            mask |= (1 << i);

        return ((n > 0) && ((n & (n - 1)) == 0) && ((n & mask) == n));
    }
};



// Solved by Math
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if ((n > 0) && ((n & (n - 1)) == 0)) 
        {
            int zeroes = 0;

            while (n > 1) 
            {
                zeroes++;
                n >>= 1;
            }

            return (zeroes % 2 == 0);
        }

        return false;
    }
};



// Solved by Logarithmic Approach
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if (n <= 0)
            return false;

        double logValue = log10(n) / log10(4);

        return (floor(logValue) == ceil(logValue));
    }
};

class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if (n <= 0)
            return false;

        double logValue = log(n) / log(4);

        return (floor(logValue) == ceil(logValue));
    }
};