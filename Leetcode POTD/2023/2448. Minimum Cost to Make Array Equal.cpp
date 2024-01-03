// Problem Link :- https://leetcode.com/problems/minimum-cost-to-make-array-equal/

// Solved by Weighted Median Approach
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    long long findCost (int val, int n, vector<int> &nums, vector<int> &cost)
    {
        long long currCost = 0;

        for (int i = 0; i < n; i++)
            currCost += 1LL * abs(nums[i] - val) * cost[i];

        return currCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        long long totalFreq = 0;
        
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++)
        {
            vec.emplace_back(nums[i], cost[i]);
            totalFreq += cost[i];
        }

        sort (vec.begin(), vec.end());

        int i = 0, median = -1;
        long long count = 0;

        while (count < (totalFreq + 1)/2)
        {
            median = vec[i].first;
            count += vec[i].second;
            i++;
        }
            
        long long mincost = findCost (median, n, nums, cost); 

        return mincost;
    }
};



// Solved by Prefix Sum
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    long long findCost (int val, int n, vector<int> &nums, vector<int> &cost)
    {
        long long currCost = 0;

        for (int i = 0; i < n; i++)
            currCost += 1LL * abs(nums[i] - val) * cost[i];

        return currCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++)
        {
            vec.emplace_back(nums[i], cost[i]);
        }

        sort (vec.begin(), vec.end());

        vector<long long> prefFreq (n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefFreq[i + 1] = prefFreq[i] + vec[i].second;
        }

        long long totalFreq = prefFreq.back();

        int medianIndex = lower_bound(prefFreq.begin(), prefFreq.end(), (totalFreq + 1) >> 1) - prefFreq.begin() - 1;
        int val = vec[medianIndex].first;
             
        long long mincost = findCost (val, n, nums, cost); 

        return mincost;
    }
};


class Solution {
public:

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++)
        {
            vec.emplace_back(nums[i], cost[i]);
        }

        sort (vec.begin(), vec.end());

        vector<long long> prefCost (n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefCost[i + 1] = prefCost[i] + vec[i].second;
        }

        long long currCost = 0, mincost = LLONG_MAX;

        for (int i = 1; i < n; i++)
            currCost += 1LL * abs(vec[i].first - vec[0].first) * vec[i].second; 

        mincost = min(mincost, currCost);

        for (int i = 1; i < n; i++)
        {
            int gap = vec[i].first - vec[i - 1].first;
            currCost -= 1LL * gap * (prefCost[n] - prefCost[i]); 
            currCost += 1LL * gap * prefCost[i];

            mincost = min(mincost, currCost);
        }

        return mincost;
    }
};



// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:

    long long findCost (int val, int n, vector<int> &nums, vector<int> &cost)
    {
        long long currCost = 0;

        for (int i = 0; i < n; i++)
            currCost += 1LL * abs(nums[i] - val) * cost[i];

        return currCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        long long mincost = LLONG_MAX;

        int low, high, mid;

        for (auto &it : nums)
        {
            low = min (low, it);
            high = max (high, it);
        }

        while (low <= high)
        {
            mid = (low + high) >> 1;

            long long cost1 = findCost (mid, n, nums, cost);
            long long cost2 = findCost (mid + 1, n, nums, cost);

            mincost = min (cost1, cost2);

            if (cost1 > cost2)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return mincost;
    }
};