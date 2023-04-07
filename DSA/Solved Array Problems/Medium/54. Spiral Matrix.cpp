// Problem Link :- https://leetcode.com/problems/spiral-matrix/

// Time Complexity :- O(m*n)
// Space Complexity :- O(m*n)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        vector<int> ans;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; i++)
                ans.emplace_back(matrix[top][i]);

            top++;

            for (int i = top; i <= bottom; i++)
                ans.emplace_back(matrix[i][right]);

            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    ans.emplace_back(matrix[bottom][i]);
                
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    ans.emplace_back(matrix[i][left]);

                left++;
            }
        }

        return ans;
    }
};