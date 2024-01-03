// Problem Link :- https://leetcode.com/problems/binary-trees-with-factors/

// Solved using unordered_map and unordered_set
// Time Complexity :- O(nlogn + n * sqrt(max(arr)))
// Space Complexity :- O(n)

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        int MOD = 1e9 + 7;

        sort(arr.begin(), arr.end());
        unordered_set<int> st(arr.begin(), arr.end());
        unordered_map<int, long long> dp;

        for (auto &it : arr)
            dp[it] = 1;

        for (auto &it1 : arr)
        {
            for (auto &it2 : arr)
            {
                if (it2 > sqrt(it1))
                    break;

                if (it1 % it2 == 0 && st.count(it1 / it2))
                {
                    long long comb = 1LL * dp[it2] * dp[it1 / it2];

                    if (it1 / it2 == it2)
                        dp[it1] += comb;

                    else
                        dp[it1] += 2LL * comb;

                    dp[it1] %= MOD;
                }
            }
        }

        int ways = 0;

        for (auto &it : dp)
        {
            ways += it.second;
            ways %= MOD;
        }

        return ways;
    }
};