// Problem Link :- https://leetcode.com/problems/put-marbles-in-bags/

// Solved by finding pairsum and sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        int n = weights.size();
        vector<int> pairSum;

        for (int i = 0; i < n - 1; i++)
        {
            int sum = weights[i] + weights[i + 1];
            pairSum.emplace_back(sum);
        }

        sort (pairSum.begin(), pairSum.end());

        long long maxSum = 0, minSum = 0;

        for (int i = 0; i < k - 1; i++)
        {
            minSum += pairSum[i];
            maxSum += pairSum[n - i - 2];
        }

        long long diff = maxSum - minSum;
        return diff;
    }
};



// Solved using priority_queue
// Time Complexity :- O(nlogk)
// Space Complexity :- O(k)

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        int n = weights.size();
        priority_queue<int> smallK;
        priority_queue<int, vector<int>, greater<int>> largeK;
        
        for (int i = 0; i < n - 1; i++)
        {
            int sum = weights[i] + weights[i + 1];
            smallK.emplace(sum);
            largeK.emplace(sum);

            if (i >= k - 1)
            {
                smallK.pop();
                largeK.pop();
            }
        }

        long long maxSum = 0, minSum = 0;

        while (!largeK.empty() && !smallK.empty())
        {
            maxSum += largeK.top();
            minSum += smallK.top();
            
            largeK.pop();
            smallK.pop();
        }

        long long diff = maxSum - minSum;
        return diff;
    }
};