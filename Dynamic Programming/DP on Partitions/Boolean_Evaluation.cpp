//Problem Link :- https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650

//Solved by Memoization Method

#include <bits/stdc++.h> 
#define ll long long

int MOD = 1e9 + 7;

ll func (int i, int j, int isTrue, vector <vector <vector<ll>>> &dp, string &exp)
{
    if (i > j)
        return 0;
    
    if (i == j)
    {
        if (isTrue)
            return (exp[i] == 'T');
        
        else
            return (exp[i] == 'F');
    }
    
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    
    ll ways = 0;
    
    for (int index = i + 1; index <= j - 1; index += 2)
    {
        ll LT = func (i, index - 1, 1, dp, exp);
        ll LF = func (i, index - 1, 0, dp, exp);
        ll RT = func (index + 1, j, 1, dp, exp);
        ll RF = func (index + 1, j, 0, dp, exp);
        
        if (exp[index] == '&')
        {
            if (isTrue)
                ways += ((LT) * (RT)) % MOD;
            
            else
                ways += ((LF) * (RF) + (LT) * (RF) + (LF) * (RT)) % MOD;
        }
        
        else if (exp[index] == '|')
        {
            if (isTrue)
                ways += ((LT) * (RF) + (LF) * (RT) + (LT) * (RT)) % MOD;
            
            else
                ways += ((LF) * (RF)) % MOD;
        }
        
        else if (exp[index] == '^')
        {
            if (isTrue)
                ways += ((LT) * (RF) + (LF) * (RT)) % MOD;
            
            else
                ways += ((LF) * (RF) + (LT) * (RT)) % MOD;
        }
        
        ways %= MOD;
    }
    
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
    
    int n = exp.size();
    vector <vector <vector<ll>>> dp (n, vector<vector <ll>> (n, vector <ll> (2, -1)));
    
    return func (0, n - 1, 1, dp, exp);
}


//Solved by Tabulation Method

#include <bits/stdc++.h> 
#define ll long long

int MOD = 1e9 + 7;

int evaluateExp(string & exp) {
    
    int n = exp.size();
    vector <vector <vector<ll>>> dp (n, vector<vector <ll>> (n, vector <ll> (2, 0)));
    
    for (int i = 0; i < n; i++)
    {
        dp[i][i][0] = (exp[i] == 'F');
        dp[i][i][1] = (exp[i] == 'T');
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)      // since i < j and i == j are base cases
        {
            for (int isTrue = 0; isTrue <= 1; isTrue++)
            {
                ll ways = 0;

                for (int index = i + 1; index <= j - 1; index += 2)
                {
                    ll LT = dp[i][index - 1][1];
                    ll LF = dp[i][index - 1][0];
                    ll RT = dp[index + 1][j][1];
                    ll RF = dp[index + 1][j][0];

                    if (exp[index] == '&')
                    {
                        if (isTrue)
                            ways += ((LT) * (RT)) % MOD;

                        else
                            ways += ((LF) * (RF) + (LT) * (RF) + (LF) * (RT)) % MOD;
                    }

                    else if (exp[index] == '|')
                    {
                        if (isTrue)
                            ways += ((LT) * (RF) + (LF) * (RT) + (LT) * (RT)) % MOD;

                        else
                            ways += ((LF) * (RF)) % MOD;
                    }

                    else if (exp[index] == '^')
                    {
                        if (isTrue)
                            ways += ((LT) * (RF) + (LF) * (RT)) % MOD;

                        else
                            ways += ((LF) * (RF) + (LT) * (RT)) % MOD;
                    }

                    ways %= MOD;
                }

                dp[i][j][isTrue] = ways;
            }
        }
    }
    
    return dp[0][n - 1][1];
}