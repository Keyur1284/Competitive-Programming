// Problem Link :- https://leetcode.com/problems/string-compression-ii/

// Solved by Memoization Method (4 States)
// Time Complexity :- O(n * k * 26 * n)
// Space Complexity :- O(n * k * 26 * n)

int dp[110][110][27][110];

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {

        int n = s.length();

        for (int index = 0; index < n; index++)
        {
            for (int del = 0; del <= k; del++)
            {
                for (int prevChar = 0; prevChar <= 26; prevChar++)
                {
                    for (int prevCount = 0; prevCount <= n; prevCount++)
                        dp[index][del][prevChar][prevCount] = -1;

                }
            }
        }

        auto solve = [&](auto self, int index, int k, int prevChar, int prevCount)
        {
            if (n - index <= k)
                return 0;

            if (index == n)
                return 0;

            if (dp[index][k][prevChar][prevCount] != -1)
                return dp[index][k][prevChar][prevCount];

            int remove = 1e8, notRemove = 1e8;

            if (k > 0)
                remove = self(self, index + 1, k - 1, prevChar, prevCount);

            int newChar = (prevCount == 1) || (prevCount == 9) || (prevCount == 99);

            if (s[index] - 'a' == prevChar)
                notRemove = self(self, index + 1, k, prevChar, prevCount + 1) + newChar;

            else
                notRemove = self(self, index + 1, k, s[index] - 'a', 1) + 1;

            return dp[index][k][prevChar][prevCount] = min(remove, notRemove);
        };

        return solve(solve, 0, k, 26, 0);
    }
};



// Solved by Memoization Method (2 States)
// Time Complexity :- O(n^2 * k)
// Space Complexity :- O(n * k)

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {

        int n = s.length();
        vector<vector<int>> dp (n, vector<int> (k + 1, -1));

        auto getChars = [&](int count)
        {
            return (count > 99 ? 3 : (count > 9) ? 2 : (count > 1) ? 1 : 0);
        };

        auto solve = [&](auto self, int index, int k)
        {
            if (n - index <= k)
                return 0;

            if (index == n)
                return 0;

            if (dp[index][k] != -1)
                return dp[index][k];

            int remove = 1e8, notRemove = 1e8;

            if (k > 0)
                remove = self(self, index + 1, k - 1);

            int count = 1, del = k;

            for (int pos = index + 1; pos <= n && del > -1; pos++)
            {
                int newChars = getChars(count);
                int oper = 1 + newChars + self(self, pos, del);
                notRemove = min(notRemove, oper);

                if (pos < n && s[pos] == s[index])
                    count++;

                else
                    del--;
            }

            return dp[index][k] = min(remove, notRemove);
        };

        return solve(solve, 0, k);
    }
};



// Solved by Tabulation Method (2 States)
// Time Complexity :- O(n^2 * k)
// Space Complexity :- O(n * k)

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {

        int n = s.length();
        vector<vector<int>> dp (n + 1, vector<int> (k + 1, 1e8));

        auto getChars = [&](int count)
        {
            return (count > 99 ? 3 : (count > 9) ? 2 : (count > 1) ? 1 : 0);
        };

        for (int index = n; index >= 0; index--)
        {
            for (int del = 0; del <= k; del++)
            {
                if (n - index <= del)
                {
                    dp[index][del] = 0;
                    continue;
                }

                if (index == n)
                {
                    dp[index][del] = 0;
                    continue;
                }

                int remove = 1e8, notRemove = 1e8;

                if (del > 0)
                    remove = dp[index + 1][del - 1];

                int count = 1, dels = del;

                for (int pos = index + 1; pos <= n && dels > -1; pos++)
                {
                    int newChars = getChars(count);
                    int oper = 1 + newChars + dp[pos][dels];
                    notRemove = min(notRemove, oper);

                    if (pos < n && s[pos] == s[index])
                        count++;

                    else
                        dels--;
                }

                dp[index][del] = min(remove, notRemove);
            }
        }

        return dp[0][k];
    }
};