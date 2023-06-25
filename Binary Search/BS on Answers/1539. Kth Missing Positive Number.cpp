// Problem Link :- https://leetcode.com/problems/kth-missing-positive-number/

// Solved by Brute Force Approach
// Time Complexity :- O(N)
// Space Complexity :- O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        for (auto &it : arr)
        {
            if (it <= k)
                k++;

            else
                break;
        }

        return k;
    }
};



// Solved by Binary Search
// Time Complexity :- O(logN)
// Space Complexity :- O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int low = 0, high = n - 1, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            int missing = arr[mid] - (mid + 1); 

            if (missing < k)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return low + k;
    }
};