// Problem Link :- https://leetcode.com/problems/find-all-people-with-secret/

// Solved by BFS
// Time Complexity :- O(m * (m + n))    m = number of meetings
// Space Complexity :- O(m + n)         n = number of people

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<pair<int, int>> adj[n];

        for (auto &meet : meetings)
        {
            adj[meet[0]].emplace_back(meet[1], meet[2]);
            adj[meet[1]].emplace_back(meet[0], meet[2]);
        }

        vector<int> lowestTime(n, INT_MAX);
        lowestTime[0] = lowestTime[firstPerson] = 0;
        
        queue<pair<int, int>> BFS;
        BFS.emplace(0, 0);
        BFS.emplace(firstPerson, 0);

        while (!BFS.empty())
        {
            auto [person, time] = BFS.front();
            BFS.pop();

            for (auto &[nextPerson, nextTime] : adj[person])
            {
                if (nextTime >= time && lowestTime[nextPerson] > nextTime)
                {
                    lowestTime[nextPerson] = nextTime;
                    BFS.emplace(nextPerson, nextTime);
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (lowestTime[i] != INT_MAX)
                ans.emplace_back(i);
        }

        return ans;
    }
};



// Solved by DFS
// Time Complexity :- O(m * (m + n))    m = number of meetings
// Space Complexity :- O(m + n)         n = number of people

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<pair<int, int>> adj[n];

        for (auto &meet : meetings)
        {
            adj[meet[0]].emplace_back(meet[1], meet[2]);
            adj[meet[1]].emplace_back(meet[0], meet[2]);
        }

        vector<int> lowestTime(n, INT_MAX);
        lowestTime[0] = lowestTime[firstPerson] = 0;
        
        function<void(int, int)> DFS = [&](int person, int time)
        {
            for (auto &[nextPerson, nextTime] : adj[person])
            {
                if (nextTime >= time && lowestTime[nextPerson] > nextTime)
                {
                    lowestTime[nextPerson] = nextTime;
                    DFS(nextPerson, nextTime);
                }
            }
        };

        DFS (0, 0);
        DFS (firstPerson, 0);

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (lowestTime[i] != INT_MAX)
                ans.emplace_back(i);
        }

        return ans;
    }
};



// Solved by modified Dijkstra's Algorithm
// Time Complexity :- O((n + m) * log(n + m) + m * n)       m = number of meetings
// Space Complexity :- O(m + n)                             n = number of people

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vector<pair<int, int>> adj[n];

        for (auto &meet : meetings)
        {
            adj[meet[0]].emplace_back(meet[1], meet[2]);
            adj[meet[1]].emplace_back(meet[0], meet[2]);
        }

        vector<bool> vis(n, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> BFS;
        BFS.emplace(0, 0);
        BFS.emplace(0, firstPerson);

        while (!BFS.empty())
        {
            auto [time, person] = BFS.top();
            BFS.pop();

            if (vis[person])
                continue;

            vis[person] = true;

            for (auto &[nextPerson, nextTime] : adj[person])
            {
                if (!vis[nextPerson] && nextTime >= time)
                {
                    BFS.emplace(nextTime, nextPerson);
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                ans.emplace_back(i);
        }

        return ans;
    }
};



// Solved by Sorting and using Map
// Time Complexity :- O(m * log(m) + m * n)       m = number of meetings
// Space Complexity :- O(m + n)                  n = number of people

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        map<int, vector<pair<int, int>>> sameTime;

        for (auto &meet : meetings)
        {
            sameTime[meet[2]].emplace_back(meet[0], meet[1]);
        }

        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = knowsSecret[firstPerson] = true;

        for (auto &[time, meets] : sameTime)
        {
            unordered_map<int, vector<int>> meet;
            unordered_set<int> start;

            for (auto &[person1, person2] : meets)
            {
                meet[person1].emplace_back(person2);
                meet[person2].emplace_back(person1);

                if (knowsSecret[person1])
                    start.emplace(person1);
                
                if (knowsSecret[person2])
                    start.emplace(person2);
            }

            queue<int> BFS;

            for (auto &person : start)
                BFS.emplace(person);

            while (!BFS.empty())
            {
                int person = BFS.front();
                BFS.pop();

                for (auto &nextPerson : meet[person])
                {
                    if (!knowsSecret[nextPerson])
                    {
                        knowsSecret[nextPerson] = true;
                        BFS.emplace(nextPerson);
                    }
                }
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (knowsSecret[i])
                ans.emplace_back(i);
        }

        return ans;
    }
};