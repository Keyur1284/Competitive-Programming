// Problem Link :- https://leetcode.com/problems/maximum-running-time-of-n-computers/

// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:

    bool check (long long time, int n, vector<int> &batteries)
    {
        long long curr = 0LL;

        for (auto &it : batteries)
            curr += min(1LL * it, time);

        return (curr >= time * n);
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        
        int total = batteries.size();
        long long low = *min_element(batteries.begin(), batteries.end()), mid;
        long long high = accumulate(batteries.begin(), batteries.end(), 0LL);

        while (low <= high)
        {
            mid = (low + high) >> 1;

            cout << mid << endl;

            if (check(mid, n, batteries))
                low = mid + 1;

            else
                high = mid - 1;
        }

        return high;
    }
};



class Solution {
public:

    bool check (long long time, int n, int total, long long sum, vector<int> &batteries)
    {
        int count = 0;

        for (int i = total - 1; i >= 0; i--)
        {
            if (batteries[i] >= time)
            {
                count++;
                sum -= batteries[i];
            }

            else
                break;

            if (count == n)
                return true;
        }

        long long avg = sum/(n - count);
        return (avg >= time);
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        
        sort(batteries.begin(), batteries.end());

        int total = batteries.size();
        long long low = batteries[0], mid;
        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL), high = sum;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            cout << mid << endl;

            if (check(mid, n, total, sum, batteries))
                low = mid + 1;

            else
                high = mid - 1;
        }

        return high;
    }
};