// Problem Link :- https://leetcode.com/problems/rotate-image/

// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        vector<vector<int>> grid (n, vector<int> (n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = grid;
    }
};


// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        vector<vector<int>> grid (n, vector<int> (n));

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};