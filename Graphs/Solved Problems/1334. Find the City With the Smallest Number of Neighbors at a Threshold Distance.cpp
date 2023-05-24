// Problem Link :- https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

// Solved by Floyd Warshall's Algorithm (Using Adjacency Matrix)
// Time Complexity :- O(V^3)
// Space Complexity :- O(V^2)


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        int inf = INT_MAX;
        vector<vector<int>> dist (n, vector<int> (n, inf));

        for (auto &it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int via = 0; via < n; via++)
	    {
	        for (int i = 0; i < n; i++)
    	    {
    	        for (int j = 0; j < n; j++)
    	        {
                    if (dist[i][via] < inf && dist[via][j] < inf && dist[i][via] + dist[via][j] < inf)
    	                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
    	        }
    	    }
	    }

        int city = -1, minCount = n;

        for (int i = 0; i < n; i++)
        {
            int count = 0;

            for (int j = 0; j < n; j++)
            {
                count += (dist[i][j] <=  distanceThreshold);
            }

            if (count <= minCount)
            {
                minCount = count;
                city = i;
            }
        }

        return city;
    }
};


// Solved by Dijkstra's Algorithm (Using Adjacency List)
// Time Complexity :- O(V * E * logV)
// Space Complexity :- O(E + V)


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int, int>> adj[n];

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        int city = -1, minCount = n, inf = INT_MAX;

        for (int src = 0; src < n; src++)
	    {
	        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(n, inf);

            pq.emplace(0, src);
            dist[src] = 0;

            while (!pq.empty())
            {
                auto vertex = pq.top();
                int steps = vertex.first;
                int node = vertex.second;
                pq.pop();

                for (auto &it : adj[node])
                {
                    if (steps + it.second < dist[it.first])
                    {
                        dist[it.first] = steps + it.second;
                        pq.emplace(dist[it.first], it.first);
                    }
                }
            }

            int count = 0;

            for (int i = 0; i < n; i++)
            {
                count += (dist[i] <=  distanceThreshold);
            }

            if (count <= minCount)
            {
                minCount = count;
                city = src;
            }
        }

        return city;
    }
};