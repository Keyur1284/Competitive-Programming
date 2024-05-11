// Problem Link :- https://leetcode.com/problems/minimum-cost-to-hire-k-workers/

// Solved using priority_queue and sorting
// Time Complexity :- O(n * (logn + logk))
// Space Complexity :- O(n + k)

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = wage.size();
        double minCost = DBL_MAX, totalQuality = 0;
        vector<pair<double, int>> wageQuality;

        for (int i = 0; i < n; i++)
        {
            wageQuality.emplace_back(1.0 * wage[i]/quality[i], quality[i]);
        } 

        sort(wageQuality.begin(), wageQuality.end());

        priority_queue<double> highQualityWorkers;

        for (int i = 0; i < n; i++)
        {
            totalQuality += wageQuality[i].second;
            highQualityWorkers.emplace(wageQuality[i].second);

            if (highQualityWorkers.size() > k)
            {
                totalQuality -= highQualityWorkers.top();
                highQualityWorkers.pop();
            }

            if (highQualityWorkers.size() == k)
            {
                minCost = min(minCost, wageQuality[i].first * totalQuality);
            }
        }

        return minCost;
    }
};



class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = wage.size();
        double minCost = DBL_MAX, totalQuality = 0;
        vector<pair<double, int>> wageQuality;

        for (int i = 0; i < n; i++)
        {
            wageQuality.emplace_back(1.0 * wage[i]/quality[i], quality[i]);
        } 

        sort(wageQuality.begin(), wageQuality.end());

        priority_queue<double> highQualityWorkers;

        for (auto &worker : wageQuality)
        {
            totalQuality += worker.second;
            highQualityWorkers.emplace(worker.second);

            if (highQualityWorkers.size() > k)
            {
                totalQuality -= highQualityWorkers.top();
                highQualityWorkers.pop();
            }

            if (highQualityWorkers.size() == k)
            {
                minCost = min(minCost, worker.first * totalQuality);
            }
        }

        return minCost;
    }
};