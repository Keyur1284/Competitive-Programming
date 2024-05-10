// Problem Link :- https://leetcode.com/problems/k-th-smallest-prime-fraction/

// Solved by Brute Force Approach
// Time Complexity :- O(n^2 * log(n ^ 2))
// Space Complexity :- O(n ^ 2)

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        vector<pair<double, pair<int, int>>> fractions;
        int n = arr.size();

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                fractions.push_back({1.0 * arr[i]/arr[j], {arr[i], arr[j]}});
            }
        }

        sort(fractions.begin(), fractions.end());

        return {fractions[k - 1].second.first, fractions[k - 1].second.second};
    }
};



// Solved by Binary Search
// Time Complexity :- O(n * log(m ^ 2))
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();
        double low = 0, high = 1.0;
        
        while (high - low > 1e-7)
        {
            double mid = (low + high) / 2;
            int count = 0;
            double maxFraction = 0;
            pair<int, int> res;
            
            for (int i = 0, j = 1; i < n; i++)
            {
                while (j < n && arr[i] > mid * arr[j])
                    j++;
                
                count += n - j;
                
                if (j == n)
                    break;
                
                if (maxFraction < 1.0 * arr[i] / arr[j])
                {
                    maxFraction = 1.0 * arr[i] / arr[j];
                    res = {arr[i], arr[j]};
                }
            }
            
            if (count == k)
                return {res.first, res.second};
            
            else if (count < k)
                low = mid;
            
            else
                high = mid;
        }

        return {};
    }
};



// Solved using priority_queue
// Time Complexity :- O((n + k) * logn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for (int i = 0; i < n; i++)
        {
            pq.push({-1.0 * arr[i] / arr[n - 1], {i, n - 1}});
        }
        
        while (k-- > 1)
        {
            auto top = pq.top().second;
            pq.pop();
            
            int i = top.first, j = top.second;
            
            if (j - 1 > i)
                pq.push({-1.0 * arr[i] / arr[j - 1], {i, j - 1}});
        }
        
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};



class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        
        for (int i = 0; i < n; i++)
        {
            pq.push({1.0 * arr[i] / arr[n - 1], {i, n - 1}});
        }
        
        while (k-- > 1)
        {
            auto top = pq.top().second;
            pq.pop();
            
            int i = top.first, j = top.second;
            
            if (j - 1 > i)
                pq.push({1.0 * arr[i] / arr[j - 1], {i, j - 1}});
        }
        
        return {arr[pq.top().second.first], arr[pq.top().second.second]};
    }
};