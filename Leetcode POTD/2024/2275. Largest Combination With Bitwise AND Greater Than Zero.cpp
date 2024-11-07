// Problem Link :- https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/

// Solved using bit count vector
// Time Complexity :- O(n * 32) = O(n)
// Space Complexity :- O(32) = O(1)

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        vector<int> bitFreq(32, 0);

        for (int val : candidates)
        {
            for (int bit = 0; bit < 32; bit++)
            {
                int mask = 1 << bit;

                if (mask & val)
                    bitFreq[bit]++;
            }
        }

        return *max_element(bitFreq.begin(), bitFreq.end());
    }
};



// Solved without using extra space
// Time Complexity :- O(n * 32) = O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int maxCount = 0;
        
        for (int bit = 0; bit < 32; bit++) 
        {
            int count = 0, mask = 1 << bit;

            for (int num : candidates) 
            {
                if (num & mask)
                    count++;
            }

            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};