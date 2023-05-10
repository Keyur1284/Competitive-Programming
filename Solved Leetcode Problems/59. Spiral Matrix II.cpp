// Problem Link :- https://leetcode.com/problems/spiral-matrix-ii/

// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

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