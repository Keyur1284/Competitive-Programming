// Problem Link :- https://leetcode.com/problems/find-the-difference-of-two-arrays/

// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set <int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        vector<int> vec1, vec2;

        for (auto &it : st1)
        {
            if (st2.find(it) == st2.end())
                vec1.emplace_back(it);
        } 

        for (auto &it : st2)
        {
            if (st1.find(it) == st1.end())
                vec2.emplace_back(it);
        } 

        return {vec1, vec2};
    }
};