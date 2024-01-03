// Problem Link :- https://leetcode.com/problems/smallest-sufficient-team/

// Solved DP + Bit-masking
// Time COmplexity :- O(n * (2 ^ m))    n -> people.size(), m -> req_skills.size()
// Space Complexity :- O(n * (2 ^ m))

class Solution {
public:

    int solve (int index, int mask, int n, int m, unordered_map<string, int> &mp, vector<vector<int>> &dp, vector<vector<bool>> &taken, vector<int> &peeps)
    {
        if (mask == (1 << m) - 1)
            return 0;

        if (index == n)
        {
            return 1e9;
        }

        if (dp[index][mask] != -1)  
            return dp[index][mask];

        int notTake = solve (index + 1, mask, n, m, mp, dp, taken, peeps);
        int take = 1 + solve (index + 1, mask | peeps[index], n, m, mp, dp, taken, peeps);

        if (take < notTake)
            taken[index][mask] = true;

        return dp[index][mask] = min(take, notTake);
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        
        unordered_map<string, int> mp;
        vector<int> peeps;
        int val = 1;

        for (auto &it : req_skills)
        {
            mp[it] = val;
            val <<= 1;
        }

        for (auto &skills : people)
        {
            int mask = 0;

            for (auto &it : skills)
            {
                mask |= mp[it];
            }

            peeps.emplace_back(mask);
        }

        int n = people.size(), m = req_skills.size(), mask = 0;

        vector<vector<int>> dp(n, vector<int> ((1 << m), -1));
        vector<vector<bool>> taken(n, vector<bool> ((1 << m),  false));
        
        solve (0, mask, n, m, mp, dp, taken, peeps);

        mask = 0;

        vector<int> team;

        for (int per = 0; per < n; per++)
        {
            if (taken[per][mask])
            {
                mask |= peeps[per];
                team.emplace_back(per);
            }

            if (mask == ((1 << m) - 1))
                break;
        }

        return team;
    }
};