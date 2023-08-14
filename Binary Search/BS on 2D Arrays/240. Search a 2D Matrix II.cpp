// Problem Link :- https://leetcode.com/problems/search-a-2d-matrix-ii/

// Solved by Binary Search
// Time Complexity :- O(mlogn)
// Space Complexity :- O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();

        for (auto &row : matrix)
        {
            if (row[0] <= target && target <= row[n - 1])
            {
                int low = 0, high = n - 1, mid;

                while (low <= high)
                {
                    mid = (low + high) >> 1;

                    if (row[mid] == target)
                        return true;

                    if (row[mid] < target)
                        low = mid + 1;

                    else
                        high = mid - 1;
                }
            }
        }

        return false;
    }
};



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();

        for (auto &row : matrix)
        {
            auto it = lower_bound(row.begin(), row.end(), target);

            if (it != row.end() && *it == target)
                return true;
        }

        return false;
    }
};



// Solved by Two Pointer Approach
// Time Complexity :- O(m + n)
// Space Complexity :- O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = n - 1;

        while (row < m && col >= 0)
        {
            if (matrix[row][col] == target)
                return true;

            else if (matrix[row][col] > target)
                col--;

            else if (matrix[row][col] < target)
                row++;
        }

        return false;
    }
};