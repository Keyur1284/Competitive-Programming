// Problem Link :- https://leetcode.com/problems/minimum-time-to-complete-trips/

// Let n be the length of time, m be the upper limit of totalTrips 
// and k be the maximum time taken by one trip.
// Time complexity: O(nlog⁡(mk))
// Space Complexity :- O(1)

class Solution {
public:

    bool check (long long duration, vector<int> &time, long long total)
    {
        long long temp = 0;

        for (auto &it : time)
            temp += duration/it;

        return (temp >= total);
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long maxi = *max_element(time.begin(), time.end());
        long long left = 1, right = maxi * totalTrips, mid, ans = right;

        while (left <= right)
        {
            mid = (left + right) >> 1;

            if (check(mid, time, totalTrips))
            {
                ans = mid;
                right = mid - 1;
            }
                
            else
                left = mid + 1;
        }
        
        return ans;
    }
};