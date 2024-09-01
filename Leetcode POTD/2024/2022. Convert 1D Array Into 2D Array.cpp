// Problem Link :- https://leetcode.com/problems/convert-1d-array-into-2d-array/

// Solved by Simulation
// Time Complexity :- O(m * n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        if (m * n != original.size())
            return vector<vector<int>>(0, vector<int>(0));

        vector<vector<int>> resultArray(m, vector<int>(n));

        for (int i = 0, index = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
                resultArray[i][j] = original[index++];
        }

        return resultArray;
    }
};



class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        if (m * n != original.size())
            return vector<vector<int>>(0, vector<int>(0));

        vector<vector<int>> resultArray(m, vector<int>(n));

        for (int i = 0; i < original.size(); i++)
            resultArray[i / n][i % n] = original[i];

        return resultArray;
    }
};