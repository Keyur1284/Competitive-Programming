// Problem Link :- https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int n = nums.size(), row = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> matrix;

        for (auto &it : nums)
        {
            if (row > 0 && matrix[row - 1].back() != it)
                row = 0;

            if (row >= matrix.size())
                matrix.push_back({});

            matrix[row++].emplace_back(it);
        }

        return matrix;
    }
};



// Solved by keeping track of frequency of each element
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        vector<vector<int>> matrix;

        for (auto &it : nums)
        {
            if (freq[it] >= matrix.size())
                matrix.push_back({});

            matrix[freq[it]].emplace_back(it);
            freq[it]++;
        }

        return matrix;
    }
};