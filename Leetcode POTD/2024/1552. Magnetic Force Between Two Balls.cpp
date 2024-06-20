// Problem Link :- https://leetcode.com/problems/magnetic-force-between-two-balls/

// Solved by Binary Search
// Time Complexity :- O(nlogn + nlogm)  n = position.size() and m = max(position)
// Space Complexity :- O(logn)

class Solution {
public:

    bool check(int minDist, int &n, vector<int> &position, int &m)
    {
        int count = 1, prev = position[0];

        for (int i = 1; i < n; i++)
        {
            if (position[i] - prev >= minDist)
            {
                prev = position[i];
                count++;
            }

            if (count == m)
                return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1, high = position.back();

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (check(mid, n, position, m))
                low = mid + 1;

            else
                high = mid - 1;
        }

        return high;
    }
};