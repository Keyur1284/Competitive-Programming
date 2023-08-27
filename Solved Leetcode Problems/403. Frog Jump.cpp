// Problem Link :- https://leetcode.com/problems/frog-jump/

// Solved by Memoization Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    bool solve (int index, int k, int n, vector<int> &stones, vector<vector<int>> &dp)
    {
        if (index == n - 1)
            return true;

        if (dp[index][k] != -1)
            return dp[index][k];

        bool ans = false;

        for (int next = k - 1; next <= k + 1; next++)
        {
            if (next > 0)
            {
                int nextIndex = lower_bound(stones.begin() + index, stones.end(), stones[index] + next) - stones.begin();

                if (nextIndex < n && stones[nextIndex] == stones[index] + next)
                    ans |= solve (nextIndex, next, n, stones, dp);
            }
        }

        return dp[index][k] = ans;
    }

    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        if (stones[1] - stones[0] != 1)
            return false;

        return solve (1, 1, n, stones, dp);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int> (n + 1, 0));

        if (stones[1] - stones[0] != 1)
            return false;

        unordered_map<int, int> mark;

        for (int i = 0; i < n; i++) 
        {
            mark[stones[i]] = i;
        }

        dp[1][1] = 1;
        
        for (int index = 1; index < n; index++) 
        {
            for (int prevJump = 1; prevJump <= n; prevJump++) 
            {
                if (dp[index][prevJump]) 
                {
                    if (mark[stones[index] + prevJump]) 
                    {
                        dp[mark[stones[index] + prevJump]][prevJump] = 1;
                    }

                    if (mark[stones[index] + prevJump + 1])
                    {
                        dp[mark[stones[index] + prevJump + 1]][prevJump + 1] = 1;
                    }

                    if (mark[stones[index] + prevJump - 1]) 
                    {
                        dp[mark[stones[index] + prevJump - 1]][prevJump - 1] = 1;
                    }
                }
            }
        }
        
        for (int prevJump = 0; prevJump <= n; prevJump++) 
        {
            if (dp[n - 1][prevJump]) 
                return true;
        }

        return false;
    }
};



// Solved using unordered_map
// Time Complexity :- O(n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        unordered_map<int, unordered_set<int>> mp;
        mp[1] = {1};

        for (int i = 1; i < n; i++)
        {
            for (auto jump : mp[stones[i]])
            {
                mp[stones[i] + jump].emplace(jump);
                mp[stones[i] + jump + 1].emplace(jump + 1);
                mp[stones[i] + jump - 1].emplace(jump - 1);
            }
        }

        return (mp[stones[n - 1]].size() > 0);
    }
};