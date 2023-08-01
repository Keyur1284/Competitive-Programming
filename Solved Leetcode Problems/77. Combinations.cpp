// Problem Link :- https://leetcode.com/problems/combinations/

// Solved by Backtracking
// Time Complexity :- O(k * nCk)
// Space Complexity :- O(nCk)

class Solution {
public:

    void solve (int start, int n, int k, vector<int> &current, vector<vector<int>> &combinations)
    {
        if (k == 0)
        {
            combinations.emplace_back(current);
            return;
        }

        for (int num = start; num <= n; num++)
        {
            current.emplace_back(num);
            solve (num + 1, n, k - 1, current, combinations);
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<int> current;
        vector<vector<int>> combinations;
        solve (1, n, k, current, combinations); 

        return combinations;
    }
};


// Solved by Bitmasking
// Time Complexity :- O(2^n * n)
// Space Complexity :- O(nCk)

class Solution {
public:

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> combinations;
        
        for (int mask = 0; mask < (1 << n); mask++)
        {
            int bitCount = __builtin_popcount(mask);

            if (bitCount == k)
            {
                vector<int> nums;

                for (int num = 0; num < n; num++)
                {
                    if (mask & (1 << num))
                        nums.emplace_back(num + 1);
                }

                combinations.emplace_back(nums);
            }
        }

        return combinations;
    }
};