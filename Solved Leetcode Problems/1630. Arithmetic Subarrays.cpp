// Problem Link :- https://leetcode.com/problems/arithmetic-subarrays/

// Solved by Brute Force Approach + Sorting
// Time Complexity :- O(n*m*log(n))
// Space Complexity :- O(n)

class Solution {
public:
    bool check(vector<int>& arr) 
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        
        for (int i = 2; i < n; i++) 
        {
            if (arr[i] - arr[i - 1] != diff)
                return false;
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int m = l.size();
        vector<bool> ans;

        for (int i = 0; i < m; i++) 
        {
            vector<int> arr(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans.emplace_back(check(arr));
        }
        
        return ans;
    }
};



// Solved without Sorting
// Time Complexity :- O(n*m)
// Space Complexity :- O(n)

class Solution {
public:
    bool check(vector<int>& arr) 
    {
        int n = arr.size(), minElement = INT_MAX, maxElement = INT_MIN;
        unordered_set<int> arrSet;
        
        for (auto &num : arr) 
        {
            minElement = min(minElement, num);
            maxElement = max(maxElement, num);
            arrSet.emplace(num);
        }
        
        if ((maxElement - minElement) % (n - 1) != 0) 
            return false;
        
        int diff = (maxElement - minElement) / (n - 1);
        int curr = minElement + diff;
        
        while (curr < maxElement) 
        {
            if (!arrSet.count(curr))
                return false;
            
            curr += diff;
        }
        
        return true;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int m = l.size();
        vector<bool> ans;

        for (int i = 0; i < m; i++) 
        {
            vector<int> arr(nums.begin() + l[i], nums.begin() + r[i] + 1);
            ans.emplace_back(check(arr));
        }
        
        return ans;
    }
};