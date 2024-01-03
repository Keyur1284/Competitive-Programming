// Problem Link :- https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

// Solved by priority_queue
// Time Complexity :- O(min(k * log k, m * n * log (m * n)))
// Space Complexity :- O(min(k * log k, m * n * log (m * n)))

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size(), m = nums2.size();
    
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        set<pair<int, int>> vis;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        vis.emplace(0, 0);

        vector<vector<int>> smallestPairs;

        while (k-- && !pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int index1 = it.second.first, index2 = it.second.second;
            smallestPairs.push_back({nums1[index1], nums2[index2]});

            if (index1 + 1 < n && vis.find({index1 + 1, index2}) == vis.end())
            {
                pq.push({nums1[index1 + 1] + nums2[index2], {index1 + 1, index2}});
                vis.emplace(index1 + 1, index2);
            }

            if (index2 + 1 < m && vis.find({index1, index2 + 1}) == vis.end())
            {
                pq.push({nums1[index1] + nums2[index2 + 1], {index1, index2 + 1}});
                vis.emplace(index1, index2 + 1);
            }
        }

        return smallestPairs;
    }
};