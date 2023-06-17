// Problem Link :- https://leetcode.com/problems/make-array-strictly-increasing/

// Solved using map
// Time Complexity :- O(n * m * logm)       n = arr1.size(), m = arr2.size()
// Space Complexity :- O(m)

class Solution {
public:

    int solve (int i, int prev, int n, int m, map<pair<int, int>, int> &dp, vector<int>& arr1, vector<int>& arr2)
    {
        if (i == n)
            return 0;

        if (dp.find({i, prev}) != dp.end())
            return dp[{i, prev}];

        int cost = 1e9;

        if (arr1[i] > prev)
            cost = 0 + solve (i + 1, arr1[i], n, m, dp, arr1, arr2);

        int index = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if (index < m)
        {
            cost = min (cost, 1 + solve (i + 1, arr2[index], n, m, dp, arr1, arr2));
        }

        return dp[{i, prev}] = cost;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort (arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());

        int n = arr1.size(), m = arr2.size(), ops = 0;

        map<pair<int, int>, int> dp;

        int ans = solve (0, -1, n, m, dp, arr1, arr2);

        return (ans >= 1e9) ? -1 : ans;
    }
};



// Solved by Memoization Method
// Time Complexity :- O(n * m * logm)       n = arr1.size(), m = arr2.size()
// Space Complexity :- O(n * m)

class Solution {
public:

    int solve (int i, int last, int n, int m, vector<vector<int>> &dp, vector<int>& arr1, vector<int>& arr2)
    {
        if (i >= n)
            return 0;

        if (dp[i][last] != -1)
            return dp[i][last];

        int change = 1e9, notChange = 1e9;
        int prev;

        if (last == 0)
            prev = arr1[i - 1];

        else
            prev = arr2[last - 1];

        if (arr1[i] > prev)
            notChange = 0 + solve (i + 1, 0, n, m, dp, arr1, arr2);

        int index = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        if (index < m)
        {
            change = 1 + solve (i + 1, index + 1, n, m, dp, arr1, arr2);
        }

        return dp[i][last] = min(change, notChange);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort (arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());

        int n = arr1.size(), m = arr2.size(), ops = 0;

        vector<vector<int>> dp (n, vector<int> (m + 1, -1));

        int ans = min(solve (1, 0, n, m, dp, arr1, arr2), 1 + solve (1, 1, n, m, dp, arr1, arr2));

        return (ans >= 1e9) ? -1 : ans;
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * m * logm)       n = arr1.size(), m = arr2.size()
// Space Complexity :- O(n * m)

class Solution {
public:

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort (arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());

        int n = arr1.size(), m = arr2.size();

        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 1e9));

        for (int index = n; index >= 1; index--)
        {
            for (int last = 0; last <= m; last++)
            {
                if (index == n)
                {
                    dp[index][last] = 0;
                    continue;
                }

                int prev, notChange = 1e9, change = 1e9;

                if (last == 0)
                    prev = arr1[index - 1];

                else
                    prev = arr2[last - 1];

                if (arr1[index] > prev)
                    notChange = 0 + dp[index + 1][0];

                int it = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

                if (it < m)
                {
                    change = 1 + dp[index + 1][it + 1];
                }

                dp[index][last] = min(change, notChange);
            }
        }

        int ops = min(dp[1][0], 1 + dp[1][1]);

        return (ops >= 1e9) ? -1 : ops;
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * m * logm)       n = arr1.size(), m = arr2.size()
// Space Complexity :- O(m)

class Solution {
public:

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort (arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());

        int n = arr1.size(), m = arr2.size();

        vector<int> dp (m + 1, 1e9);

        for (int index = n; index >= 1; index--)
        {
            vector<int> temp (m + 1, 1e9);
            
            for (int last = 0; last <= m; last++)
            {
                if (index == n)
                {
                    temp[last] = 0;
                    continue;
                }

                int prev, notChange = 1e9, change = 1e9;

                if (last == 0)
                    prev = arr1[index - 1];

                else
                    prev = arr2[last - 1];

                if (arr1[index] > prev)
                    notChange = 0 + dp[0];

                int it = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

                if (it < m)
                {
                    change = 1 + dp[it + 1];
                }

                temp[last] = min(change, notChange);
            }

            dp = temp;
        }

        int ops = min(dp[0], 1 + dp[1]);

        return (ops >= 1e9) ? -1 : ops;
    }
};