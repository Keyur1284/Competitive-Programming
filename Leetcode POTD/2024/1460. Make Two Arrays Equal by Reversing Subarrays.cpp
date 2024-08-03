// Problem Link :- https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/

// Solved by Sorting
// Time complexity :- O(nlogn)
// Space complexity :- O(logn)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        return arr == target;
    }
};



// Solved by counting the frequency of each element
// Time complexity :- O(n)
// Space complexity :- O(1000)

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        int n = arr.size();
        vector<int> freq(1001, 0);

        for (int i = 0; i < n; i++)
        {
            freq[target[i]]++;
            freq[arr[i]]--;
        }

        for (int num = 1; num <= 1000; num++)
        {
            if (freq[num])
                return false;
        }

        return true;
    }
};



