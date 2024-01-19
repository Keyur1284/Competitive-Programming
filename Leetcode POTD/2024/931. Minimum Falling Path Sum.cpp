// Problem Link :- https://leetcode.com/problems/minimum-falling-path-sum/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    vector<vector<int>> moves = {{1, -1}, {1, 0}, {1, 1}};

    bool isValid (int x, int y, int n)
    {
        return (x >= 0 && y >= 0 && x < n && y < n);
    }

    int DFS (int x, int y, int n, vector<vector<int>> &minSum, vector<vector<int>> &matrix)
    {
        if (x == n - 1)
            return matrix[x][y];

        if (minSum[x][y] != 1e9)
            return minSum[x][y];

        int sum = matrix[x][y];
        int ans = 1e9;

        for (auto &it : moves)
        {
            int newx = x + it[0], newy = y + it[1];

            if (isValid(newx, newy, n))
                ans = min(ans, DFS (newx, newy, n, minSum, matrix));
        }
        
        return minSum[x][y] = sum + ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>> minSum(n, vector<int> (n, 1e9));
        int mini = 1e9;

        for (int i = 0; i < n; i++)
        {
            int ans = DFS (0, i, n, minSum, matrix);
            mini = min(mini, ans);
        }

        return mini;
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    vector<vector<int>> moves = {{1, -1}, {1, 0}, {1, 1}};

    bool isValid (int x, int y, int n)
    {
        return (x >= 0 && y >= 0 && x < n && y < n);
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>> minSum(n, vector<int> (n, 1e9));

        for (int row = n - 1; row >= 0; row--)
        {
            for (int col = 0; col < n; col++)
            {
                if (row == n - 1)
                {
                    minSum[row][col] = matrix[row][col];
                    continue;
                }
                
                int sum = matrix[row][col];
                int ans = 1e9;

                for (auto &it : moves)
                {
                    int newx = row + it[0], newy = col + it[1];

                    if (isValid(newx, newy, n))
                        ans = min(ans, minSum[newx][newy]);
                }

                minSum[row][col] = sum + ans;
            }
        }

        int mini = *min_element(minSum[0].begin(), minSum[0].end());

        return mini;
    }
};



// Solved by changing the original matrix
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        for (int row = 1; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                matrix[row][col] += min({matrix[row - 1][max(0, col - 1)], matrix[row - 1][col], matrix[row - 1][min(col + 1, n - 1)]});
            }
        }

        int minSum = *min_element(matrix[n - 1].begin(), matrix[n - 1].end());
        return minSum;
    }
};