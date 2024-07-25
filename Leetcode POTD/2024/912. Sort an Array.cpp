// Problem Link :- https://leetcode.com/problems/sort-an-array/

// Solved by Heap Sort
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    void heapify (vector<int> &nums, int n, int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;

        if (right < n && nums[right] > nums[largest])
            largest = right;

        if (largest != index)
        {
            swap (nums[index], nums[largest]);
            heapify (nums, n, largest);
        }
    }

    void heapSort (vector<int> &nums, int n)
    {
        for (int i = n/2 - 1; i >= 0; i--)
        {
            heapify (nums, n, i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            swap (nums[0], nums[i]);

            heapify (nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        heapSort (nums, nums.size());
        return nums;
    }
};



// Solved by Merge Sort
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    void merge (int left, int mid, int right, vector <int> &nums)
    {
        int l = left, r = mid + 1, index = 0, size = right - left + 1;
        vector<int> temp (size, 0);

        while (l <= mid && r <= right)
            temp[index++] = (nums[l] < nums[r]) ? nums[l++] : nums[r++];

        while (l <= mid)
            temp[index++] = nums[l++];

        while (r <= right)
            temp[index++] = nums[r++];

        for (int i = 0; i < size; i++)
            nums[left + i] = temp[i];
    }

    void mergeSort (vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int mid = (left + right) >> 1;
            mergeSort (nums, left, mid);
            mergeSort (nums, mid + 1, right);
            merge (left, mid, right, nums);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        mergeSort (nums, 0, nums.size() - 1);
        return nums;
    }
};



// Solved by Quick Sort
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    int partition (vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        int i = low, j = high;

        while (i < j)
        {
            while (i < high && nums[i] <= pivot)
                i++;

            while (j > low && nums[j] > pivot)
                j--;

            if (i < j)
                swap(nums[i], nums[j]);
        }

        swap(nums[low], nums[j]);

        return j;
    }

    void quickSort (vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int pi = partition (nums, low, high);
            quickSort (nums, low, pi - 1);
            quickSort (nums, pi + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {

        quickSort (nums, 0, nums.size() - 1);
        return nums;
    }
};