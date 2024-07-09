// Problem Link :- https://leetcode.com/problems/average-waiting-time/

// Solved by Simulation
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        int n = customers.size();
        double nextIdleTime = 0, waitingTime = 0;

        for (auto &customer : customers)
        {
            nextIdleTime = max(1.0 * customer[0], nextIdleTime) + customer[1];
            waitingTime += nextIdleTime - customer[0];
        }

        return waitingTime / n;
    }
};