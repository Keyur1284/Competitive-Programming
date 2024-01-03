// Problem Link :- https://leetcode.com/problems/stone-game-iii/

// Solved by Memoization Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int func (int index, int &n, vector<int> &dp, vector<int>& stoneValue)
    {
        if (index >= n)
            return 0;

        if (dp[index] != INT_MAX)
            return dp[index];

        int sum = 0;
        int ans = INT_MIN;

        for (int k = 1; k <= 3; k++)
        {
            if (index + k - 1 >= n)
                break;

            sum += stoneValue[index + k - 1];
            ans = max(ans, sum - func(index + k, n, dp, stoneValue));
        }

        return dp[index] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<int> dp (n, INT_MAX);

        int alice = func (0, n, dp, stoneValue);

        return (alice > 0) ? "Alice" : (alice == 0) ? "Tie" : "Bob";
    }
};


// Solved by Tabulation Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<int> dp (n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            int ans = INT_MIN, sum = 0;

            for (int k = 1; k <= 3; k++)
            {
                if (index + k - 1 >= n)
                    break;

                sum += stoneValue[index + k - 1];
                ans = max(ans, sum - dp[index + k]);
            }

            dp[index] = ans;
        }

        return (dp[0] > 0) ? "Alice" : (dp[0] == 0) ? "Tie" : "Bob";
    }
};


// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        vector<int> dp (4, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            int ans = INT_MIN, sum = 0;
            
            for (int k = 1; k <= 3; k++)
            {
                if (index + k - 1 >= n)
                    break;

                sum += stoneValue[index + k - 1];
                ans = max(ans, sum - dp[(index + k) % 4]);
            }
            
            dp[index % 4] = ans;
        }

        return (dp[0] > 0) ? "Alice" : (dp[0] == 0) ? "Tie" : "Bob";
    }
};