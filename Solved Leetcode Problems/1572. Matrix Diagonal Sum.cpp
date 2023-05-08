// Problem Link :- https://leetcode.com/problems/matrix-diagonal-sum/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int sum = 0;

        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            sum += mat[i][i];

            if (i != j)
                sum += mat[i][j];
        } 

        return sum;
    }
};


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int sum = 0;

        for (int i = 0, j = n - 1; i < n; i++, j--)
        {
            sum += mat[i][i] + mat[i][j];
        } 

        if (n % 2)
            sum -= mat[n/2][n/2];

        return sum;
    }
};