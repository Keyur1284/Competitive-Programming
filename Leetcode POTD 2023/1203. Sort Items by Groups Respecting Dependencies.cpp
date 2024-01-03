// Problem Link :- https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/

// Solved by Topological Sort
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:

    void topoSort (vector<int> adj[], vector<int> &indegree, vector<int> &topo)
    {
        queue<int> q;
        int n = indegree.size();

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.emplace(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            topo.emplace_back(node);

            for (auto &it : adj[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.emplace(it);
            }
        }
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        vector<int> sortedItems;

        for (auto &it : group)
        {
            if (it == -1)
                it = m++;
        }

        vector<int> indegItems(n, 0), indegGroups(m, 0), adjItems[n], adjGroups[m];

        for (int i = 0; i < n; i++)
        {
            for (auto &item : beforeItems[i])
            {
                adjItems[item].emplace_back(i);
                indegItems[i]++;

                if (group[item] != group[i])
                {
                    adjGroups[group[item]].emplace_back(group[i]);
                    indegGroups[group[i]]++;
                }
            }
        }

        vector<int> topoItems, topoGroups;

        topoSort (adjItems, indegItems, topoItems);
        topoSort (adjGroups, indegGroups, topoGroups);

        if (topoItems.size() != n || topoGroups.size() != m)
            return sortedItems;

        vector<int> groupItems[m];

        for (auto &it : topoItems)
        {
            groupItems[group[it]].emplace_back(it);
        }

        for (auto &grp : topoGroups)
        {
            for (auto &it : groupItems[grp])
            {
                sortedItems.emplace_back(it);
            }
        }

        return sortedItems;
    }
};