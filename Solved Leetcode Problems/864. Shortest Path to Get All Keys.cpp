// Problem Link :- https://leetcode.com/problems/shortest-path-to-get-all-keys/

// Solved by BFS
// Time Complexity :- O(m * n * 2^k)
// Space Complexity :- O(m * n * 2^k)

class Solution {
public:

    class Node {
        public:
        int keys, x, y;

        Node (int a, int b, int c)
        {
            this->keys = a;
            this->x = b;
            this->y = c;
        }

    };

    bool isValid (int x, int y, int m, int n)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }

    int shortestPathAllKeys(vector<string>& grid) {

        int m = grid.size(), n = grid[0].size(), moves = 0, startx = -1, starty = -1, totalKeys = 0;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

        unordered_set<string> vis;
        queue<Node> BFS;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char cell = grid[i][j];
                
                if (cell == '@')
                {
                    startx = i;
                    starty = j;
                }

                else if (islower(cell))
                    totalKeys++;
            }
        }

        string state = to_string(0) + " " + to_string(startx) + " " + to_string(starty);
        BFS.emplace(Node(0, startx, starty));
        vis.emplace(state);

        while (!BFS.empty())
        {
            int size = BFS.size();

            while (size--)
            {
                auto it = BFS.front();
                BFS.pop();
                int currKeys = it.keys, x = it.x, y = it.y;

                if (currKeys == (1 << totalKeys) - 1)
                    return moves;

                for (int i = 0; i < 4; i++)
                {
                    int newx = x + dx[i], newy = y + dy[i], updatedKeys = currKeys;

                    if (isValid(newx, newy, m, n))
                    {
                        char cell = grid[newx][newy];

                        if (cell == '#')
                            continue;
                        
                        if (islower(cell))
                        {
                            int index = cell - 'a';
                            updatedKeys |= (1 << index);
                        }

                        if (isupper(cell))
                        {
                            int index = cell - 'A';

                            if ((updatedKeys & (1 << index)) == 0)
                                continue;
                        }

                        state = to_string(updatedKeys) + " " + to_string(newx) + " " + to_string(newy);

                        if (vis.find(state) == vis.end())
                        {
                            BFS.emplace(Node(updatedKeys, newx, newy));
                            vis.emplace(state);
                        }
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};