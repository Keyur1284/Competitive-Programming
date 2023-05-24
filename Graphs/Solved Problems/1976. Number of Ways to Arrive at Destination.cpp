// Problem Link :- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

// Time Complexity :- O(ElogV)
// Space Complexity :- O(E + V)

class Solution {
public:

    int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int, int>> adj[n];
        
        for (auto &it : roads)
        {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        vector<long long> duration(n, LLONG_MAX), ways(n, 0);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        
        pq.emplace(0, 0);
        duration[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty())
        {
            auto tuple = pq.top();
            long long time = tuple.first;
            long long node = tuple.second;
            pq.pop();
            
            for (auto &it : adj[node])
            {
                if (time + it.second < duration[it.first])
                {
                    duration[it.first] = time + it.second;
                    ways[it.first] = ways[node];
                    
                    pq.emplace(duration[it.first], it.first);
                }
                
                else if (time + it.second == duration[it.first])
                {
                    ways[it.first] += ways[node];
                    ways[it.first] %= MOD;
                }
            }
        }
        
        return ways[n - 1] % MOD;
    }
};