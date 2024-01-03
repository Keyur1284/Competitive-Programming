// Problem Link :-  https://leetcode.com/problems/transpose-matrix/

// Solved by Brute Force Approach
// Time Complexity :- O(n*m)
// Space Complexity :- O(m*n)

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> matrixT(m, vector<int> (n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                matrixT[j][i] = matrix[i][j];
        }

        return matrixT;
    }
};