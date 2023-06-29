// Problem Link :- https://leetcode.com/problems/total-cost-to-hire-k-workers/

// Solved using 2 priority_queues
// Time Complexity :- O((candidates + k) * log (candidates))
// Space Complexity :- O(candidates)

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> frontpq, backpq;
        int frontIdx = 0, backIdx = n - 1;

        for (int i = 0; i < candidates; i++)
            frontpq.emplace(costs[frontIdx++]);

        for (int i = 0; i < candidates; i++)
        {
            if (frontIdx <= backIdx)
                backpq.emplace(costs[backIdx--]);
        }

        long long netCost = 0;

        for (int i = 0; i < k; i++)
        {
            if (backpq.empty() || (!frontpq.empty() && frontpq.top() <= backpq.top()))
            {
                netCost += frontpq.top();
                frontpq.pop();

                if (frontIdx <= backIdx)
                    frontpq.emplace(costs[frontIdx++]);
            }

            else
            {
                netCost += backpq.top();
                backpq.pop();

                if (frontIdx <= backIdx)
                    backpq.emplace(costs[backIdx--]);
            }
        }

        return netCost;
    }
}; 



// Solved using 1 priority_queue
// Time Complexity :- O((candidates + k) * log (candidates))
// Space Complexity :- O(candidates)

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int frontIdx = 0, backIdx = n - 1;

        for (int i = 0; i < candidates; i++)
            pq.emplace(costs[frontIdx++], 0);

        for (int i = 0; i < candidates; i++)
        {
            if (frontIdx <= backIdx)
                pq.emplace(costs[backIdx--], 1);
        }

        long long netCost = 0;

        for (int i = 0; i < k; i++)
        {
            auto it = pq.top();
            pq.pop();
            int cost = it.first, id = it.second;

            netCost += cost;

            if (frontIdx <= backIdx)
            {
                (id == 0) ? pq.emplace(costs[frontIdx++], 0) : pq.emplace(costs[backIdx--], 1);
            }
        }

        return netCost;
    }
}; 