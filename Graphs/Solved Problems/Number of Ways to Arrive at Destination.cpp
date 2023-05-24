// Problem Link :- https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1

// Time Complexity :- O(ElogV)
// Space Complexity :- O(E + V)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends