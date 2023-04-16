// Problem Link :- https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

// Time Complexity :- O((n + m)*k)
// Space Complexity :- O(m*k)

// Solved by Memoization Method

class Solution {
public:

    int MOD = 1e9 + 7;

    long long func (int i, int j, vector<vector<int>> &freq, vector<vector<long long>> &dp, string &target)
    {
        if (j == 0)
            return (i == 0);

        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = func(i, j - 1, freq, dp, target);

        if (i > 0)
            dp[i][j] += freq[j - 1][target[i - 1] - 'a'] * func(i - 1, j - 1, freq, dp, target);

        dp[i][j] %= MOD;
        
        return dp[i][j];
    }

    int numWays(vector<string>& words, string target) {
        
        int m = target.size(), n = words.size(), k = words[0].size();

        vector<vector<int>> freq(k, vector<int> (26, 0));
        vector<vector<long long>> dp(m + 1, vector<long long> (k + 1, -1));

        for (int col = 0; col < k; col++)
        {
            for (auto &it : words)
            {
                freq[col][it[col] - 'a']++;
            }
        }

        return func (m, k, freq, dp, target);
    }
};


// Time Complexity :- O((n + m)*k)
// Space Complexity :- O(m*k)

// Solved by Tabulation Method

class Solution {
public:

    int MOD = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        
        int m = target.size(), n = words.size(), k = words[0].size();

        vector<vector<int>> freq(k, vector<int> (26, 0));
        vector<vector<long long>> dp(m + 1, vector<long long> (k + 1, 0));

        dp[0][0] = 1;

        for (int col = 0; col < k; col++)
        {
            for (auto &it : words)
            {
                freq[col][it[col] - 'a']++;
            }
        }

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = (i == 0);
                    continue;
                }

                dp[i][j] = dp[i][j - 1];

                if (i > 0)
                    dp[i][j] += freq[j - 1][target[i - 1] - 'a'] * dp[i - 1][j - 1];
                
                dp[i][j] %= MOD;
            }
        }

        return dp[m][k];
    }
};


// Time Complexity :- O((n + m)*k)
// Space Complexity :- O(m)

// Solved by Tabulation Method (Space Optimized)

class Solution {
public:

    int MOD = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        
        int m = target.size(), n = words.size(), k = words[0].size();

        vector<vector<int>> freq(k, vector<int> (26, 0));
        vector<long long> dp(k + 1, 0);

        dp[0] = 1;

        for (int col = 0; col < k; col++)
        {
            for (auto &it : words)
            {
                freq[col][it[col] - 'a']++;
            }
        }

        for (int i = 0; i <= m; i++)
        {
            vector<long long> temp(k + 1, 0);

            for (int j = 0; j <= k; j++)
            {
                if (j == 0)
                {
                    temp[j] = (i == 0);
                    continue;
                }

                temp[j] = temp[j - 1];

                if (i > 0)
                    temp[j] += freq[j - 1][target[i - 1] - 'a'] * dp[j - 1];
                
                temp[j] %= MOD;
            }

            dp = temp;
        }

        return dp[k];
    }
};

class Solution {
public:

    int MOD = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        
        int m = target.size(), n = words.size(), k = words[0].size();

        vector<vector<int>> freq(k, vector<int> (26, 0));
        vector<long long> dp(m + 1, 0);

        dp[0] = 1;

        for (int col = 0; col < k; col++)
        {
            for (auto &it : words)
            {
                freq[col][it[col] - 'a']++;
            }
        }

        for (int i = 0; i < k; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                dp[j + 1] += dp[j] * freq[i][target[j] - 'a']; 
                dp[j + 1] %= MOD;
            }
        }

        return dp[m];
    }
};
