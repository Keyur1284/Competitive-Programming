// Problem Link :- https://leetcode.com/problems/score-after-flipping-matrix/

// Solved by Greedy Approach
// Time Complexity :- O(m * n)
// Space Complexity :- O(1)

class Solution {
public:
    int matrixScore(vector<vector<int>> &grid) {
        
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    grid[i][j] ^= 1;
                }
            }
        }

        for (int j = 1; j < n; j++)
        {
            int zeros = 0;

            for (int i = 0; i < m; i++)
                zeros += (grid[i][j] == 0);

            if (zeros > m - zeros)
            {
                for (int i = 0; i < m; i++)
                {
                    grid[i][j] ^= 1;
                }
            } 
        }

        int score = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                score += (grid[i][j] << (n - j - 1));
            }
        }

        return score;
    }
};



// Solved by Greedy Approach (Without Modifying Input)
// Time Complexity :- O(m * n)
// Space Complexity :- O(1)

class Solution {
public:
    int matrixScore(vector<vector<int>> &grid) {
        
        int m = grid.size(), n = grid[0].size();
        int score = m * (1 << (n - 1));
        
        for (int j = 1; j < n; j++) 
        {
            int countSameBits = 0;
            for (int i = 0; i < m; i++) 
            {
                if (grid[i][j] == grid[i][0])
                    countSameBits++;
            }

            countSameBits = max(countSameBits, m - countSameBits);

            int columnScore = (1 << (n - j - 1)) * countSameBits;
            score += columnScore;
        }

        return score;
    }
};