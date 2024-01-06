// Problem Link :- https://leetcode.com/problems/maximum-profit-in-job-scheduling/

// Solved by Memoization Method + Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Job {
public:
    
    int startTime, endTime, profit;

    Job (int _startTime, int _endTime, int _profit)
    {
        startTime = _startTime;
        endTime = _endTime;
        profit = _profit;
    }

    bool operator<(const Job &job) const {

        if (startTime == job.startTime)
        {
            if (endTime == job.endTime)
                return profit > job.profit;

            return endTime < job.endTime;
        }

        return startTime < job.startTime;
    }
};

class Solution {
public:

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        vector<Job> jobs;

        for (int i = 0; i < n; i++)
        {
            jobs.emplace_back(Job(startTime[i], endTime[i], profit[i]));
        }

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);

        auto binarySearch = [&](int curr)
        {
            int low = curr + 1, high = n - 1, ans = n;

            while (low <= high)
            {
                int mid = (low + high) >> 1;

                if (jobs[mid].startTime >= jobs[curr].endTime)
                {
                    ans = mid;
                    high = mid - 1;
                }

                else
                    low = mid + 1;
            }

            return ans;
        };

        auto solve = [&](auto self, int index)
        {
            if (index >= n)
                return 0;

            if (dp[index] != -1)
                return dp[index];

            int notTake = self(self, index + 1);

            int nextJob = binarySearch(index);
            int take = jobs[index].profit + self(self, nextJob);

            return dp[index] = max(take, notTake);
        };

        return solve(solve, 0);
    }
};



class Job {
public:
    
    int startTime, endTime, profit;

    Job (int _startTime, int _endTime, int _profit)
    {
        startTime = _startTime;
        endTime = _endTime;
        profit = _profit;
    }

    bool operator<(const Job &job) const {

        if (startTime == job.startTime)
        {
            if (endTime == job.endTime)
                return profit > job.profit;

            return endTime < job.endTime;
        }

        return startTime < job.startTime;
    }
};


class Solution {
public:

    void addAndSortJobs(vector<Job> &jobs, vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = profit.size();

        for (int i = 0; i < n; i++)
        {
            jobs.emplace_back(Job(startTime[i], endTime[i], profit[i]));
        }

        sort(jobs.begin(), jobs.end());
    }

    int binarySearch(vector<Job> &jobs, int curr)
    {   
        int n = jobs.size();
        int low = curr + 1, high = n - 1, ans = n;

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (jobs[mid].startTime >= jobs[curr].endTime)
            {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return ans;
    }

    int solve(vector<Job> &jobs, vector<int> &dp, int index)
    {
        int n = jobs.size();

        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int notTake = solve(jobs, dp, index + 1);

        int nextJob = binarySearch(jobs, index);
        int take = jobs[index].profit + solve(jobs, dp, nextJob);

        return dp[index] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        vector<Job> jobs;
        addAndSortJobs(jobs, startTime, endTime, profit);

        vector<int> dp(n, -1);

        return solve(jobs, dp, 0);
    }
};



// Solution by Tabulation Method + Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Job {
public:
    
    int startTime, endTime, profit;

    Job (int _startTime, int _endTime, int _profit)
    {
        startTime = _startTime;
        endTime = _endTime;
        profit = _profit;
    }

    bool operator<(const Job &job) const {

        if (startTime == job.startTime)
        {
            if (endTime == job.endTime)
                return profit > job.profit;

            return endTime < job.endTime;
        }

        return startTime < job.startTime;
    }
};

class Solution {
public:

    void addAndSortJobs(vector<Job> &jobs, vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = profit.size();

        for (int i = 0; i < n; i++)
        {
            jobs.emplace_back(Job(startTime[i], endTime[i], profit[i]));
        }

        sort(jobs.begin(), jobs.end());
    }

    int binarySearch(vector<Job> &jobs, int curr)
    {   
        int n = jobs.size();
        int low = curr + 1, high = n - 1, ans = n;

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            if (jobs[mid].startTime >= jobs[curr].endTime)
            {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;
        }

        return ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        vector<Job> jobs;
        addAndSortJobs(jobs, startTime, endTime, profit);

        vector<int> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            int notTake = dp[index + 1];

            int nextJob = binarySearch(jobs, index);
            int take = jobs[index].profit + dp[nextJob];

            dp[index] = max(take, notTake);
        }

        return dp[0];
    }
};