// Problem Link :- https://leetcode.com/problems/find-a-peak-element-ii/

// Solved by Binary Search on rows
// Time Complexity :- O(n * logm)
// Space Complexity :- O(1)

class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        int startRow = 0, endRow = m - 1, midRow, maxCol = 0;
        
        while (startRow <= endRow)
        {
            midRow = (startRow + endRow) >> 1;

            for (int col = 0; col < n; col++)
            {
                maxCol = (mat[midRow][col] > mat[midRow][maxCol]) ? col : maxCol;
            }

            bool isUpBig = (midRow - 1 >= startRow && mat[midRow - 1][maxCol] > mat[midRow][maxCol]);
            bool isDownBig = (midRow + 1 <= endRow && mat[midRow + 1][maxCol] > mat[midRow][maxCol]);

            if (!isUpBig && !isDownBig)
                return {midRow, maxCol};

            if (isDownBig)
                startRow = midRow + 1;

            else 
                endRow = midRow - 1;
        }

        return {};
    }
};



// Solved by Binary Search on columns
// Time Complexity :- O(m * logn)
// Space Complexity :- O(1)

class Solution {
public:

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        int startCol = 0, endCol = n - 1, midCol, maxRow = 0;
        
        while (startCol <= endCol)
        {
            midCol = (startCol + endCol) >> 1;

            for (int row = 0; row < m; row++)
            {
                maxRow = (mat[row][midCol] > mat[maxRow][midCol]) ? row : maxRow;
            }

            bool isLeftBig = (midCol - 1 >= startCol && mat[maxRow][midCol - 1] > mat[maxRow][midCol]);
            bool isRightBig = (midCol + 1 <= endCol && mat[maxRow][midCol + 1] > mat[maxRow][midCol]);

            if (!isLeftBig && !isRightBig)
                return {maxRow, midCol};

            if (isLeftBig)
                endCol = midCol - 1;

            else 
                startCol = midCol + 1;
        }

        return {};
    }
};



// Solved by linear traversal along rows and columns simultaneously
// Time Complexity :- O(m + n)
// Space Complexity :- O(1)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        int row = 0, col = n - 1;

        while (row < m && col >= 0)
        {
            bool flag = true;

            for (int i = 0; i < 4; i++)
            {
                int newx = row + dx[i];
                int newy = col + dy[i];

                if (newx >= 0 && newy >= 0 && newx < m && newy < n)
                {
                    if (mat[newx][newy] > mat[row][col])
                    {
                        row += dx[i];
                        col += dy[i];
                        flag = false;
                        break;
                    }
                }
            }

            if (flag)
                return {row, col};
        }

        return {};
    }
};