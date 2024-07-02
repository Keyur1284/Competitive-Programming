// Problem Link :- https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Solved by Sorting + Two Pointers
// Time Complexity :- O(nlogn + mlogm)
// Space Complexity :- O(logn + logm)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        vector<int> res;

        while (i < n && j < m)
        {
            if (nums1[i] == nums2[j])
            {
                res.emplace_back(nums1[i]);
                i++;
				j++;
            }

            else if (nums1[i] < nums2[j])
                i++;
            
            else
                j++;
        }

        return res;
    }
};



// Solved using unordered_map
// Time Complexity :- O(n + m)
// Space Complexity :- O(n + m)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> freq1, freq2;

        for (auto &it : nums1)
            freq1[it]++;

        for (auto &it : nums2)
            freq2[it]++;

        vector<int> ans;

        for (auto &it : freq1)
        {
            while(it.second && freq2[it.first])
            {
                ans.emplace_back(it.first);
                it.second--;
                freq2[it.first]--;
            }
        }

        return ans;
    }
};



// Solved using unordered_map
// Time Complexity :- O(n + m)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> freq;
        vector<int> ans;
        
        for (auto &it : nums1)
            freq[it]++;

        for (auto &it : nums2)
        {
            if (freq[it])
            {
                ans.emplace_back(it);
                freq[it]--;
            }
        }

        return ans;
    }
};