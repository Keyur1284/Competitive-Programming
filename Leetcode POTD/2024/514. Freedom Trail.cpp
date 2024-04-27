// Problem Link :- https://leetcode.com/problems/freedom-trail/

// Solved by Memoization Method
// Time Complexity :- O(n^2 * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int solve(int rInd, int kInd, int &n, int &m, string &ring, string &key, vector<vector<int>> &dp)
    {
        if (kInd == m)
            return 0;

        if (dp[rInd][kInd] != -1)
            return dp[rInd][kInd];
        
        int minSteps = 1e9;

        for (int index = 0; index < n; index++)
        {
            if (ring[index] == key[kInd])
            {
                int steps =  1 + countSteps(rInd, index, n) + solve(index, kInd + 1, n, m, ring, key, dp);
                minSteps = min(steps, minSteps);
            }
        }
        
        return dp[rInd][kInd] = minSteps;
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, n, m, ring, key, dp);
    }
};



class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int solve(int rInd, int kInd, int &n, int &m, string &ring, string &key, vector<int> pos[], vector<vector<int>> &dp)
    {
        if (kInd == m)
            return 0;

        if (dp[rInd][kInd] != -1)
            return dp[rInd][kInd];

        int minSteps = 1e9;

        for (auto &next : pos[key[kInd] - 'a'])
        {
            int steps = 1 + countSteps(rInd, next, n) + solve(next, kInd + 1, n, m, ring, key, pos, dp);
            minSteps = min(steps, minSteps);
        }

        return dp[rInd][kInd] = minSteps;
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();
        vector<int> pos[26];

        for (int i = 0; i < n; i++)
        {
            pos[ring[i] - 'a'].emplace_back(i);
        }

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, n, m, ring, key, pos, dp);
    }
};



// Solved by Memoization Method + Binary Search
// Time Complexity :- O(n * m * log(n))
// Space Complexity :- O(n * m)

class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int solve(int rInd, int kInd, int &n, int &m, string &ring, string &key, vector<int> pos[], vector<vector<int>> &dp)
    {
        if (kInd == m)
            return 0;

        if (dp[rInd][kInd] != -1)
            return dp[rInd][kInd];
        
        int size = pos[key[kInd] - 'a'].size();
        int index1 = lower_bound(pos[key[kInd] - 'a'].begin(), pos[key[kInd] - 'a'].end(), rInd) - pos[key[kInd] - 'a'].begin();
        int index2 = (index1 + size - 1) % size;
        index1 %= size;

        /*
            int clockInd = upper_bound(pos[key[kInd] - 'a'].begin(), pos[key[kInd] - 'a'].end(), rInd) - pos[key[kInd] - 'a'].begin() - 1;
            int antiClockInd = lower_bound(pos[key[kInd] - 'a'].begin(), pos[key[kInd] - 'a'].end(), rInd) - pos[key[kInd] - 'a'].begin();

            clockInd = (clockInd + size) % size;
            antiClockInd = (antiClockInd + size) % size;

            antiClockInd = pos[key[kInd] - 'a'][antiClockInd];
            clockInd = pos[key[kInd] - 'a'][clockInd];

            int clockWise = 1 + countSteps(rInd, clockInd, n) + solve(clockInd, kInd + 1, n, m, ring, key, pos, dp);
            int antiClockWise = 1 + countSteps(rInd, antiClockInd, n) + solve(antiClockInd, kInd + 1, n, m, ring, key, pos, dp);
        */

        int clockWise = 1 + countSteps(rInd, pos[key[kInd] - 'a'][index1], n) + solve(pos[key[kInd] - 'a'][index1], kInd + 1, n, m, ring, key, pos, dp);
        int antiClockWise = 1 + countSteps(rInd, pos[key[kInd] - 'a'][index2], n) + solve(pos[key[kInd] - 'a'][index2], kInd + 1, n, m, ring, key, pos, dp);
        
        return dp[rInd][kInd] = min(clockWise, antiClockWise);
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();
        vector<int> pos[26];

        for (int i = 0; i < n; i++)
        {
            pos[ring[i] - 'a'].emplace_back(i);
        }

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, n, m, ring, key, pos, dp);
    }
};


// Solved by Tabulation Method
// Time Complexity :- O(n^2 * m)
// Space Complexity :- O(n * m)

class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();

        vector<vector<int>> dp(n, vector<int> (m + 1, 1e9));

        for (int rInd = 0; rInd < n; rInd++)
            dp[rInd][m] = 0;

        for (int kInd = m - 1; kInd >= 0; kInd--)
        {
            for (int rInd = 0; rInd < n; rInd++)
            {
                for (int index = 0; index < n; index++)
                {
                    if (ring[index] == key[kInd])
                    {
                        int steps = 1 + countSteps(rInd, index, n) + dp[index][kInd + 1];
                        dp[rInd][kInd] = min(dp[rInd][kInd], steps);
                    }
                }
            }
        }

        return dp[0][0];
    }
};



class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();
        vector<int> pos[26];

        for (int i = 0; i < n; i++)
        {
            pos[ring[i] - 'a'].emplace_back(i);
        }

        vector<vector<int>> dp(n, vector<int> (m + 1, 1e9));

        for (int rInd = 0; rInd < n; rInd++)
            dp[rInd][m] = 0;

        for (int kInd = m - 1; kInd >= 0; kInd--)
        {
            for (int rInd = 0; rInd < n; rInd++)
            {
                for (auto &index : pos[key[kInd] - 'a'])
                {
                    int steps = 1 + countSteps(rInd, index, n) + dp[index][kInd + 1];
                    dp[rInd][kInd] = min(dp[rInd][kInd], steps);
                }
            }
        }

        return dp[0][0];
    }
};



// Solved by Tabulation Method + Binary Search
// Time Complexity :- O(n * m * log(n))
// Space Complexity :- O(n * m)

class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();
        vector<int> pos[26];

        for (int i = 0; i < n; i++)
        {
            pos[ring[i] - 'a'].emplace_back(i);
        }

        vector<vector<int>> dp(n, vector<int> (m + 1, 1e9));

        for (int rInd = 0; rInd < n; rInd++)
            dp[rInd][m] = 0;

        for (int kInd = m - 1; kInd >= 0; kInd--)
        {
            for (int rInd = 0; rInd < n; rInd++)
            {
                int size = pos[key[kInd] - 'a'].size();
                int index1 = lower_bound(pos[key[kInd] - 'a'].begin(), pos[key[kInd] - 'a'].end(), rInd) - pos[key[kInd] - 'a'].begin();
                int index2 = (index1 + size - 1) % size;
                index1 %= size;

                int clockWise = 1 + countSteps(rInd, pos[key[kInd] - 'a'][index1], n) + dp[pos[key[kInd] - 'a'][index1]][kInd + 1];
                int antiClockWise = 1 + countSteps(rInd, pos[key[kInd] - 'a'][index2], n) + dp[pos[key[kInd] - 'a'][index2]][kInd + 1];
                
                dp[rInd][kInd] = min(clockWise, antiClockWise);
            }
        }

        return dp[0][0];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n^2 * m)
// Space Complexity :- O(n)

class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();

        vector<int> dp(n, 0);

        for (int kInd = m - 1; kInd >= 0; kInd--)
        {
            vector<int> temp(n, 1e9);

            for (int rInd = 0; rInd < n; rInd++)
            {
                for (int index = 0; index < n; index++)
                {
                    if (ring[index] == key[kInd])
                    {
                        int steps = 1 + countSteps(rInd, index, n) + dp[index];
                        temp[rInd] = min(temp[rInd], steps);
                    }
                }
            }

            dp = temp;
        }

        return dp[0];
    }
};



class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();
        vector<int> pos[26];

        for (int i = 0; i < n; i++)
        {
            pos[ring[i] - 'a'].emplace_back(i);
        }

        vector<int> dp(n, 0);

        for (int kInd = m - 1; kInd >= 0; kInd--)
        {
            vector<int> temp(n, 1e9);

            for (int rInd = 0; rInd < n; rInd++)
            {
                for (auto &index : pos[key[kInd] - 'a'])
                {
                    int steps = 1 + countSteps(rInd, index, n) + dp[index];
                    temp[rInd] = min(temp[rInd], steps);
                }
            }

            dp = temp;
        }

        return dp[0];
    }
};



// Solved by Tabulation Method (Space Optimized) + Binary Search
// Time Complexity :- O(n * m * log(n))
// Space Complexity :- O(n)

class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();
        vector<int> pos[26];

        for (int i = 0; i < n; i++)
        {
            pos[ring[i] - 'a'].emplace_back(i);
        }

        vector<int> dp(n, 0);

        for (int kInd = m - 1; kInd >= 0; kInd--)
        {
            vector<int> temp(n, 1e9);

            for (int rInd = 0; rInd < n; rInd++)
            {
                int size = pos[key[kInd] - 'a'].size();
                int index1 = lower_bound(pos[key[kInd] - 'a'].begin(), pos[key[kInd] - 'a'].end(), rInd) - pos[key[kInd] - 'a'].begin();
                int index2 = (index1 + size - 1) % size;
                index1 %= size;

                int clockWise = 1 + countSteps(rInd, pos[key[kInd] - 'a'][index1], n) + dp[pos[key[kInd] - 'a'][index1]];
                int antiClockWise = 1 + countSteps(rInd, pos[key[kInd] - 'a'][index2], n) + dp[pos[key[kInd] - 'a'][index2]];
                
                temp[rInd] = min(clockWise, antiClockWise);
            }

            dp = temp;
        }

        return dp[0];
    }
};



// Solved by Dijkstra's Algorithm
// Time Complexity :- O(n * m * log(n * m))
// Space Complexity :- O(n * m)

class Solution {
public:

    int countSteps(int curr, int next, int &n)
    {
        int between = abs(curr - next);
        int around = n - between;
        return min(around, between);
    }

    int findRotateSteps(string ring, string key) {
        
        int n = ring.length(), m = key.length();
        vector<int> pos[26];

        for (int i = 0; i < n; i++)
        {
            pos[ring[i] - 'a'].emplace_back(i);
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int totalSteps = 0;
        
        while (!pq.empty()) 
        {
            auto state = pq.top();
            pq.pop();
            
            totalSteps = state[0];
            int rInd = state[1], kInd = state[2];
            
            if (kInd == m)
                break;
            
            if (vis[rInd][kInd])
                continue;

            vis[rInd][kInd] = true;
            
            for (auto &index : pos[key[kInd] - 'a'])
            {
                int steps = 1 + countSteps(rInd, index, n);
                pq.push({totalSteps + steps, index, kInd + 1});
            }
        }
        
        return totalSteps;
    }
};