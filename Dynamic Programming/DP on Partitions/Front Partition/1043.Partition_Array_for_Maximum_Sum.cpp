//Problem Link :- https://leetcode.com/problems/partition-array-for-maximum-sum/

//Solved by Memoization Method

class Solution {
public:
    
    int func (int i, int n, int k, vector <int> &dp, vector <int> &arr)
    {
        if (i == n)
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        int maxi = INT_MIN, len = 0, maxAns = INT_MIN;
        
        for (int j = i; j < min(n, i + k); j++)
        {
            len++;
            maxi = max (maxi, arr[j]);
            
            int sum = maxi * len + func (j + 1, n, k, dp, arr);
            
            maxAns = max (sum, maxAns);
        }
        
        return dp[i] = maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector <int> dp (n, -1);
        
        return func (0, n, k, dp, arr);
        
    }
};


//Solved by Tabulation Method

class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector <int> dp (n + 1, 0);
        dp[n] = 0;      //  Base case (Can be omitted)
        
        
        for (int i = n - 1; i >= 0; i--)
        {
            int maxi = INT_MIN, len = 0, maxAns = INT_MIN;
        
            for (int j = i; j < min(n, i + k); j++)
            {
                len++;
                maxi = max (maxi, arr[j]);

                int sum = maxi * len + dp[j + 1];

                maxAns = max (sum, maxAns);
            }

            dp[i] = maxAns;
        }
        
        return dp[0];
        
    }
}; 