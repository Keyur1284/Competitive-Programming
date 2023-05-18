//Problem Link :- https://leetcode.com/problems/rotting-oranges/

// Time Complexity :- O(m*n)
// Space Complexity :- O(m*n)

class Solution {
public:

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    struct Node {

        int x, y, time;

        Node (int a, int b, int c)
        {
            x = a;
            y = b; 
            time = c;
        }
    };

    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int oranges = 0;

        queue<Node> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                oranges += (grid[i][j] > 0);

                if (grid[i][j] == 2)
                    q.emplace(Node(i, j, 0));
            }
        }

        int ans = 0, count = 0;

        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            count++;
            q.pop();

            ans = max(ans, time);

            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 1)
                {
                    grid[newx][newy] = 2;
                    q.emplace(Node(newx, newy, time + 1));
                }
            }
        }

        return (count == oranges) ? ans : -1;
    }
};