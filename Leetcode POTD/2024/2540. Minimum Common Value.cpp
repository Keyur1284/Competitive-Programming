// Problem Link :- https://leetcode.com/problems/minimum-common-value/

// Solved using unordered_set
// Time Complexity :- O(n + m)
// Space Complexity :- O(n)

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st(nums1.begin(), nums1.end());

        for (auto &it : nums2)
        {
            if (st.count(it))
                return it;
        }
        
        return -1;
    }
};



// Solved by Binary Search
// Time Complexity :- O(nlogm)
// Space Complexity :- O(1)

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
                
        for (auto &it : nums1)
        {
            if (binary_search(nums2.begin(), nums2.end(), it))
                return it;
        }
        
        return -1;
    }
};



// Solved by two pointer approach
// Time Complexity :- O(n + m)
// Space Complexity :- O(1)

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();

        for (int i = 0, j = 0; i < n && j < m;)
        {
            if (nums1[i] == nums2[j])
                return nums1[i];

            (nums1[i] > nums2[j]) ? j++ : i++;
        }

        return -1;
    }
};