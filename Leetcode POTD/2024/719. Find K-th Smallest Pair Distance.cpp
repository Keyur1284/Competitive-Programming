// Problem Link :- https://leetcode.com/problems/find-k-th-smallest-pair-distance/

// Solved by Bucket Sort (Brute Force Approach)
// Time Complexity :- O(n^2 + max(nums))
// Space Complexity :- O(max(nums))

class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {

        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());

        vector<int> bucket(maxEle + 1, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(nums[i] - nums[j]);
                bucket[dist]++;
            }
        }

        for (int dist = 0; dist <= maxEle; dist++)
        {
            k -= bucket[dist];

            if (k <= 0)
                return dist;
        }

        return -1;
    }
};



// Solved by DP + Binary Search
// Time Complexity :- O(nlogn + nlog(max(nums)))
// Space Complexity :- O(n + max(nums))

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxElement = nums[n - 1];
        int maxPossibleDistance = maxElement * 2;
        vector<int> prefixCount(maxPossibleDistance, 0);
        unordered_map<int, int> valueCount;

        for (int value = 0, index = 0; value < maxPossibleDistance; value++) 
        {
            while (index < n && nums[index] <= value)
                index++;
            
            prefixCount[value] = index;
        }

        for (int i = 0; i < n; i++)
            valueCount[nums[i]]++;

        int low = 0, high = maxElement, ans = 0;
        
        while (low <= high) 
        {
            int mid = (low + high) >> 1;
            int count = countPairs(nums, prefixCount, valueCount, mid);

            if (count >= k) 
            {
                ans = mid;
                high = mid - 1;
            } 

            else 
                low = mid + 1;
        }

        return ans;
    }

private:
    int countPairs(vector<int>& nums, vector<int>& prefixCount, unordered_map<int, int>& valueCount, int maxDistance) {
        
        int count = 0, n = nums.size();

        for (int index = 0; index < n; index++)
        {
            int currentValue = nums[index];
            int valueCountForCurrent = valueCount[currentValue];
            int pairsWithLargerValues = prefixCount[currentValue + maxDistance] - prefixCount[currentValue];
            int pairsWithSameValues = valueCountForCurrent * (valueCountForCurrent - 1) / 2;

            count += pairsWithLargerValues * valueCountForCurrent + pairsWithSameValues;

            while (index + 1 < n && nums[index] == nums[index + 1])
                index++;
        }

        return count;
    }
};



// Solved by Binary Search + Sliding Window
// Time Complexity :- O(nlogn + nlog(max(nums)))
// Space Complexity :- O(logn)

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int low = 0, high = nums[n - 1] - nums[0], ans = 0;

        while (low <= high) 
        {
            int mid = (low + high) >> 1;
            int count = countPairsWithMaxDistance(nums, mid);

            if (count >= k) 
            {
                ans = mid;
                high = mid - 1;
            } 
            
            else
                low = mid + 1;
        }

        return ans;
    }

private:

    int countPairsWithMaxDistance(vector<int>& nums, int maxDistance) {
        
        int count = 0, n = nums.size();

        for (int right = 0, left = 0; right < n; right++) 
        {
            while (nums[right] - nums[left] > maxDistance)
                left++;

            count += (right - left + 1) - 1;
        }
        
        return count;
    }
};