// Problem Link :- https://leetcode.com/problems/sum-of-square-numbers/

// Solved by Binary Search
// Time Complexity :- O(c ^ 0.5 * logc)
// Space Complexity :- O(1)

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for (long a = 0; a * a <= c; a++)
        {
            long low = a, high = c - a * a, b = high;

            while (low <= high)
            {
                long mid = (low + high) >> 1;
                
                if (mid * mid == b)
                    return true;

                if (mid * mid < b)
                    low = mid + 1;

                else
                    high = mid - 1;
            }
        }

        return false;
    }
};



// Solved by Math
// Time Complexity :- O(c ^ 0.5 * logc)     // logc for sqrt
// Space Complexity :- O(1)

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for (long a = 0; a * a <= c; a++)
        {
            double b = sqrt(c - (a * a));

            if (b == (int)b)
                return true;
        }

        return false;
    }
};