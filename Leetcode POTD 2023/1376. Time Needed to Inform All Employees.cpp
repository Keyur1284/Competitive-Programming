// Problem Link :- https://leetcode.com/problems/time-needed-to-inform-all-employees/

// Solved by DFS 
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:

    int DFS (int id, vector<int> &informTime, vector<int> adj[])
    {
        int maxTime = 0;

        for (auto &it : adj[id])
        {
            int time = DFS (it, informTime, adj);
            maxTime = max(time, maxTime);
        }

        return maxTime + informTime[id];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            if (i != headID)
                adj[manager[i]].emplace_back(i);
        }

        return DFS (headID, informTime, adj);;
    }
};


class Solution {
public:

    int maxTime = 0;

    void DFS (int id, int time, vector<int> &informTime, vector<int> adj[])
    {
        for (auto &it : adj[id])
        {
            DFS (it, time + informTime[it], informTime, adj);
        }

        maxTime = max(time, maxTime);
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            if (i != headID)
                adj[manager[i]].emplace_back(i);
        }

        DFS (headID, informTime[headID], informTime, adj);

        return maxTime;
    }
};



// Solved by BFS
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:

    int maxTime = 0;

    void BFS (int startId, int startTime, vector<int> &informTime, vector<int> adj[])
    {
        queue<pair<int, int>> q;
        q.emplace(startId, startTime);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            int id = node.first;
            int time = node.second;

            maxTime = max(time, maxTime);

            for (auto &it : adj[id])
            {
                q.emplace(it, time + informTime[it]);
            }
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            if (i != headID)
                adj[manager[i]].emplace_back(i);
        }

        BFS (headID, informTime[headID], informTime, adj);

        return maxTime;
    }
};
