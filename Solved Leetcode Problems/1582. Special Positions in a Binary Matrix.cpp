// Problem Link :- https://leetcode.com/problems/special-positions-in-a-binary-matrix/

// Solved by Brute Force Approach
// Time Complexity :- O(m * n * (m + n))
// Space Complexity :- O(1)

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int special = 0, m = mat.size(), n = mat[0].size();
        
        for (int row = 0; row < m; row++) 
        {
            for (int col = 0; col < n; col++) 
            {
                if (mat[row][col] == 0) 
                    continue;
                
                bool good = true;
                
                for (int r = 0; r < m && good; r++)
                {
                    if (r != row && mat[r][col] == 1) 
                        good = false;
                }
                
                for (int c = 0; c < n && good; c++) 
                {
                    if (c != col && mat[row][c] == 1)
                        good = false;
                }
                
                if (good)
                    special++;
            }
        }
        
        return special;
    }
};



// Solved by Optimized Approach
// Time Complexity :- O(m * n)
// Space Complexity :- O(m + n)

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int special = 0, m = mat.size(), n = mat[0].size();
        vector<int> rowCount(m, 0), colCount(n, 0);
        
        for (int row = 0; row < m; row++) 
        {
            for (int col = 0; col < n; col++) 
            {
                if (mat[row][col] == 1) 
                {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }
        
        for (int row = 0; row < m; row++) 
        {
            for (int col = 0; col < n; col++) 
            {
                if (mat[row][col] == 1) 
                {
                    if (rowCount[row] == 1 && colCount[col] == 1)
                        special++;
                }
            }
        }
        
        return special;
    }
};