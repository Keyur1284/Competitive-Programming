// Problem Link :- https://leetcode.com/problems/longest-ideal-subsequence/

// Most Optimized Solution
// Time Complexity :- O(n * k)
// Space Complexity :- O(26)

class Solution {
public:

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<int> dp(26, 0);

        int maxLen = 0;

        for (auto &ch : s)
        {
            int currLen = 0;

            for (int prev = max(ch - 'a' - k, 0); prev <= min(ch - 'a' + k, 25); prev++)
                currLen = max(currLen, 1 + dp[prev]);

            dp[ch - 'a'] = currLen;
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};



// Solved by Memoization Method
// Time Complexity :- O(n * 26)
// Space Complexity :- O(n * 26)

class Solution {
public:

    int solve (int index, int prev, int &n, int &k, string &s, vector<vector<int>> &dp)
    {
        if (index == n)
            return 0;

        if (dp[index][prev] != -1)
            return dp[index][prev];

        int notTake = solve(index + 1, prev, n, k, s, dp);
        int take = 0;

        if (prev == 26 || abs(s[index] - 'a' - prev) <= k)
            take = 1 + solve(index + 1, s[index] - 'a', n, k, s, dp);

        return dp[index][prev] = max(take, notTake);
    }

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (27, -1));

        return solve(0, 26, n, k, s, dp);
    }
};



class Solution {
public:

    int solve (int index, int prev, int &n, int &k, string &s, vector<vector<int>> &dp)
    {
        if (index == n)
            return 0;

        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int notTake = solve(index + 1, prev, n, k, s, dp);
        int take = 0;

        if (prev == -1 || abs(s[index] - 'a' - prev) <= k)
            take = 1 + solve(index + 1, s[index] - 'a', n, k, s, dp);

        return dp[index][prev + 1] = max(take, notTake);
    }

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (27, -1));

        return solve(0, -1, n, k, s, dp);
    }
};



class Solution {
public:

    int solve (int index, int prev, int &k, string &s, vector<vector<int>> &dp)
    {
        if (index < 0)
            return 0;

        if (dp[index][prev] != -1)
            return dp[index][prev];

        int notTake = solve(index - 1, prev, k, s, dp);
        int take = 0;

        if (prev == 26 || abs(s[index] - 'a' - prev) <= k)
            take = 1 + solve(index - 1, s[index] - 'a', k, s, dp);

        return dp[index][prev] = max(take, notTake);
    }

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (27, -1));

        return solve(n - 1, 26, k, s, dp);
    }
};



class Solution {
public:

    int solve (int index, int prev, int &k, string &s, vector<vector<int>> &dp)
    {
        if (index < 0)
            return 0;

        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int notTake = solve(index - 1, prev, k, s, dp);
        int take = 0;

        if (prev == -1 || abs(s[index] - 'a' - prev) <= k)
            take = 1 + solve(index - 1, s[index] - 'a', k, s, dp);

        return dp[index][prev + 1] = max(take, notTake);
    }

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (27, -1));

        return solve(n - 1, -1, k, s, dp);
    }
};


// Solved by Tabulation Method
// Time Complexity :- O(n * 26)
// Space Complexity :- O(n * 26)

class Solution {
public:

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (27, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = 26; prev >= 0; prev--)
            {
                int notTake = 0 + dp[index + 1][prev];
                int take = 0;

                if (prev == 26 || abs(s[index] - 'a' - prev) <= k)
                    take = 1 + dp[index + 1][s[index] - 'a'];

                dp[index][prev] = max(take, notTake);
            }
        }

        return dp[0][26];
    }
};



class Solution {
public:

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (27, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = -1; prev <= 25; prev++)
            {
                int notTake = 0 + dp[index + 1][prev + 1];
                int take = 0;

                if (prev == -1 || abs(s[index] - 'a' - prev) <= k)
                    take = 1 + dp[index + 1][s[index] - 'a' + 1];

                dp[index][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][-1 + 1];
    }
};



class Solution {
public:

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (27, 0));

        for (int index = 1; index <= n; index++)
        {
            for (int prev = 26; prev >= 0; prev--)
            {
                int notTake = dp[index - 1][prev];
                int take = 0;

                if (prev == 26 || abs(s[index - 1] - 'a' - prev) <= k)
                    take = 1 + dp[index - 1][s[index - 1] - 'a'];

                dp[index][prev] = max(take, notTake);
            }
        }

        return dp[n][26];
    }
};



class Solution {
public:

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int> (27, 0));

        for (int index = 1; index <= n; index++)
        {
            for (int prev = -1; prev <= 25; prev++)
            {
                int notTake = dp[index - 1][prev + 1];
                int take = 0;

                if (prev == -1 || abs(s[index - 1] - 'a' - prev) <= k)
                    take = 1 + dp[index - 1][s[index - 1] - 'a' + 1];

                dp[index][prev + 1] = max(take, notTake);
            }
        }

        return dp[n][-1 + 1];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * 26)
// Space Complexity :- O(26)

class Solution {
public:

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<int> dp(27, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            vector<int> temp(27, 0);

            for (int prev = 26; prev >= 0; prev--)
            {
                int notTake = 0 + dp[prev];
                int take = 0;

                if (prev == 26 || abs(s[index] - 'a' - prev) <= k)
                    take = 1 + dp[s[index] - 'a'];

                temp[prev] = max(take, notTake);
            }

            dp = temp;
        }

        return dp[26];
    }
};



class Solution {
public:

    int longestIdealString(string s, int k) {
        
        int n = s.length();
        vector<int> dp(27, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            vector<int> temp(27, 0);

            for (int prev = -1; prev <= 25; prev++)
            {
                int notTake = 0 + dp[prev + 1];
                int take = 0;

                if (prev == -1 || abs(s[index] - 'a' - prev) <= k)
                    take = 1 + dp[s[index] - 'a' + 1];

                temp[prev + 1] = max(take, notTake);
            }

            dp = temp;
        }

        return dp[-1 + 1];
    }
};