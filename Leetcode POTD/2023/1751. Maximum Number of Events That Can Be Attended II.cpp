// Problem Link :- https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

// Solved by Memoization + Binary Search
// Time Complexity :- O(n * k * log(n))
// Space Complexity :- O(n * k)

class Solution {
public:

    int solve (int index, int k, int &n, vector<vector<int>> &dp, vector<vector<int>>& events)
    {
        if (index >= n || k == 0)
            return 0;

        if (dp[index][k] != -1)
            return dp[index][k];

        int notTake = solve (index + 1, k, n, dp, events);
        int take = 0;

        int low = index + 1, high = n - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (events[mid][0] > events[index][1])
                high = mid - 1;

            else
                low = mid + 1;
        }

        take += events[index][2] + solve (low, k - 1, n, dp, events);

        return dp[index][k] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n, vector<int> (k + 1, -1));

        return solve (0, k, n, dp, events);
    }
};



// Solved by Memoization + Binary Search (Using inbuilt upper_bound function)
// Time Complexity :- O(n * k * log(n))
// Space Complexity :- O(n * k)

class Solution {
public:

    int solve (int index, int k, int &n, vector<vector<int>> &dp, vector<vector<int>>& events)
    {
        if (index >= n || k == 0)
            return 0;

        if (dp[index][k] != -1)
            return dp[index][k];

        int notTake = solve (index + 1, k, n, dp, events);
        int take = 0;
        vector<int> next = {events[index][1], INT_MAX, INT_MAX};

        int nextIndex = upper_bound(events.begin() + index + 1, events.end(), next) - events.begin();

        take += events[index][2] + solve (nextIndex, k - 1, n, dp, events);

        return dp[index][k] = max(take, notTake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        sort(events.begin(), events.end());

        vector<vector<int>> dp(n, vector<int> (k + 1, -1));

        return solve (0, k, n, dp, events);
    }
};