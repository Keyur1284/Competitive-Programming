// Problem Link :- https://leetcode.com/problems/set-matrix-zeroes/

// Time Complexity :- O(m*n)
// Space Complexity :- O(m) + O(n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0), col(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


// Time Complexity :- O(m*n)
// Space Complexity :- O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        bool isColZero = false;

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
                isColZero = true;

            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        if (isColZero)
        {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }   
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        bool isRowZero = false;

        for (int j = 0; j < n; j++)
        {
            if (matrix[0][j] == 0)
                isRowZero = true;

            for (int i = 1; i < m; i++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }

        if (isRowZero)
        {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }   
    }
};
