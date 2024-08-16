// Problem Link :- https://leetcode.com/problems/maximum-distance-in-arrays/

// Solved using priority_queue
// Time Complexity :- O(nlog2)
// Space Complexity :- O(1)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int m = arrays.size();
        priority_queue<pair<int, int>> minHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxHeap;

        for (int i = 0; i < m; i++)
        {
            minHeap.emplace(arrays[i][0], i);
            maxHeap.emplace(arrays[i].back(), i);

            if (minHeap.size() > 2)
                minHeap.pop();

            if (maxHeap.size() > 2)
                maxHeap.pop();
        }

        auto [min1, ind1] = minHeap.top();
        minHeap.pop();

        auto [min2, ind2] = minHeap.top();
        minHeap.pop();

        auto [max1, ind3] = maxHeap.top();
        maxHeap.pop();

        auto [max2, ind4] = maxHeap.top();
        maxHeap.pop();

        int maxAns = 0;

        if (ind1 != ind3)
            maxAns = max(maxAns, abs(max1 - min1));

        if (ind1 != ind4)
            maxAns = max(maxAns, abs(max2 - min1));

        if (ind2 != ind3)
            maxAns = max(maxAns, abs(max1 - min2));

        if (ind2 != ind4)
            maxAns = max(maxAns, abs(max2 - min2));

        return maxAns;
    }
};



// Solved by Greedy Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int mini = 1e4, maxi = -1e4, maxDiff = 0;

        for (auto &array : arrays)
        {
            maxDiff = max({maxDiff, maxi - array.front(), array.back() - mini});
            mini = min(mini, array.front());
            maxi = max(maxi, array.back());
        }
        
        return maxDiff;
    }
};