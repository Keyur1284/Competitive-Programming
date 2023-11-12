// Problem Link :- https://leetcode.com/problems/bus-routes/

// Solved by BFS with Bus Stops as Nodes
// Time Complexity :- O(n^2 * k)    n = number of routes
// Space Complexity :- O(n * k)     k = average number of stops in a route

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if (source == target)
            return 0;

        unordered_map<int, vector<int>> adj;
        int n = routes.size();

        for (int i = 0; i < n; i++)
        {
            for (auto &it : routes[i])
                adj[it].emplace_back(i);
        }

        queue<int> BFS;
        vector<bool> vis(n, false);

        for (auto &it : adj[source])
        {
            BFS.emplace(it);
            vis[it] = true;
        }

        int buses = 1;

        while (!BFS.empty())
        {
            int size = BFS.size();

            while (size--)
            {   
                auto index = BFS.front();
                BFS.pop();

                for (auto &stop : routes[index])
                {
                    if (stop == target)
                        return buses;

                    for (auto &next : adj[stop])
                    {
                        if (!vis[next])
                        {
                            BFS.emplace(next);
                            vis[next] = true;
                        }
                    }
                }
            }

            buses++;
        }

        return -1;
    }
};


// Solved by BFS with Bus Routes as Nodes
// Time Complexity :- O(n^2 * k)    n = number of routes
// Space Complexity :- O(n^2)     k = average number of stops in a route

class Solution {
public:

    bool hasCommonStop (vector<int> &route1, vector<int> &route2)
    {
        int n = route1.size(), m = route2.size();
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (route1[i] == route2[j])
                return true;

            (route1[i] < route2[j]) ? i++ : j++;
        }

        return false;
    }

    bool isStopPresent (vector<int> &route, int node)
    {
        for (auto &stop : route)
        {
            if (stop == node)
                return true;
        }

        return false;
    }

    void buildGraph (vector<vector<int>>& routes, vector<int> adj[])
    {
        int n = routes.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (hasCommonStop(routes[i], routes[j]))
                {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }
    }

    void addSourceRoutes (vector<vector<int>>& routes, int source, queue<int> &BFS, vector<bool> &vis)
    {
        int n = routes.size();

        for (int i = 0; i < n; i++)
        {
            if (isStopPresent(routes[i], source))
            {
                BFS.emplace(i);
                vis[i] = true;
            }
        }
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if (source == target)
            return 0;

        int n = routes.size();
        vector<int> adj[n];
        
        for (auto &route : routes)
            sort(route.begin(), route.end());

        buildGraph(routes, adj);

        queue<int> BFS;
        vector<bool> vis(n, false);

        addSourceRoutes(routes, source, BFS, vis);

        int buses = 1;

        while (!BFS.empty())
        {
            int size = BFS.size();

            while (size--)
            {   
                auto index = BFS.front();
                BFS.pop();

                if (isStopPresent(routes[index], target))
                    return buses;

                for (auto &it : adj[index])
                {
                    if (!vis[it])
                    {
                        BFS.emplace(it);
                        vis[it] = true;
                    }
                }
            }

            buses++;
        }

        return -1;
    }
};