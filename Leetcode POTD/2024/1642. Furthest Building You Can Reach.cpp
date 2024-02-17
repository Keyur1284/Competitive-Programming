// Problem Link :- https://leetcode.com/problems/furthest-building-you-can-reach/

// Solved by Binary Search
// Time Complexity :- O(n * logn * logn)
// Space Complexity :- O(n)

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        int low = 0, high = n - 1, mid, ans = 0;

        auto check = [&](int mid)
        {
            priority_queue<int, vector<int>, greater<int>> diffs;

            for (int i = 0; i < mid; i++)
            {
                if (heights[i + 1] <= heights[i])
                continue;

                int diff = heights[i + 1] - heights[i];
                diffs.emplace(diff);
            }

            int availableBricks = bricks;

            while (!diffs.empty() && availableBricks >= diffs.top())
            {
                availableBricks -= diffs.top();
                diffs.pop();
            }

            return (diffs.size() <= ladders);
        };

        while (low <= high)
        {
            mid = low + (high - low)/2;

            if (check(mid))
            {
                ans = mid;
                low = mid + 1;
            }

            else
                high = mid - 1;
        }

        return ans;
    }
};



class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        int low = 0, high = n - 1, mid, ans = 0;

        auto check = [&](int mid)
        {
            vector<int> diffs;

            for (int i = 0; i < mid; i++)
            {
                if (heights[i + 1] <= heights[i])
                continue;

                int diff = heights[i + 1] - heights[i];
                diffs.emplace_back(diff);
            }

            sort(diffs.rbegin(), diffs.rend());

            int availableBricks = bricks;

            while (!diffs.empty() && availableBricks >= diffs.back())
            {
                availableBricks -= diffs.back();
                diffs.pop_back();
            }

            return (diffs.size() <= ladders);
        };

        while (low <= high)
        {
            mid = low + (high - low)/2;

            if (check(mid))
            {
                ans = mid;
                low = mid + 1;
            }

            else
                high = mid - 1;
        }

        return ans;
    }
};



// Solved using Min Heap
// Time Complexity :- O(n * log(ladders))
// Space Complexity :- O(ladders)

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size(), sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n - 1; i++)
        {
            if (heights[i + 1] <= heights[i])
                continue;

            int diff = heights[i + 1] - heights[i];
            pq.emplace(diff);

            if (pq.size() > ladders)
            {
                auto it = pq.top();
                pq.pop();

                if (sum + it > bricks)
                    return i;

                sum += it;
            }
        }

        return n - 1;
    }
};