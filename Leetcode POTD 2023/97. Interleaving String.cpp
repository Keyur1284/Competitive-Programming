// Problem Link :- https://leetcode.com/problems/interleaving-string/

// Solved by Memoization Method
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    bool solve (int i, string &s1, int len1, int j, string &s2, int len2, int k, string &s3, int len3, vector<vector<int>> &dp)
    {
        if (i == len1 && j == len2 && k == len3)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        if (i < len1 && s1[i] == s3[k])
            ans |= solve (i + 1, s1, len1, j, s2, len2, k + 1, s3, len3, dp);

        if (j < len2 && s2[j] == s3[k])
            ans |= solve (i, s1, len1, j + 1, s2, len2, k + 1, s3, len3, dp);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();

        if (len1 + len2 != len3)
            return false;

        vector<vector<int>> dp (len1 + 1, vector<int> (len2 + 1, -1));

        return solve (0, s1, len1, 0, s2, len2, 0, s3, len3, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * m)
// Space Complexity :- O(n * m)

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();

        if (len1 + len2 != len3)
            return false;

        vector<vector<bool>> dp (len1 + 1, vector<bool> (len2 + 1, false));

        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = true;

                else if (i == 0)
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);

                else if (j == 0)
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);

                else
                    dp[i][j] = ((dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]));
            }
        }

        return dp[len1][len2];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n * m)
// Space Complexity :- O(m)

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();

        if (len1 + len2 != len3)
            return false;

        vector<bool> dp (len2 + 1, false);

        for (int i = 0; i <= len1; i++)
        {
            vector<bool> temp (len2 + 1, false);

            for (int j = 0; j <= len2; j++)
            {
                if (i == 0 && j == 0)
                    temp[j] = true;

                else if (i == 0)
                    temp[j] = (temp[j - 1] && s2[j - 1] == s3[i + j - 1]);

                else if (j == 0)
                    temp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]);

                else
                    temp[j] = ((temp[j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[j] && s1[i - 1] == s3[i + j - 1])); 
            }

            dp = temp;
        }

        return dp[len2];
    }
};