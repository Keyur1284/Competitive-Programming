// Problem Link :- https://leetcode.com/problems/minimum-cost-for-tickets/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        int last = days.back();

        vector<int> dp(last + 1, 0);

        unordered_set<int> st;

        for (auto &it : days)
            st.emplace(it);

        for (int i = 1; i <= last; i++)
        {
            if (st.find(i) != st.end())
            {
                int one = dp[max(0, i - 1)] + costs[0];
                int week = dp[max(0, i - 7)] + costs[1];
                int month = dp[max(0, i - 30)] + costs[2];

                dp[i] = min({one, week, month});
            }

            else
                dp[i] = dp[i - 1];
        }

        return dp[last];
    }
};