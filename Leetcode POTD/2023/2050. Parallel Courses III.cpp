// Problem Link :- https://leetcode.com/problems/parallel-courses-iii/

// Solved by Topological Sort
// Time Complexity :- O(E + V)
// Space Complexity :- O(E + V)

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> adj[n + 1], indegree(n + 1, 0);

        for (auto &it : relations)
        {
            adj[it[0]].emplace_back(it[1]);
            indegree[it[1]]++;
        }

        queue<int> BFS;
        vector<int> maxTime(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                BFS.emplace(i);
                maxTime[i] = time[i - 1];
            }
        }

        while (!BFS.empty())
        {
            int node = BFS.front();
            BFS.pop();

            for (auto &it : adj[node])
            {
                maxTime[it] = max(maxTime[it], time[it - 1] + maxTime[node]);

                indegree[it]--;

                if (indegree[it] == 0)
                    BFS.emplace(it);
            }
        }

        int ans = *max_element(maxTime.begin(), maxTime.end());

        return ans;
    }
};



// Solved by DFS 
// Time Complexity :- O(E + V)
// Space Complexity :- O(E + V)

class Solution {
public:

    int solve (int node, vector<int> &dp, vector<int> &time, vector<int> adj[])
    {
        if (dp[node] != -1)
            return dp[node];
        
        int maxi = 0;

        for (auto &it : adj[node])
        {
            maxi = max(maxi, solve(it, dp, time, adj));
        }

        return dp[node] = maxi + time[node - 1];
    }

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<int> adj[n + 1], dp(n + 1, -1);

        for (auto &it : relations)
        {
            adj[it[0]].emplace_back(it[1]);
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, solve(i, dp, time, adj));
        }
        
        return ans;
    }
};