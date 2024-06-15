// Problem Link :- https://leetcode.com/problems/ipo/

// Solved using max heap
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++)
            projects.emplace_back(capital[i], profits[i]);

        sort (projects.begin(), projects.end());

        priority_queue<int> pq;
        int index = 0;

        for (int i = 0; i < k; i++)
        {
            while (index < n && projects[index].first <= w)
                pq.emplace(projects[index++].second);

            if (pq.empty())
                break;

            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};