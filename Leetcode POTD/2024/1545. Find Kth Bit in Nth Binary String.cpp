// Problem Link :- https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

// Solved by Simulation
// Time Complexity :- O(2^n)
// Space Complexity :- O(2^n)

class Solution {
public:
    char findKthBit(int n, int k) {
        
        string sequence = "0";

        for (int i = 1; i < n && k > sequence.length(); i++) 
        {
            string temp = sequence;
            sequence += '1';

            for (int j = temp.length() - 1; j >= 0; --j) 
            {
                char invertedBit = temp[j] ^ '0' ^ '1';
                sequence += invertedBit;
            }
        }
        
        return sequence[k - 1];
    }
};