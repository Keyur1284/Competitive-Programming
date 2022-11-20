//First find the length of the longest common subsequence and then the following function should be written inorder to find the required 
//longest common subsequence

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s, string t, vector <vector <int>> &dp) 
{
        
    int n = s.size();
    int m = t.size();

    // vector <vector <int>> dp (n + 1, vector <int> (m + 1, -1));

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

    return dp[n][m];  
}

int main ()
{
    // input
    // abcde
    // bdgek
    
    string s, t, ans = "";

    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    
    vector <vector <int>> dp (n + 1, vector <int> (m + 1, 0));

    int longest = longestCommonSubsequence(s, t, dp);
    int index = longest - 1;

    int i = n, j = m;

    for (int k = 1; k <= longest; k++)
        ans += "$";         //dummy string

    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans[index] = s[i - 1];
            i--;
            j--;
            index--;
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
    
            i--;

        else 
            j--;
    }

    cout << ans << endl;

    return 0;
}