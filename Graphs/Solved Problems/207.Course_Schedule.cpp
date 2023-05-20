//Problem Link :- https://leetcode.com/problems/course-schedule/

// Time Complexity :- O(N + E)
// Space Complexity :- O(N + E)

// Solved by DFS

class Solution {
public:

    bool checkCycle (int node, vector<bool> &vis, vector<bool> &dfsVis, vector<int> adj[])
    {
        vis[node] = true;
        dfsVis[node] = true;

        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                if (checkCycle(it, vis, dfsVis, adj))
                    return true;
            }

            else if (vis[it] && dfsVis[it])
                return true;
        }

        dfsVis[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];

        for (auto &it : prerequisites)
        {
            adj[it[1]].emplace_back(it[0]);
        }

        vector<bool> vis (numCourses, false), dfsVis (numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, vis, dfsVis, adj))
                    return false;
            }
        }

        return true;
    }
};


// Solved by BFS

class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses], indegree(numCourses, 0);

        for (auto &it : prerequisites)
        {
            adj[it[1]].emplace_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        int count = 0;

        while (!q.empty())
        {
            int node = q.front();
            count++;
            q.pop();

            for (auto &it : adj[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.emplace(it);
            }
        }

        return (count == numCourses);
    }
};