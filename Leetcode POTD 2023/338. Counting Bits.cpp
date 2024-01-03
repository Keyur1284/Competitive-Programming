// Problem Link :- https://leetcode.com/problems/counting-bits/

// Solved by using built in popcount function
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> bitCount;

        for (int i = 0; i <= n; i++)
        {
            int bits = __builtin_popcount(i);
            bitCount.emplace_back(bits);
        }

        return bitCount;
    }
};



// Solved by Bit Manipulation
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> bitCount;

        for (int i = 0; i <= n; i++)
        {
            int bits = 0;
            int num = i;
            
            while (num > 0)
            {
                bits++;
                num &= (num - 1);
            }
            
            bitCount.emplace_back(bits);
        }

        return bitCount;
    }
};



// Solved by Dynamic Programming
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> bitCount(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            bitCount[i] = bitCount[i & (i - 1)] + 1;
        }

        return bitCount;
    }
};



class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> bitCount(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            bitCount[i] = bitCount[i >> 1] + (i & 1);
        }

        return bitCount;
    }
};
