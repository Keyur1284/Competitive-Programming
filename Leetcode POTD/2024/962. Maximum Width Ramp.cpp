// Problem Link :- https://leetcode.com/problems/maximum-width-ramp/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> indices(n);

        for (int i = 0; i < n; i++)
            indices[i] = i;

        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        });

        int minIndex = n, maxWidth = 0;

        for (int i = 0; i < n; i++) 
        {
            maxWidth = max(maxWidth, indices[i] - minIndex);
            minIndex = min(minIndex, indices[i]);
        }

        return maxWidth;
    }
};



// Solved by Two Pointers
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int n = nums.size();
        vector<int> rightMax(n);
        rightMax[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], nums[i]);

        int left = 0, right = 0, maxWidth = 0;

        while (right < n) 
        {
            while (left < right && nums[left] > rightMax[right])
                left++;
            
            maxWidth = max(maxWidth, right - left);
            right++;
        }

        return maxWidth;
    }
};



// Solved using stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int n = nums.size();
        stack<int> indicesStack;

        for (int i = 0; i < n; i++) 
        {
            if (indicesStack.empty() || nums[indicesStack.top()] > nums[i])
                indicesStack.emplace(i);
        }

        int maxWidth = 0;

        for (int j = n - 1; j >= 0; j--) 
        {
            while (!indicesStack.empty() && nums[indicesStack.top()] <= nums[j]) 
            {
                maxWidth = max(maxWidth, j - indicesStack.top());
                indicesStack.pop();
            }
        }

        return maxWidth;
    }
};