// Problem Link :- https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/

// Solved by Storing Current Row and Col Sum
// Time Complexity :- O(n * m)
// Space Complexity :- O(n + m)

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> mat(n, vector<int> (m));
        vector<int> currRowSum(n, 0), currColSum(m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[i][j] = min(rowSum[i] - currRowSum[i], colSum[j] - currColSum[j]);
                currRowSum[i] += mat[i][j];
                currColSum[j] += mat[i][j];
            }
        }

        return mat;
    }
};



// Solved using priority_queue
// Time Complexity :- O(n * log(n) + m * log(m))
// Space Complexity :- O(n + m)

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> mat(n, vector<int> (m));
        priority_queue<pair<int, int>> pqRow, pqCol;

        for (int i = 0; i < n; i++)
            pqRow.emplace(rowSum[i], i);

        for (int j = 0; j < m; j++)
            pqCol.emplace(colSum[j], j);

        while (!pqRow.empty() && !pqCol.empty())
        {
            auto [rowSum, i] = pqRow.top();
            auto [colSum, j] = pqCol.top();

            pqRow.pop();
            pqCol.pop();

            mat[i][j] = min(rowSum, colSum);

            rowSum -= mat[i][j];
            colSum -= mat[i][j];

            if (rowSum > 0)
                pqRow.emplace(rowSum, i);

            if (colSum > 0)
                pqCol.emplace(colSum, j);
        }

        return mat;
    }
};



// Solved by Space Optimization
// Time Complexity :- O(n * m)
// Space Complexity :- O(1)

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> mat(n, vector<int> (m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= mat[i][j];
                colSum[j] -= mat[i][j];
            }
        }

        return mat;
    }
};



// Time and Space Optimized Solution
// Time Complexity :- O(n * m)
// Space Complexity :- O(1)

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> mat(n, vector<int> (m));
        int row = 0, col = 0;

        while (row < n && col < m)
        {
            mat[row][col] = min(rowSum[row], colSum[col]);
            rowSum[row] -= mat[row][col];
            colSum[col] -= mat[row][col];

            (rowSum[row] == 0) ? row++ : col++;
        }

        return mat;
    }
};