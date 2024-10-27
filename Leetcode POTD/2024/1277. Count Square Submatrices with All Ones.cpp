// Problem Link :- https://leetcode.com/problems/count-square-submatrices-with-all-ones/

// Solved by 2D Prefix Sum
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                matrix[i][j] += matrix[i][j] * min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
            }
        }

        int squares = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                squares += matrix[i][j];
        }

        return squares;
    }
};