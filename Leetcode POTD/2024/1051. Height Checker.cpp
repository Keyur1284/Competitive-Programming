// Problem Link :- https://leetcode.com/problems/height-checker/

// Solved by Sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {

        int n = heights.size(), count = 0;
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());

        for (int i = 0; i < n; i++)
        {
            count += (expected[i] != heights[i]);
        }

        return count;
    }
};



// Solved by Counting Sort
// Time Complexity :- O(n + k)  n = size of heights
// Space Complexity :- O(k)  k = range of heights

class Solution
{

    void countingSort(vector<int> &arr)
    {

        unordered_map<int, int> counts;

        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        for (auto &val : arr)
            counts[val]++;

        int index = 0;

        for (int val = minVal; val <= maxVal; val++)
        {
            while (counts[val] > 0)
            {
                arr[index] = val;
                index++;
                counts[val]--;
            }
        }
    }

public:
    int heightChecker(vector<int> &heights)
    {

        int n = heights.size(), count = 0;
        vector<int> expected = heights;
        countingSort(expected);

        for (int i = 0; i < n; i++)
        {
            count += (expected[i] != heights[i]);
        }

        return count;
    }
};



// Solved by Radix Sort
// Time Complexity :- O((n + 10) * d)  n = size of heights, d = number of digits in max element
// Space Complexity :- O(n + 10)

class Solution {

    void bucketSort(vector<int>& arr, int placeValue) {
       
        vector<vector<int>> buckets(10);

        for (int &val : arr) 
        {
            int digit = val / placeValue;
            digit = digit % 10;
            buckets[digit].push_back(val);
        }

        int index = 0;
        
        for (int digit = 0; digit < 10; ++digit) 
        {
            for (int &val : buckets[digit]) 
            {
                arr[index++] = val;
            }
        }
    }


    void radixSort(vector<int>& arr) {

        int maxElement = *max_element(arr.begin(), arr.end());
        int maxDigits = 0;
        
        while (maxElement > 0) 
        {
            maxDigits += 1;
            maxElement /= 10;
        }

        int placeValue = 1;
        
        for (int digit = 0; digit < maxDigits; ++digit) 
        {
            bucketSort(arr, placeValue);
            placeValue *= 10;
        }
    }

public:
    int heightChecker(vector<int>& heights) {

        int n = heights.size(), count = 0;
        vector<int> expected = heights;
        radixSort(expected);

        for (int i = 0; i < n; i++)
        {
            count += (expected[i] != heights[i]);
        }

        return count;
    }
};