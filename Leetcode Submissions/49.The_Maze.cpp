//Problem Link :- https://www.lintcode.com/problem/787/

class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) 
    {
        queue <pair<int, int>> q;
        int row = maze.size();
        int col = maze[0].size();
        int vis[row][col];
        memset(vis, 0, sizeof vis);
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        q.emplace(start[0], start[1]);
        

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == destination[0] && y == destination[1])
                return true;

            for (int i = 0; i<4; i++)
            {
                int newx = x;
                int newy = y;

                while (newx >= 0 && newx < row && newy >= 0 && newy < col && maze[newx][newy] == 0)
                {
                    newx += dx[i];
                    newy += dy[i];
                }
                
                newx -= dx[i];
                newy -= dy[i];

                if (!vis[newx][newy])
                {
                    vis[newx][newy] = 1;
                    q.emplace(newx, newy);
                }
            }
        }

        return false;
    }
};