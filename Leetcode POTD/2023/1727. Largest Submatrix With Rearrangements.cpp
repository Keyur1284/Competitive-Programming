// Problem Link :- https://leetcode.com/problems/largest-submatrix-with-rearrangements/

// Solved by Sorting
// Time Complexity :- O(m * n * log(n))
// Space Complexity :- O(m * n)

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        int maxArea = 0;
        
        for (int row = 0; row < m; row++) 
        {
            for (int col = 0; col < n; col++) 
            {
                if (matrix[row][col] != 0 && row > 0) 
                {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }
            
            vector<int> currRow = matrix[row];

            sort(currRow.begin(), currRow.end(), greater());

            for (int i = 0; i < n; i++) 
            {
                maxArea = max(maxArea, currRow[i] * (i + 1));
            }
        }
        
        return maxArea;
    }
};



// Solved by Sorting (Space Optimized)
// Time Complexity :- O(m * n * log(n))
// Space Complexity :- O(n)

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        int maxArea = 0;

        vector<int> prev(n, 0);
        
        for (int row = 0; row < m; row++) 
        {
            vector<int> curr = matrix[row];

            for (int col = 0; col < n; col++) 
            {
                if (curr[col] != 0) 
                {
                    curr[col] += prev[col];
                }
            }
            
            vector<int> sorted = curr;

            sort(sorted.begin(), sorted.end(), greater());

            for (int i = 0; i < n; i++) 
            {
                maxArea = max(maxArea, sorted[i] * (i + 1));
            }

            prev = curr;
        }
        
        return maxArea;
    }
};



