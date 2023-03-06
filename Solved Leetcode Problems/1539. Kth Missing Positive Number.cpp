// Problem Link :- https://leetcode.com/problems/kth-missing-positive-number/

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


// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();
        int low = 0, high = n - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (arr[mid] - (mid + 1) < k)
                low = mid + 1;

            else
                high = mid - 1;
        }
        
        return low + k;
    }
};