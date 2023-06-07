// Problem Link :- https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

// Time Complexity :- O(log_2 n)
// Space Complexity :- O(1)

// Solved by using bitset

class Solution {
public:
    int minFlips(int a, int b, int c) {
    
        bitset<32> bsa(a), bsb(b), bsc(c);
        int flips = 0;

        for (int pos = 0; pos < 32; pos++)
        {
            int bita = bsa[pos], bitb = bsb[pos], bitc = bsc[pos];

            if ((bita | bitb) == bitc)
                continue;

            if (bitc == 0)
            {
                flips += (bita == 1) + (bitb == 1);
            }

            else if (bitc == 1)
            {
                flips++;
            }
        }

        return flips;
    }
};


// Solved by using inbuilt popcount function    (__builtin_popcount (num))

class Solution {
public:
    int minFlips(int a, int b, int c) {
    
        return __builtin_popcount ((a | b) ^ c) + __builtin_popcount ((a & b) & ((a | b) ^ c));
    }
};