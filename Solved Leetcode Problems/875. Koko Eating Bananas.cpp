// Problem Link :- https://leetcode.com/problems/koko-eating-bananas/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:

    bool check (long long speed, vector<int> &piles, int hours)
    {
        int time = 0;

        for (auto &it : piles)
            time += (it + speed - 1)/speed;

        return (time <= hours);
    }    

    int minEatingSpeed(vector<int>& piles, int h) {

        long long maxi = *max_element(piles.begin(), piles.end());
        long long left = 1, right = maxi * h, mid, ans = right;
        
        while (left <= right)
        {
            mid = (left + right) >> 1;

            if (check(mid, piles, h))
            {
                ans = mid;
                right = mid - 1;
            }

            else
                left = mid + 1;
        }

        return (int)ans;
    }
};