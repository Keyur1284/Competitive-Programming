// Problem Link :- https://leetcode.com/problems/trapping-rain-water/

// Solved using prefMax and suffMax vector
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> prefMax (n + 1, 0), suffMax(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefMax[i + 1] = max(prefMax[i], height[i]);
        } 

        for (int i = n - 1; i >= 0; i--)
        {
            suffMax[i] = max(suffMax[i + 1], height[i]);
        } 

        int water = 0;

        for (int i = 0; i < n; i++)
        {
            water += max(0, min(prefMax[i], suffMax[i]) - height[i]);
        }

        return water;
    }
};



class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> prefMax (n + 1, 0), suffMax(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefMax[i + 1] = max(prefMax[i], height[i]);
        } 

        for (int i = n - 1; i >= 0; i--)
        {
            suffMax[i] = max(suffMax[i + 1], height[i]);
        } 

        int water = 0;

        for (int i = 0; i < n; i++)
        {
            water += min(prefMax[i + 1], suffMax[i]) - height[i];
        }

        return water;
    }
};



class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> prefMax (n, 0), suffMax(n, 0);
        
        prefMax[0] = height[0], suffMax[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
        {
            prefMax[i] = max(prefMax[i - 1], height[i]);
        } 

        for (int i = n - 2; i >= 0; i--)
        {
            suffMax[i] = max(suffMax[i + 1], height[i]);
        } 

        int water = 0;

        for (int i = 0; i < n; i++)
        {
            water += min(prefMax[i], suffMax[i]) - height[i];
        }

        return water;
    }
};



// Solved using two pointer approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int left = 0, right = n - 1, leftMax = 0, rightMax = 0, water = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                (height[left] >= leftMax) ? leftMax = height[left] : water += (leftMax - height[left]);
                left++;
            }

            else
            {
                (height[right] >= rightMax) ? rightMax = height[right] : water += (rightMax - height[right]);
                right--;
            }
        }

        return water;
    }
};



class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int left = 0, right = n - 1, leftMax = 0, rightMax = 0, water = 0;

        while (left <= right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if (leftMax < rightMax)
            {
                water += (leftMax - height[left]);
                left++;
            }

            else
            {
                water += (rightMax - height[right]);
                right--;
            }
        }

        return water;
    }
};