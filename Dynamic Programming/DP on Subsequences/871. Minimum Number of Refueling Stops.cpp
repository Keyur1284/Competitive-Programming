// Problem Link :- https://leetcode.com/problems/minimum-number-of-refueling-stops/

// Solved by Tabulation Method
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        vector<long> dp(n + 1, 0);
        dp[0] = startFuel;

        for (int index = 0; index < n; index++)
        {
            for (int stops = index; stops >= 0; stops--)
            {
                if (dp[stops] >= stations[index][0])
                {
                    dp[stops + 1] = max(dp[stops + 1], dp[stops] + stations[index][1]);
                }
            }
        }

        for (int stops = 0; stops <= n; stops++)
        {
            if (dp[stops] >= target) 
                return stops;
        }   

        return -1;
    }
};



// Solved using Priority Queue
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size(), refuel = 0, curr = startFuel;
        priority_queue<int> pq;

        for (int i = 0; curr < target; refuel++)
        {
            while (i < n && stations[i][0] <= curr)
                pq.emplace(stations[i++][1]);

            if (pq.empty())
                return -1;

            curr += pq.top();
            pq.pop();
        }

        return refuel;
    }
};