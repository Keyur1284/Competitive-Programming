// Problem Link :- https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(logn)

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] > 1)
                arr[i] = 1 + arr[i - 1];
        }
        
        return arr[n - 1];
    }
};



class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= ans + 1)
                ans++;
        }
        
        return ans;
    }
};



// Solved by Counting Sort
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n = arr.size(), ans = 1;
        vector<int> count(n + 1, 0);

        for (auto &it : arr)
            count[min(it, n)]++;

        for (int num = 2; num <= n; num++)
        {
            ans = min(ans + count[num], num);
        }

        return ans;
    }
};