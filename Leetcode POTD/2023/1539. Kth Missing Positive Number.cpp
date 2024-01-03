// Problem Link :- https://leetcode.com/problems/kth-missing-positive-number/

// Solved using unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        unordered_map<int, int> mp;

        for (auto &it : arr)
            mp[it]++;

        int temp = 1;

        while(1)
        {
            if (mp[temp] == 0)
                k--;

            if (k == 0)
                return temp;

            temp++;
        }
        
    }
};



// Solved using two pointer
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();
        int i = 0, missing = 0, count = 0;

        while (i < n && count != k)
        {
            if (arr[i] == missing + 1)
                i++;

            else
                count++;
            
            missing++;
        }

        if (count != k)
            missing = k - count + arr[n - 1];
        
        return missing;
    }
};


// Solved by Binary Search
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();
        int low = 1, high = n, mid, ans = 0;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (arr[mid - 1] - mid < k)
            {
                ans = mid;
                low = mid + 1;
            }

            else
                high = mid - 1;
        }
        
        return ans + k;
    }
};