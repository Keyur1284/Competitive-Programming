// Problem Link :- https://leetcode.com/problems/minimum-height-trees/

// Solved by BFS
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n], indeg(n, 0);

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
            indeg[it[0]]++;
            indeg[it[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 1)
                q.emplace(i);
        }

        vector<int> mht = {0};

        while (!q.empty())
        {
            mht.clear();
            int size = q.size();

            while (size--)
            {
                int node = q.front();
                q.pop();
                mht.emplace_back(node);

                for (auto &neighbour : adj[node])
                {
                    indeg[neighbour]--;

                    if (indeg[neighbour] == 1)
                        q.emplace(neighbour);
                }
            }
        }

        return mht;
    }
};



class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if (n == 1)
            return {0};

        vector<int> adj[n], indeg(n, 0);

        for (auto &it : edges)
        {
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
            indeg[it[0]]++;
            indeg[it[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 1)
                q.emplace(i);
        }

        while (n > 2)
        {
            int size = q.size();
            n -= size;

            while (size--)
            {
                int node = q.front();
                q.pop();

                for (auto &neighbour : adj[node])
                {
                    indeg[neighbour]--;

                    if (indeg[neighbour] == 1)
                        q.emplace(neighbour);
                }
            }
        }

        vector<int> mht;

        while (!q.empty())
        {
            mht.emplace_back(q.front());
            q.pop();
        }

        return mht;
    }
};