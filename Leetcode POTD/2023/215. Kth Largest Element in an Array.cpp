// Problem Link :- https://leetcode.com/problems/kth-largest-element-in-an-array/

// Solved by using priority_queue
// Time Complexity :- O(nlogk)
// Space Complexity :- O(k)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto &it : nums)
        {
            pq.emplace(it);

            if (pq.size() > k)
                pq.pop();
        }
        
        return pq.top();
    }
};



// Solved by Counting Sort Algorithm
// Time Complexity :- O(n + m)      n = nums.size(), m = maxVal - minVal
// Space Complexity :- O(m)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int maxVal = INT_MIN, minVal = INT_MAX;

        for (auto &it : nums)
        {
            maxVal = max(maxVal, it);
            minVal = min(minVal, it);
        }

        vector<int> count(maxVal - minVal + 1, 0);

        for (auto &it : nums)
        {
            count[it - minVal]++;
        }

        for (int index = maxVal - minVal; index >= 0; index--)
        {
            k -= count[index];

            if (k <= 0)
                return index + minVal;
        }
        
        return 0;
    }
};



// Solved by Quick Select Algorithm (Hoare's Selection Algorithm)

// Time Complexity :- O(n)      Worst Case :- O(n^2)
// Space Complexity :- O(n)

// As we need kth largest element, we will keep nums[i] > pivot in left and nums[i] < pivot in right
// If we need kth smallest element, we will keep nums[i] < pivot in left and nums[i] > pivot in right

class Solution {
public:

    int quickSelect (vector<int> &nums, int k)
    {
        int n = nums.size();
        int pivot = nums[rand() % n];

        vector<int> left, mid, right;

        for (auto &it : nums)
        {
            if (it > pivot)
                left.emplace_back(it);

            else if (it < pivot)
                right.emplace_back(it);

            else
                mid.emplace_back(it);
        }

        if (left.size() >= k)
            return quickSelect (left, k);

        else if (left.size() + mid.size() < k)
        {
            k -= (left.size() + mid.size());
            return quickSelect (right, k);
        }

        return pivot;
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        return quickSelect (nums, k);
    }
};



// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:

    int partition(vector<int> &nums, int left, int right)
    {
        int pivot = nums[left];
        int i = left + 1, j = right;

        while (i <= j)
        {
            if (nums[i] < pivot && nums[j] > pivot)
            {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }

            else if (nums[i] >= pivot)
                i++;
                
            else if (nums[j] <= pivot)
                j--;
        }

        swap(nums[left], nums[j]);

        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int pivotIndex = partition(nums, left, right);

            if (pivotIndex == k - 1)
                return nums[pivotIndex];

            else if (pivotIndex > k - 1)
                right = pivotIndex - 1;
                
            else
                left = pivotIndex + 1;
        }
        
        return 0;
    }
};