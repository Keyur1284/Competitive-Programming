// Problem Link :- https://leetcode.com/problems/spiral-matrix/

// Time Complexity :- O(mn)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        vector<int> spiral;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                spiral.emplace_back(matrix[top][i]);

            top++;

            for (int i = top; i <= bottom; i++)
                spiral.emplace_back(matrix[i][right]);

            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    spiral.emplace_back(matrix[bottom][i]);

                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    spiral.emplace_back(matrix[i][left]);

                left++;
            }
        }

        return spiral;
    }
};