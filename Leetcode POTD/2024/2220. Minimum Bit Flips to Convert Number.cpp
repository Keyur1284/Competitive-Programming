// Problem Link :- https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

// Solved by Bit Manipulation
// Time Complexity :- O(log(max(start, goal)))
// Space Complexity :- O(1)

class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int bitFlips = 0;

        while (start || goal)
        {
            if ((start & 1) ^ (goal & 1))
                bitFlips++;

            start >>= 1;
            goal >>= 1;
        }

        return bitFlips;
    }
};



class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        if (start == 0 && goal == 0) 
            return 0;

        int flip = (start & 1) != (goal & 1);
        return flip + minBitFlips(start >> 1, goal >> 1);
    }
};



class Solution {
public:
    int minBitFlips(int start, int goal) {

        int xorResult = start ^ goal, count = 0;

        while (xorResult) 
        {
            count += xorResult & 1;
            xorResult >>= 1;
        }

        return count;
    }
};



class Solution {
public:
    int minBitFlips(int start, int goal) {

        int xorResult = start ^ goal, count = 0;

        while (xorResult) 
        {
            xorResult &= (xorResult - 1);
            count++;
        }
        return count;
    }
};



class Solution {
public:
    int minBitFlips(int start, int goal) {

        return __builtin_popcount(start ^ goal);
    }
};