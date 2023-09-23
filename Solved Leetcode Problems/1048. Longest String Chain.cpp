// Problem Link: https://leetcode.com/problems/longest-string-chain/

// Solved by DP + Sorting
// Time Complexity :- O(nlogn + n^2)
// Space Complexity :- O(n)

bool comp (string &s, string &t)
{
    return s.size() < t.size();
}

class Solution {
public:
    
    bool check (string &s, string &t)
    {
        if (s.size() != t.size() + 1)
            return false;
        
        int i = 0, j = 0;
        
        while (i < s.size())
        {
            if (s[i] == t[j])
                i++, j++;
            
            else
                i++;
        }
        
        if (i == s.size() && j == t.size())
            return true;
        
        else
            return false;
    }
    
    int longestStrChain(vector<string>& words) {
        
        int n = words.size(), maxi = INT_MIN;
        sort(words.begin(), words.end(), comp);
        
        vector <int> dp(n, 1);
        
        for (int index = 0; index < n; index++)
        {
            for (int prev = 0; prev < index; prev++)
            {
                if (check(words[index], words[prev]) && 1 + dp[prev] > dp[index])   
                    dp[index] = 1 + dp[prev];
                
            }
            
             maxi = max (maxi, dp[index]);
        }
        
        return maxi;
    }
};