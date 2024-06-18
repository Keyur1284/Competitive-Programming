// Problem Link :- https://leetcode.com/problems/most-profit-assigning-work/

// Solved by Sorting
// Time Complexity :- O(nlogn + mlogm)
// Space Complexity :- O(n + logn + logm)

class Solution {
public:
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int n = difficulty.size(), m = worker.size();
        vector<pair<int, int>> jobs;

        for (int i = 0; i < n; i++)
            jobs.emplace_back(difficulty[i], profit[i]);

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end()); 

        int maxProfit = 0, ind = 0, maxi = 0;

        for (auto &power : worker)
        {
            while (ind < n && jobs[ind].first <= power)
                maxi = max(maxi, jobs[ind++].second);

            maxProfit += maxi;
        }

        return maxProfit;
    }
};



class Job {
public:
    int difficulty, profit;

    Job (int diff, int prof)
    {
        difficulty = diff;
        profit = prof;
    }

    bool operator<(const Job &job) const {

        if (difficulty == job.difficulty)
            return profit > job.profit;

        return difficulty < job.difficulty;
    }
};

class Solution {
public:
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int n = difficulty.size(), m = worker.size();
        vector<Job> jobs;

        for (int i = 0; i < n; i++)
            jobs.emplace_back(Job(difficulty[i], profit[i]));

        sort(jobs.begin(), jobs.end());
        
        vector<int> maxProfits(n);
        maxProfits[0] = jobs[0].profit;

        for (int i = 1; i < n; i++)
        {
            maxProfits[i] = max(maxProfits[i - 1], jobs[i].profit);
        }  

        int maxProfit = 0;

        for (int i = 0; i < m; i++)
        {
            int power = worker[i];
            int low = 0, high = n - 1, mid, ans = n;

            while (low <= high)
            {
                mid = (low + high) >> 1;
                if (jobs[mid].difficulty > power)
                {
                    ans = mid;
                    high = mid - 1;
                }

                else
                    low = mid + 1;
            }

            maxProfit += (ans - 1 >= 0) ? maxProfits[ans - 1] : 0;
        }

        return maxProfit;
    }
};



class Job {
public:
    int difficulty, profit;

    Job (int diff, int prof)
    {
        difficulty = diff;
        profit = prof;
    }

    bool operator<(const Job &job) const {

        if (difficulty == job.difficulty)
            return profit > job.profit;

        return difficulty < job.difficulty;
    }
};

class Solution {
public:
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int n = difficulty.size(), m = worker.size();
        vector<Job> jobs;

        for (int i = 0; i < n; i++)
            jobs.emplace_back(Job(difficulty[i], profit[i]));

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end()); 

        int maxProfit = 0, ind = 0, maxi = 0;

        for (auto &power : worker)
        {
            while (ind < n && jobs[ind].difficulty <= power)
                maxi = max(maxi, jobs[ind++].profit);

            maxProfit += maxi;
        }

        return maxProfit;
    }
};