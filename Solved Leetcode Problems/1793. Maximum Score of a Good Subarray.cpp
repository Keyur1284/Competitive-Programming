// Problem Link :- https://leetcode.com/problems/maximum-score-of-a-good-subarray/

// Solved by Binary Search
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
        
    int solve(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> left(k, 0);

        int currMin = INT_MAX;

        for (int i = k - 1; i >= 0; i--) 
        {
            currMin = min(currMin, nums[i]);
            left[i] = currMin;
        }
        
        vector<int> right;
        currMin = INT_MAX;

        for (int i = k; i < n; i++) 
        {
            currMin = min(currMin, nums[i]);
            right.emplace_back(currMin);
        }
        
        int ans = 0, sizeR = right.size();

        for (int j = 0; j < sizeR; j++) 
        {
            currMin = right[j];
            int i = lower_bound(left.begin(), left.end(), currMin) - left.begin();
            int size = (k + j) - i + 1;
            ans = max(ans, currMin * size);
        }
        
        return ans;
    }

    int maximumScore(vector<int>& nums, int k) {
       
        int ans = solve(nums, k);
        reverse(nums.begin(), nums.end());
        return max(ans, solve(nums, nums.size() - k - 1));
    }
};



// Solvind using monotonic stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:

    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> stack;
        
        for (int i = n - 1; i >= 0; i--) 
        {
            while (!stack.empty() && nums[stack.back()] > nums[i]) 
            {
                left[stack.back()] = i;
                stack.pop_back();
            }
            
            stack.emplace_back(i);
        }
        
        vector<int> right(n, n);
        stack.clear();

        for (int i = 0; i < n; i++) 
        {
            while (!stack.empty() && nums[stack.back()] > nums[i]) 
            {
                right[stack.back()] = i;
                stack.pop_back();
            }
            
            stack.emplace_back(i);
        }
        
        int ans = 0;

        for (int i = 0; i < n; i++) 
        {
            if (left[i] < k && right[i] > k) 
            {
                ans = max(ans, nums[i] * (right[i] - left[i] - 1));
            }
        }
        
        return ans;
    }
};



// Solved by two pointer approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size(), left = k, right = k;
        int ans = nums[k], currMin = nums[k];
        
        while (left > 0 || right < n - 1) 
        {
            if ((left > 0 ? nums[left - 1]: 0) < (right < n - 1 ? nums[right + 1] : 0)) 
            {
                right++;
                currMin = min(currMin, nums[right]);
            } 
            
            else 
            {
                left--;
                currMin = min(currMin, nums[left]);
            }
            
            ans = max(ans, currMin * (right - left + 1));
        }
        
        return ans;
    }
};