// Problem Link :- https://leetcode.com/problems/jump-game-iv/

// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size(), steps = 0;
        vector<bool> vis (n , false);
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
            adj[arr[i]].emplace_back(i);

        queue <int> visIndices;
        vis[0] = true;
        visIndices.emplace(0);

        while (!visIndices.empty())
        {
            int size = visIndices.size();

            while (size--)
            {
                int index = visIndices.front();
                visIndices.pop();

                if (index == n - 1)
                    return steps;

                vector<int> &jumpTo = adj[arr[index]];
                jumpTo.emplace_back(index + 1);
                jumpTo.emplace_back(index - 1);

                for (auto &it : jumpTo)
                {
                    if (it >= 0 && it < n && !vis[it])
                    {
                        visIndices.emplace(it);
                        vis[it] = true;
                    }
                }

                jumpTo.clear();
            }

            steps++;
        }

        return -1;
    }
};