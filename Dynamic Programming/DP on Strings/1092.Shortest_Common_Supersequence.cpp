//Problem Link :- https://leetcode.com/problems/shortest-common-supersequence/


//Solved by Tabulation Method

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        vector <vector <int>> dp (n + 1, vector <int> (m + 1, 0));
        
        for (int i = 0; i<=n; i++)
            dp[i][0] = 0;
        
        for (int j = 0; j<=m; j++)
            dp[0][j] = 0;
        
        for (int i = 1; i<=n; i++)
        {
            for (int j = 1; j<=m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else
                    dp[i][j] = 0 + max (dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        string ans = "";
        int i = n, j = m;
        
        while (i > 0 && j > 0)
        {
            if (s[i - 1] == t[j - 1])
            {
                ans += s[i - 1];
                i--;
                j--;
            }
            
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s[i - 1];
                i--;
            }
            
            else
            {
                ans += t[j - 1];
                j--;
            }
        }
        
        while (i)
        {
            ans += s[i - 1];
            i--;
        }
        
        while (j)
        {
            ans += t[j - 1];
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};