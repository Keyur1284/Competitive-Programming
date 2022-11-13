//Problem Link :- https://www.lintcode.com/problem/788/

class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        
        int row = maze.size();
        int col = maze[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        vector <int> dis(row * col + 1, INT_MAX);

        priority_queue <pair<int, pair<int, int>>, vector <pair<int, pair<int, int>>>, greater <pair<int, pair<int, int>>>> pq;

        dis[start[0] * col + start[1]] = 0;
        pq.push({0, {start[0], start[1]}});

        int count, newx, newy;

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for (int i = 0; i<4; i++)
            {
                newx = x;
                newy = y;
                count = 0;

                while (newx >= 0 && newx < row && newy >= 0 && newy < col && maze[newx][newy] == 0)
                {
                    newx += dx[i];
                    newy += dy[i];
                    count++;
                }

                count--;
                newx -= dx[i];
                newy -= dy[i];

                if (dist + count < dis[newx * col + newy])
                {
                    dis[newx * col + newy] = dist + count;
                    pq.push({dis[newx * col + newy], {newx, newy}});
                }
            }
        }

        return (dis[destination[0]*col + destination[1]] == INT_MAX) ? -1 : dis[destination[0]*col + destination[1]];
    }
};