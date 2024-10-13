// Problem Link :- https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

// Solved by Optimal Brute Force Approach
// Time Complexity :- O(n * k)  n = total number of elements in all lists
// Space Complexity :- O(k)     k = number of lists

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k = nums.size();

        vector<int> indices(k, 0), range = {0, INT_MAX};

        while (1) 
        {
            int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;

            for (int i = 0; i < k; i++) 
            {
                int currentElement = nums[i][indices[i]];

                if (currentElement < curMin) 
                {
                    curMin = currentElement;
                    minListIndex = i;
                }

                if (currentElement > curMax)
                    curMax = currentElement;
            }

            if (curMax - curMin < range[1] - range[0]) 
            {
                range[0] = curMin;
                range[1] = curMax;
            }

            if (++indices[minListIndex] == nums[minListIndex].size()) 
                break;
        }

        return range;
    }
};



// Solved using priority_queue
// Time Complexity :- O(n * logk)
// Space Complexity :- O(k)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k = nums.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;

        for (int i = 0; i < k; i++) 
        {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        while (pq.size() == k) 
        {
            auto [minVal, indices] = pq.top();
            pq.pop();
            int row = indices.first, col = indices.second;

            if (maxVal - minVal < rangeEnd - rangeStart) 
            {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            if (col + 1 < nums[row].size()) 
            {
                int nextVal = nums[row][col + 1];
                pq.push({nextVal, {row, col + 1}});
                maxVal = max(maxVal, nextVal);
            }
        }

        return {rangeStart, rangeEnd};
    }
};



// Solved by Two Pointer Approach
// Time Complexity :- O(n * logn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k = nums.size();
        vector<pair<int, int>> merged;

        for (int i = 0; i < k; i++) 
        {
            for (int num : nums[i]) 
            {
                merged.emplace_back(num, i);
            }
        }

        sort(merged.begin(), merged.end());

        unordered_map<int, int> freq;
        int left = 0, count = 0, rangeStart = 0, rangeEnd = INT_MAX;

        for (int right = 0; right < merged.size(); right++) 
        {
            freq[merged[right].second]++;
        
            if (freq[merged[right].second] == 1) 
                count++;

            while (count == k) 
            {
                int curRange = merged[right].first - merged[left].first;
                
                if (curRange < rangeEnd - rangeStart) 
                {
                    rangeStart = merged[left].first;
                    rangeEnd = merged[right].first;
                }

                freq[merged[left].second]--;
                
                if (freq[merged[left].second] == 0) 
                    count--;
                
                left++;
            }
        }

        return {rangeStart, rangeEnd};
    }
};