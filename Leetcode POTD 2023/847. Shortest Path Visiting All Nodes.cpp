// Problem Link :- https://leetcode.com/problems/shortest-path-visiting-all-nodes/

// Solved by BFS
// Time Complexity :- O(N * 2^N)
// Space Complexity :- O(N * 2^N)

class Solution {
public:

    struct Node {

        int val, mask, cost;

        Node (int a, int b, int c)
        {
            val = a;
            mask = b;
            cost = c;
        }
    };

    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        int allVis = (1 << n) - 1;

        queue<Node> BFS;
        set<pair<int, int>> vis;

        for (int i = 0; i < n; i++)
        {
            int mask = (1 << i);
            Node node(i, mask, 0);

            BFS.emplace(node);
            vis.emplace(i, mask);
        }

        while (!BFS.empty())
        {
            auto node = BFS.front();
            BFS.pop();

            int currVal = node.val, currMask = node.mask, currCost = node.cost;

            if (currMask == allVis)
                return currCost;

            for (auto &it : graph[currVal])
            {
                int nextMask = currMask | (1 << it);
                
                if (vis.find({it, nextMask}) == vis.end())
                {
                    Node next(it, nextMask, currCost + 1);
                    BFS.emplace(next);
                    vis.emplace(it, nextMask);
                }
            }
        }

        return -1;
    }
};