// Problem Link :- https://leetcode.com/problems/top-k-frequent-elements/

// Solved using Priority Queue
// Time Complexity :- O(NlogN)
// Space Complexity :- O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        for (auto &it : nums)
            mp[it]++;

        priority_queue<pair<int, int>> pq;

        for (auto &it : mp)
            pq.emplace(it.second, it.first);


        vector<int> top;

        for (int i = 0; i < k; i++)
        {
            top.emplace_back(pq.top().second);
            pq.pop();
        }            

        return top;
    }
};


// Solved using vector<pair<int, int>>
// Time Complexity :- O(NlogN)
// Space Complexity :- O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        for (auto &it : nums)
            mp[it]++;

        vector<pair<int, int>> vec;

        for (auto &it : mp)
            vec.emplace_back(it.second, it.first);

        sort (vec.rbegin(), vec.rend());

        vector<int> top;

        for (int i = 0; i < k; i++)
            top.emplace_back(vec[i].second);

        return top;
    }
};

// Solved using Bucket Sort
// Time Complexity :- O(N)
// Space Complexity :- O(N)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;

        for (auto &it : nums)
            mp[it]++;

        vector<int> bucket[n + 1];

        for (auto &it : mp)
            bucket[it.second].emplace_back(it.first);

        vector<int> top;

        for (int i = n; i >= 1; i--)
        {
            for (auto &it : bucket[i])
            {
                top.emplace_back(it);

                if (top.size() == k)
                    return top;
            }
        }

        return top;
    }
};
