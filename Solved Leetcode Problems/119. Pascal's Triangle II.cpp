// Problem Link :- https://leetcode.com/problems/pascals-triangle-ii/

// Solved by Maths
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        long long prod = 1;
        vector<int> row (rowIndex + 1, 1);
        rowIndex++;

        for (int col = 1; col < rowIndex; col++)
        {
            prod *= (rowIndex - col);
            prod /= col;
            row[col] = prod;
        }

        return row;
    }
};