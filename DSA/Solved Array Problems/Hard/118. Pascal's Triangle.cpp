// Problem Link :- https://leetcode.com/problems/pascals-triangle/

// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++)
        {
            int size = i + 1;
            vector<int> temp(size, 1);

            for (int j = 1; j < (size + 1)/2; j++)
            {
                temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                temp[i - j] = temp[j];
            }

            ans.emplace_back(temp);
        }

        return ans;
    }
};


class Solution {
public:

    vector<int> generateRow (int row)
    {
        long long ans = 1;
        vector<int> temp;
        temp.emplace_back(1);

        for (int col = 1; col < row; col++)
        {
            ans *= (row - col);
            ans /= col;
            
            temp.emplace_back(ans);
        }

        return temp;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for (int i = 1; i <= numRows; i++)
        {
            vector<int> row = generateRow(i);
            ans.emplace_back(row);
        }

        return ans;
    }
};
