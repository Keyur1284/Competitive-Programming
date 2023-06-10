// Problem Link :- https://leetcode.com/problems/russian-doll-envelopes/

// Similar Approach as the problem Longest Increasing Subsequence (Solved by Binary Search)

// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    static bool comp (vector<int> &env1, vector<int> &env2)
    {
        if (env1[0] != env2[0])
            return env1[0] < env2[0];

        return env1[1] > env2[1];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp;

        dp.emplace_back(envelopes[0][1]);

        for (int i = 1; i < n; i++)
        {
            int height = envelopes[i][1];
            if (height > dp.back())
                dp.emplace_back(height);

            else
            {
                int index = lower_bound (dp.begin(), dp.end(), height) - dp.begin();
                dp[index] = height;
            }
        }

        return (int)dp.size();
    }
};



class Solution {
public:

    static bool comp (vector<int> &env1, vector<int> &env2)
    {
        if (env1[1] != env2[1])
            return env1[1] < env2[1];

        return env1[0] > env2[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp;

        dp.emplace_back(envelopes[0][0]);

        for (int i = 1; i < n; i++)
        {
            int width = envelopes[i][0];
            if (width > dp.back())
                dp.emplace_back(width);

            else
            {
                int index = lower_bound (dp.begin(), dp.end(), width) - dp.begin();
                dp[index] = width;
            }
        }

        return (int)dp.size();
    }
};