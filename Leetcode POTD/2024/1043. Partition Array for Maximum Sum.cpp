// Problem Link :- https://leetcode.com/problems/partition-array-for-maximum-sum/

// Solved by Memoization Method
// Time Complexity :- O(n * k)
// Space Complexity :- O(n)

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> dp(n, -1);

        function<int(int)> solve = [&](int index) -> int
        {
            if (index == n)
                return 0;

            if (dp[index] != -1)
                return dp[index];

            int maxi = INT_MIN, maxSum = INT_MIN, len = 0;

            for (int j = index; j < min(n, index + k); j++)
            {
                maxi = max(maxi, arr[j]);
                len++;
                int sum = maxi * len + solve(j + 1);
                maxSum = max(maxSum, sum);
            }

            return dp[index] = maxSum;
        };

        return solve(0);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n * k)
// Space Complexity :- O(n)

class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector <int> dp (n + 1, 0);        
        
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



class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            int maxi = INT_MIN, maxSum = INT_MIN, len = 0;

            for (int j = i - 1; j >= max(0, i - k); j--)
            {
                maxi = max(maxi, arr[j]);
                len++;
                int sum = maxi * len + dp[j];
                maxSum = max(maxSum, sum);
            }

            dp[i] = maxSum;
        }

        return dp[n];
    }
};