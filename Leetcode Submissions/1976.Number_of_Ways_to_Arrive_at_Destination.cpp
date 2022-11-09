//Problem Link :- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector <pair<long long, long long>> adj[n];
        long long MOD = 1e9 + 7;
        
        for (auto it : roads)
        {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }
        
        long long INF = 1e18;

        priority_queue <pair<long long, long long>, vector <pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector <long long> dis(n, INF), ways(n, 0);
        
        ways[0] = 1;
        dis[0] = 0;
        pq.emplace(0, 0);
        
        while (!pq.empty())
        {
            long long node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            
            for (auto it : adj[node])
            {
                long long adjNode = it.first;
                long long wt = it.second;
                
                if (dist + wt < dis[adjNode])
                {
                    dis[adjNode] = dist + wt;
                    pq.emplace(dis[adjNode], adjNode);
                    ways[adjNode] = ways[node];
                }
                
                else if (dist + wt == dis[adjNode])
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
            }
        }
        
        return ways[n-1];
    }
};