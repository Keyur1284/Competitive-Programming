// Problem Link :- https://leetcode.com/problems/median-of-two-sorted-arrays/

// Solved by storing nums in vector and sorting
// Time Complexity : O((n + m) * log(n + m))
// Space Complexity : O(n + m)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> vec;

        for (auto &it : nums1)
            vec.emplace_back(it);

        for (auto &it : nums2)
            vec.emplace_back(it);
        
        sort (vec.begin(), vec.end());

        int n = vec.size();

        if (n & 1)
            return vec[n/2];

        return (double)(vec[n/2] + vec[n/2 - 1])/2.0;
    }   
};


// Solved by Two Pointers Approach
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0, k = 0;
        int arr[n + m];

        while (i < n && j < m) 
            arr[k++] = (nums1[i] < nums2[j]) ? nums1[i++] : nums2[j++];

        while (i < n)
            arr[k++] = nums1[i++];

        while (j < m)
            arr[k++] = nums2[j++];

        int len = n + m;

        if (len & 1)
            return arr[len/2];

        return (double)(arr[len/2] + arr[len/2 - 1])/2.0;
    }   
};


// Solved by Binary Search
// Time Complexity : O(log(min(n, m)))
// Space Complexity : O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        if (n > m)
            return findMedianSortedArrays (nums2, nums1);

        int low = 0, high = n;      // We are doing Binary Search on smaller size vector

        while (low <= high)
        {
            int cut1 = (low + high) >> 1;
            int cut2 = (n + m + 1)/2 - cut1;

            int left1 = (cut1 == 0)? INT_MIN : nums1[cut1 - 1];
            int left2 = (cut2 == 0)? INT_MIN : nums2[cut2 - 1];
            int right1 = (cut1 == n)? INT_MAX : nums1[cut1];
            int right2 = (cut2 == m)? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1)
            {
                if ((n + m) & 1)
                    return max(left1, left2);

                else
                    return (double)(max(left1, left2) + min(right1, right2))/2.0;
            }

            if (left1 > right2)
                high = cut1 - 1;

            else if (left2 > right1)
                low = cut1 + 1;
        }

        return 0;
    }   
};