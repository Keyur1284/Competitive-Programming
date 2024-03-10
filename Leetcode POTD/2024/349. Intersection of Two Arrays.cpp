// Problem Link :- https://leetcode.com/problems/intersection-of-two-arrays/

// Solved using unordered_set
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> st1(nums1.begin(), nums1.end()), st2(nums2.begin(), nums2.end());
        vector<int> intersection;

        for (auto &it : st1)
        {
            if (st2.count(it))
                intersection.emplace_back(it);
        }

        return intersection;
    }
};



// Solved by Binary Search
// Time Complexity :- O((n + m) * log(n))
// Space Complexity :- O(n + log(n))

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());   

        unordered_set<int> st;

        for (auto &it : nums2)
        {
            if (binary_search(nums1.begin(), nums1.end(), it))
                st.emplace(it);
        }

        vector<int> intersection(st.begin(), st.end());

        return intersection;
    }
};



// Solved by Sorting and Two Pointers
// Time Complexity :- O(nlogn + mlogm + n + m)
// Space Complexity :- O(logn + logm)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> intersection;

        int n = nums1.size(), m = nums2.size(), i = 0, j = 0;

        while (i < n && j < m)
        {
            if (nums1[i] == nums2[j])
            {
                if (intersection.empty() || intersection.back() != nums1[i])
                    intersection.emplace_back(nums1[i]);

                i++, j++;
            }

            else if (nums1[i] < nums2[j])
                i++;
            
            else
                j++;
        }

        return intersection;
    }
};