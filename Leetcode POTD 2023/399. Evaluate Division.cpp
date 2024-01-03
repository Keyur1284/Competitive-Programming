// Problem Link :- https://leetcode.com/problems/evaluate-division/

// Time Complexity :- O(Q * (N + E))
// Space Complexity :- O(N + E)

// Solved by DFS (Pass by Reference of temp)

class Solution {
public:

    unordered_map<string, unordered_map<string, double>> makeAdjacencyList (vector<vector<string>>& equations, vector<double>& values)
    {
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> adj;

        for (int i = 0; i < n; i++)
        {
            double val = values[i];
            string numerator = equations[i][0];
            string denominator = equations[i][1];

            adj[numerator][denominator] = val;
            adj[denominator][numerator] = 1.0 / val;
        }

        return adj;
    }

    void DFS (string num, string &den, double &ans, double &temp, unordered_set<string> &vis, unordered_map<string, unordered_map<string, double>> adj)
    {
        if (num == den)
        {
            ans = temp;
            return;
        }

        vis.emplace(num);

        for (auto &it : adj[num])
        {
            if (vis.find(it.first) == vis.end())
            {
                temp *= it.second;
                DFS (it.first, den, ans, temp, vis, adj);
                temp *= 1.0 / it.second;
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, unordered_map<string, double>> adj = makeAdjacencyList(equations, values);
        vector<double> result;

        for (auto &it : queries)
        {
            string numerator = it[0];
            string denominator = it[1];

            if (adj.find(numerator) == adj.end() || adj.find(denominator) == adj.end())
                result.emplace_back(-1.0);

            else
            {
                unordered_set<string> vis;
                double ans = -1.0, temp = 1.0;
                DFS (numerator, denominator, ans, temp, vis, adj);
                result.emplace_back(ans);
            }
        }

        return result;
    }
};



// Solved by DFS (Pass by Value of temp)

class Solution {
public:

    unordered_map<string, unordered_map<string, double>> makeAdjacencyList (vector<vector<string>>& equations, vector<double>& values)
    {
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> adj;

        for (int i = 0; i < n; i++)
        {
            double val = values[i];
            string numerator = equations[i][0];
            string denominator = equations[i][1];

            adj[numerator][denominator] = val;
            adj[denominator][numerator] = 1.0 / val;
        }

        return adj;
    }

    void DFS (string num, string &den, double &ans, double temp, unordered_set<string> &vis, unordered_map<string, unordered_map<string, double>> adj)
    {
        if (num == den)
        {
            ans = temp;
            return;
        }

        vis.emplace(num);

        for (auto &it : adj[num])
        {
            if (vis.find(it.first) == vis.end())
            {
                DFS (it.first, den, ans, temp * it.second, vis, adj);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, unordered_map<string, double>> adj = makeAdjacencyList(equations, values);
        vector<double> result;

        for (auto &it : queries)
        {
            string numerator = it[0];
            string denominator = it[1];

            if (adj.find(numerator) == adj.end() || adj.find(denominator) == adj.end())
                result.emplace_back(-1.0);

            else
            {
                unordered_set<string> vis;
                double ans = -1.0, temp = 1.0;
                DFS (numerator, denominator, ans, temp, vis, adj);
                result.emplace_back(ans);
            }
        }

        return result;
    }
};



// Solved by BFS    

class Solution {
public:

    unordered_map<string, unordered_map<string, double>> makeAdjacencyList (vector<vector<string>>& equations, vector<double>& values)
    {
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> adj;

        for (int i = 0; i < n; i++)
        {
            double val = values[i];
            string numerator = equations[i][0];
            string denominator = equations[i][1];

            adj[numerator][denominator] = val;
            adj[denominator][numerator] = 1.0 / val;
        }

        return adj;
    }

    double BFS (string num, string &den, unordered_map<string, unordered_map<string, double>> adj)
    {
        queue<pair<string, double>> q;
        unordered_set<string> vis;
        q.emplace(num, 1.0);
        vis.emplace(num);

        while (!q.empty())
        {
            string curr = q.front().first;
            double temp = q.front().second;
            q.pop();

            if (curr == den)
                return temp;

            for (auto &it : adj[curr])
            {
                if (vis.find(it.first) == vis.end())
                {
                    q.emplace(it.first, temp * it.second);
                    vis.emplace(it.first);
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, unordered_map<string, double>> adj = makeAdjacencyList(equations, values);
        vector<double> result;

        for (auto &it : queries)
        {
            string numerator = it[0];
            string denominator = it[1];

            if (adj.find(numerator) == adj.end() || adj.find(denominator) == adj.end())
                result.emplace_back(-1.0);

            else
            {
                double ans = BFS (numerator, denominator, adj);
                result.emplace_back(ans);
            }
        }

        return result;
    }
};