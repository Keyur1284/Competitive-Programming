// Problem Link :- https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

// Solved by traversing
// Time Complexity :- O(n * m)      n = number of banks
// Space Complexity :- O(1)         m = number of cells in each bank

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prev = 0, beams = 0;

        for (auto &row : bank)
        {
            int one = count(row.begin(), row.end(), '1');

            if (one)
            {
                beams += prev * one;
                prev = one;
            }
        }

        return beams;
    }
};