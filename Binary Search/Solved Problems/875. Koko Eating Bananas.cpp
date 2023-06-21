// Problem Link :- https://leetcode.com/problems/koko-eating-bananas/

// Solved by Binary Search
// Time Complexity :- O(n*log(maxEle))
// Space Complexity :- O(1)

class Solution {
public:

    bool check (long long speed, vector<int> &piles, int hours)
    {
        long long time = 0;

        for (auto &it : piles)
            time += (it + speed - 1)/speed;

        return (time <= hours);
    }    

    int minEatingSpeed(vector<int>& piles, int h) {

        long long high = *max_element(piles.begin(), piles.end());
        long long low = 1, mid, ans = high;
        
        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, piles, h))
            {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return ans;
    }
};