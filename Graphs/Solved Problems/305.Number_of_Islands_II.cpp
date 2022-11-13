//Problem Link :- https://www.lintcode.com/problem/434/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    int findPar(int node, vector <int> &parent)
    {
        if(node == parent[node])
            return node;

        return parent[node] = findPar(parent[node], parent);
    }

    void UnionRank(int u, int v, vector <int> &parent, vector <int> &rank)
    {
        u = findPar(u, parent);
        v = findPar(v, parent);

        if(rank[u] < rank[v])
            parent[u] = v;

        else if (rank[v] < rank[u])
            parent[v] = u;

        else if (rank[u] == rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        
        vector <int> parent (n * m + 1, 0), rank (n * m + 1, 0), ans;
        vector <vector<int>> grid (n, vector <int>(m, 0));
        int dx[] = {0, -1, 0, 1};
        int dy[] = {1, 0, -1, 0};
        int count = 0;

        for (int i = 1; i <= n*m; i++)
            parent[i] = i;

        for (auto it : operators)
        {
            int x = it.x;
            int y = it.y;

            if (grid[x][y] == 1)
            {
                ans.emplace_back(count);
                continue;
            }
            count++;

            grid[x][y] = 1;

            int fixed = x * m + y + 1;

            for (int i = 0; i<4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                int adjacents = newx * m + newy + 1;

                while(newx >= 0 && newy >= 0 && newx < n && newy < m && grid[newx][newy] == 1 && findPar(fixed, parent) != findPar(adjacents, parent))
                {
                    count--;
                    UnionRank(fixed, adjacents, parent, rank);
                }
            }

            ans.emplace_back(count);
        }

        return ans;
    }
};