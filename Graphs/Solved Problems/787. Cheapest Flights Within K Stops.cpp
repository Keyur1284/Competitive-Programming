// Problem Link :- https://leetcode.com/problems/cheapest-flights-within-k-stops/

// Solved by BFS (Simple Queue)
// Time Complexity :- O(N + E*K)
// Space Complexity :- O(N + E*K)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n];

        for (auto &it : flights)
            adj[it[0]].emplace_back(it[1], it[2]);

        queue<pair<int, int>> BFS;
        vector<int> price(n, INT_MAX);

        BFS.emplace(src, 0);
        price[src] = 0;

        while (k >= 0 && !BFS.empty())
        {
            int size = BFS.size();

            while (size--)
            {
                auto front = BFS.front();
                int node = front.first;
                int cost = front.second;
                BFS.pop();

                for (auto &it : adj[node])
                {
                    if (cost + it.second < price[it.first])
                    {
                        price[it.first] = cost + it.second;
                        BFS.emplace(it.first, price[it.first]);
                    }
                }
            }

            k--;
        }

        return (price[dst] == INT_MAX) ? -1 : price[dst];
    }
};



// Solved by Dijkstra's Algorithm (Using Priority Queue)
// Time Complexity :- O(N + E*K*log(E*K))
// Space Complexity :- O(N + E*K)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n];

        for (auto &it : flights)
            adj[it[0]].emplace_back(it[1], it[2]);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> stops(n, INT_MAX);

        pq.push({0, src, 0});

        while (!pq.empty())
        {
            auto flight = pq.top();
            int price = flight[0];
            int node = flight[1];
            int steps = flight[2];
            pq.pop();

            if (steps > stops[node] || steps > k + 1)
                continue;

            if (node == dst)
                return price;

            stops[node] = steps;

            for (auto &it : adj[node])
            {
                pq.push({price + it.second, it.first, steps + 1});
            }
        }
        
        return -1;
    }
};


// Solved by making a struct of Flight and Comparator


class Solution {
public:

    struct Flight {

        int price, node, steps;

        Flight (int a, int b, int c)
        {
            price = a;
            node = b;
            steps = c;
        }
    };

    struct comp {
        
        bool operator()(Flight &a, Flight &b)
        {
            return a.price > b.price;
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n];

        for (auto &it : flights)
            adj[it[0]].emplace_back(it[1], it[2]);

        priority_queue<Flight, vector<Flight>, comp> pq;
        vector<int> stops(n, INT_MAX);

        pq.emplace(Flight(0, src, 0));

        while (!pq.empty())
        {
            auto plane = pq.top();
            int price = plane.price;
            int node = plane.node;
            int steps = plane.steps;
            pq.pop();

            if (steps > stops[node] || steps > k + 1)
                continue;

            if (node == dst)
                return price;

            stops[node] = steps;

            for (auto &it : adj[node])
            {
                pq.emplace(Flight(price + it.second, it.first, steps + 1));
            }
        }
        
        return -1;
    }
};



// Solved by Bellman Ford's Algorithm
// Time Complexity :- O((N + E)*K)
// Space Complexity :- O(N)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> price(n, 1e6);
        price[src] = 0;

        for (int stops = 0; stops <= k; stops++)
        {
            vector<int> temp = price;

            for (auto &it : flights)
            {
                temp[it[1]] = min(temp[it[1]], price[it[0]] + it[2]);
            }

            price = temp;
        }

        return price[dst] == 1e6 ? -1 : price[dst];
    }
};

