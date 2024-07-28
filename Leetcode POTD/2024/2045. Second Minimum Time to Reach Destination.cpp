// Problem Link :- https://leetcode.com/problems/second-minimum-time-to-reach-destination/

// Solved by Dijkstra Algorithm (Modified)
// Time Complexity :- O(n + e * log(n))
// Space Complexity :- O(n + e)

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int> adj[n + 1];

        for (auto &edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX), freq(n + 1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 1);
        dist1[1] = 0;

        while(!pq.empty())
        {
            auto [currTime, node] = pq.top();
            pq.pop();
            freq[node]++;

            if (node == n && freq[node] == 2)
                return currTime;

            int timeParity = currTime/change, timeToReachChild;

            if (timeParity & 1)
                timeToReachChild = (timeParity + 1) * change + time;

            else
                timeToReachChild = currTime + time;

            for (auto &child : adj[node])
            {
                if (freq[child] == 2)
                    continue;

                if (timeToReachChild < dist1[child])
                {
                    dist2[child] = dist1[child];
                    dist1[child] = timeToReachChild;
                    pq.emplace(timeToReachChild, child);
                }

                else if (timeToReachChild < dist2[child] && dist1[child] != timeToReachChild)
                {
                    dist2[child] = timeToReachChild;
                    pq.emplace(timeToReachChild, child);
                }
            }
        }

        return -1;
    }
};



// Solved by BFS
// Time Complexity :- O(n + e)
// Space Complexity :- O(n + e)

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int> adj[n + 1];

        for (auto &edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
        queue<pair<int, int>> q;
        q.emplace(0, 1);
        dist1[1] = 0;

        while(!q.empty())
        {
            auto [currTime, node] = q.front();
            q.pop();

            int timeParity = currTime/change, timeToReachChild;

            if (timeParity & 1)
                timeToReachChild = (timeParity + 1) * change + time;

            else
                timeToReachChild = currTime + time;

            for (auto &child : adj[node])
            {
                if (timeToReachChild < dist1[child])
                {
                    dist2[child] = dist1[child];
                    dist1[child] = timeToReachChild;
                    q.emplace(timeToReachChild, child);
                }

                else if (timeToReachChild < dist2[child] && dist1[child] != timeToReachChild)
                {
                    if (child == n)
                        return timeToReachChild;

                    dist2[child] = timeToReachChild;
                    q.emplace(timeToReachChild, child);
                }
            }
        }

        return -1;
    }
};