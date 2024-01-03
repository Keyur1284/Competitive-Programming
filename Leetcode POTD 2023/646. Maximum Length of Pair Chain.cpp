// Problem Link :- https://leetcode.com/problems/maximum-length-of-pair-chain/

// Solved greedily by sorting the pairs according to the second element
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:

    static bool comp (vector<int> &pair1, vector<int> &pair2)
    {
        if (pair1[1] != pair2[1])
            return pair1[1] < pair2[1];

        return pair1[0] < pair2[0];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort (pairs.begin(), pairs.end(), comp);

        int last = pairs[0][1];
        int chain = 1;

        for (int i = 1; i < n; i++)
        {
            if (last < pairs[i][0])
            {
                last = pairs[i][1];
                chain++;
            }
        } 

        return chain;
    }
};



class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort (pairs.begin(), pairs.end());

        int last = pairs[0][1];
        int chain = 1;

        for (int i = 1; i < n; i++)
        {
            if (pairs[i][1] < last) 
            {
                last = pairs[i][1];
            }

            if (last < pairs[i][0])
            {
                last = pairs[i][1];
                chain++;
            }
        } 

        return chain;
    }
};



// Solved by Memoization Method
// Time Complexity :- O(nlogn + n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    int solve (int index, int prev, vector<vector<int>>& dp, vector<vector<int>>& pairs)
    {
        if (index == pairs.size())
            return 0;

        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int notTake = 0 + solve (index + 1, prev, dp, pairs);
        int take = INT_MIN;

        if (prev == -1 || pairs[prev][1] < pairs[index][0])
            take = 1 + solve (index + 1, index, dp, pairs);

        return dp[index][prev + 1] = max(take, notTake);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort (pairs.begin(), pairs.end());
        vector<vector<int>> dp (n, vector<int> (n + 1, -1));

        return solve (0, -1, dp, pairs);
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(nlogn + n^2)
// Space Complexity :- O(n^2)

class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort (pairs.begin(), pairs.end());
        vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = index - 1; prev >= -1; prev--)
            {
                int notTake = dp[index + 1][prev + 1];
                int take = INT_MIN;

                if (prev == -1 || pairs[prev][1] < pairs[index][0])
                    take = 1 + dp[index + 1][index + 1];

                dp[index][prev + 1] = max(take, notTake);
            }
        }
        
        return dp[0][-1 + 1];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(nlogn + n^2)
// Space Complexity :- O(n)

class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();
        sort (pairs.begin(), pairs.end());
        vector<int> dp (n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int prev = index - 1; prev >= -1; prev--)
            {
                int notTake = 0 + dp[prev + 1];
                int take = INT_MIN;

                if (prev == -1 || pairs[prev][1] < pairs[index][0])
                    take = 1 + dp[index + 1];

                dp[prev + 1] = max (take, notTake);
            }
        }
        
        return dp[-1 + 1];
    }
};