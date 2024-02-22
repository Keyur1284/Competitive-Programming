// Problem Link :- https://leetcode.com/problems/find-the-town-judge/

// Solved by counting indegree and outdegree 
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> freq(n + 1, 0);

        for (auto &it : trust)
        {
            freq[it[0]]--;
            freq[it[1]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (freq[i] == n - 1)
                return i;
        }

        return -1;
    }
};