// Problem Link :- https://leetcode.com/problems/lucky-numbers-in-a-matrix/

// Solved by storing rowMin and colMax
// Time Complexity :- O(n * m)
// Space Complexity :- O(n + m)

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rowMin(m, INT_MAX), colMax(n, INT_MIN);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        vector<int> lucky;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rowMin[i] == colMax[j])
                    lucky.emplace_back(rowMin[i]);
            }
        }

        return lucky;
    }
};



// Solved without using extra space
// Time Complexity :- O(n * m)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        int rowMinMax = INT_MIN;
        
        for (int i = 0; i < m; i++) 
        {
            int rowMin = *min_element(matrix[i].begin(), matrix[i].end());
            rowMinMax = max(rowMinMax, rowMin);
        }
        
        int colMaxMin = INT_MAX;
        
        for (int i = 0; i < n; i++) {

            int colMax = INT_MIN;

            for (int j = 0; j < m; j++)
                colMax = max(colMax, matrix[j][i]);
            
            colMaxMin = min(colMaxMin, colMax);
        }
        
        return rowMinMax == colMaxMin ? vector<int>{rowMinMax} : vector<int>{};
    }
};