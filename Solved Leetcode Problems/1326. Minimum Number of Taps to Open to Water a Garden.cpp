// Problem Link :- https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

// Solved by DP
// Time Complexity :- O(n * m)  where m is the average range of the taps
// Space Complexity :- O(n)

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 0; i <= n; i++)
        {
            int start = max(0, i - ranges[i]), end = min(n, i + ranges[i]);

            for (int j = start; j <= end; j++)
            {
                dp[end] = min(dp[end], dp[j] + 1);
            }
        }

        return (dp[n] == 1e9) ? -1 : dp[n];
    }
};



// Solved by sorting intervals
// Time Complexity :- O(n * log(n))
// Space Complexity :- O(n)

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<pair<int, int>> intervals;

        for (int i = 0; i <= n; i++)
        {
            int left = max(0, i - ranges[i]), right = min(n, i + ranges[i]);
            intervals.emplace_back(left, right);
        }

        sort(intervals.begin(), intervals.end());

        int taps = 0;

        for (int i = 0, start = 0, end = 0; i <= n && start < n; start = end, taps++)
        {
            while (i <= n && intervals[i].first <= start)
            {
                end = max(end, intervals[i++].second);
            }

            if (start == end)
                return -1;
        }

        return taps;
    }
};



// Solved by Greedy Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int> maxRight (n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            if (ranges[i])
            {
                int left = max(0, i - ranges[i]), right = i + ranges[i];
                maxRight[left] = max(maxRight[left], right);
            }
        }

        int farthest = 0, end = 0, taps = 0;

        for (int i = 0; i <= n && end < n; end = farthest)
        {
            taps++;

            while (i <= n && i <= end)
            {
                farthest = max(farthest, maxRight[i++]);
            }

            if (end == farthest)
                return -1;
        }

        return taps;
    }
};



class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<int> maxRight (n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            if (ranges[i])
            {
                int left = max(0, i - ranges[i]), right = i + ranges[i];
                maxRight[left] = max(maxRight[left], right);
            }
        }

        int taps = 0, currEnd = 0, nextEnd = 0;

        for (int i = 0; i <= n; i++) 
        {
            if (i > nextEnd)
                return -1;

            if (i > currEnd)
            {
                taps++;
                currEnd = nextEnd;
            }

            nextEnd = max(nextEnd, maxRight[i]);
        }

        return taps;
    }
};