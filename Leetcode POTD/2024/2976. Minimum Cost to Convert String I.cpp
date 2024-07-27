// Problem Link :- https://leetcode.com/problems/minimum-cost-to-convert-string-i/

// Solved by Dijkstra's Algorithm
// Time Complexity :- O(n + m + 26 * (m + 26) * log(26))
// Space Complexity :- O(m + 26 * 26)

class Solution {
public:

    vector<long long> dijkstra(int start, vector<pair<int, int>> adj[])
    {
        vector<long long> minCost(26, INT_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.emplace(0, start);

        while(!pq.empty())
        {
            auto [cost, curr] = pq.top();
            pq.pop();

            if (minCost[curr] < cost)
                continue;

            for (auto &[next, convCost] : adj[curr])
            {
                long long newCost = cost + convCost;

                if (newCost < minCost[next])
                {
                    minCost[next] = newCost;
                    pq.emplace(newCost, next);
                }
            }
        }

        return minCost;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        int n = source.length(), m = cost.size();
        vector<pair<int, int>> adj[26];

        for (int i = 0; i < m; i++)
            adj[original[i] - 'a'].emplace_back(changed[i] - 'a', cost[i]);

        vector<long long> minCost[26];

        for (int src = 0; src < 26; src++)
        {
            minCost[src] = dijkstra(src, adj);
        }

        long long totalCost = 0;

        for (int i = 0; i < n; i++)
        {
            if (source[i] != target[i])
            {
                long long cost = minCost[source[i] - 'a'][target[i] - 'a'];

                if (cost == INT_MAX)
                    return -1;

                totalCost += cost;
            }
        }

        return totalCost;
    }
};



// Solved by Floyd Warshall Algorithm
// Time Complexity :- O(n + m + 26 * 26 * 26)
// Space Complexity :- O(26 * 26)

class Solution {
public:

    void floydWarshall(vector<vector<long long>> &minCost)
    {
        for (int via = 0; via < 26; via++)
        {
            for (int src = 0; src < 26; src++)
            {
                for (int dest = 0; dest < 26; dest++)
                {
                    minCost[src][dest] = min(minCost[src][dest], minCost[src][via] + minCost[via][dest]);
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        int n = source.length(), m = cost.size();
        vector<vector<long long>> minCost(26, vector<long long> (26, INT_MAX));

        for (int i = 0; i < m; i++)
        {
            int src = original[i] - 'a', dest = changed[i] - 'a';
            minCost[src][dest] = min(minCost[src][dest], 1LL * cost[i]);
        }

        floydWarshall(minCost);

        long long totalCost = 0;

        for (int i = 0; i < n; i++)
        {
            if (source[i] != target[i])
            {
                long long cost = minCost[source[i] - 'a'][target[i] - 'a'];

                if (cost == INT_MAX)
                    return -1;

                totalCost += cost;
            }
        }

        return totalCost;
    }
};