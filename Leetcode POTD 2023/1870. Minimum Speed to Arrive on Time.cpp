// Problem Link :- https://leetcode.com/problems/minimum-speed-to-arrive-on-time/

// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:

    bool check (int speed, int n, vector<int> &dist, double &hour)
    {
        double currTime = 0;

        for (int i = 0; i < n; i++)
        {
            currTime = ceil(currTime);
            currTime += dist[i] * 1.0/speed;

            if (currTime > hour)
                return false;
        }

        return true;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        int n = dist.size();
        int low = 1, high = 1e7, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, n, dist, hour))
                high = mid - 1;

            else
                low = mid + 1;
        }    

        return (low > 1e7) ? -1 : low;
    }
};