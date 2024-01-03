// Problem Link :- https://leetcode.com/problems/search-a-2d-matrix/

// Solved by Binary Search
// Time Complexity :- O(log(n*m))
// Space Complexity :- O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (matrix[mid/n][mid % n] == target)
                return true;

            if (matrix[mid/n][mid % n] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return false;
    }
};



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == target)
                        return true;
                }
            }
        }

        return false;
    }
};