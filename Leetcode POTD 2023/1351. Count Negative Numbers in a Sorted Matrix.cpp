// Problem Link :- https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

// Solved by Brute Force Approach
// Time Complexity : O(n * m)
// Space Complexity : O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int neg = 0;

        for (auto &vec : grid)
        {
            for (auto &it : vec)
            {
                neg += (it < 0);
            }
        }

        return neg;
    }
};



// Solved by Binary Search on col for each row
// Time Complexity : O(m * log(n))
// Space Complexity : O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int neg = 0;
        int m = grid.size(), n = grid[0].size();

        for (int row = 0; row < m; row++)
        {
            int low = 0, high = n - 1, mid, ans = n;

            while (low <= high)
            {
                mid = (low + high) >> 1;

                if (grid[row][mid] < 0)
                {
                    ans = mid;
                    high = mid - 1;
                }

                else
                    low = mid + 1;
            }

            neg += n - ans;
        }

        return neg;
    }
};



// Solved by using inbuilt upper_bound function
// Time Complexity : O(m * log(n))
// Space Complexity : O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int neg = 0;
        int m = grid.size(), n = grid[0].size();

        for (int row = 0; row < m; row++)
        {
            int index = upper_bound (grid[row].begin(), grid[row].end(), 0, greater<int>()) - grid[row].begin();

            neg += n - index;
        }

        return neg;
    }
};



// Solved by Linear Traversal
// Time Complexity : O(n + m)
// Space Complexity : O(1)

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int neg = 0;
        int m = grid.size(), n = grid[0].size(), currNegIndex = n  - 1;

        for (int row = 0; row < m; row++)
        {
            while (currNegIndex >= 0 && grid[row][currNegIndex] < 0)
                currNegIndex--;

            neg += n - (currNegIndex + 1);
        }

        return neg;
    }
};