// Problem Link :- https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/

// Solved by Gray Code Method
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int minimumOneBitOperations(int n) {
        
        int ans = 0;
        
        while (n)
        {
            ans ^= n;
            n >>= 1;
        }

        return ans;
    }
};



class Solution {
public:
    int minimumOneBitOperations(int n) {
        
        int ans = n;
        ans ^= ans >> 16;
        ans ^= ans >> 8;
        ans ^= ans >> 4;
        ans ^= ans >> 2;
        ans ^= ans >> 1;
        
        return ans;
    }
};