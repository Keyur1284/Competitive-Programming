// Problem Link :- https://leetcode.com/problems/spiral-matrix-ii/

// Time Complexity :- O(n^2)
// Space Complexity :- O(1)

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int top = 0, bottom = n - 1, left = 0, right = n - 1;

        vector<vector<int>> spiral(n, vector<int> (n));

        int num = 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                spiral[top][i] = num++;

            top++;

            for (int i = top; i <= bottom; i++)
                spiral[i][right] = num++;

            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    spiral[bottom][i] = num++;

                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    spiral[i][left] = num++;

                left++;
            }
        }

        return spiral;
    }
};


class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {
        
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1, row = 0, col = 0, d = 0;
        
        vector<vector<int>> spiral(n, vector<int> (n, 0));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (num <= n * n)
        {
            spiral[row][col] = num++;

            int r = (row + dir[d][0] + n) % n;
            int c = (col + dir[d][1] + n) % n;

            if (spiral[r][c] != 0)
                d = (d + 1) % 4;

            row += dir[d][0];
            col += dir[d][1];    
        }

        return spiral;
    }
};