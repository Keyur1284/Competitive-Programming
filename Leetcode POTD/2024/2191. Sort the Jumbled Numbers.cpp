// Problem Link :- https://leetcode.com/problems/sort-the-jumbled-numbers/

// Solved by Custom Sort
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    int getNumVal(vector<int> &mapping, int num)
    {
        int val = 0;
        string numString = to_string(num);

        for (auto &it : numString)
        {
            val = val * 10 + mapping[it - '0'];
        }

        return val;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        unordered_map<int, int> numToVal;

        for (auto &it : nums)
            numToVal[it] = getNumVal(mapping, it);

        sort(nums.begin(), nums.end(), [&](int num1, int num2){
            return numToVal[num1] < numToVal[num2];
        });

        return nums;
    }
};



class Solution {
public:

    int getNumVal(vector<int> &mapping, int num)
    {
        if (num == 0)
            return mapping[0];

        int val = 0, radix = 1;

        while(num)
        {
            int digit = num % 10;
            val += mapping[digit] * radix;
            radix *= 10;
            num /= 10;
        }

        return val;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        unordered_map<int, int> numToVal;

        for (auto &it : nums)
            numToVal[it] = getNumVal(mapping, it);

        sort(nums.begin(), nums.end(), [&](int num1, int num2){
            return numToVal[num1] < numToVal[num2];
        });

        return nums;
    }
};



class Solution {
public:

    int getNumVal(vector<int> &mapping, int num)
    {
        if (num == 0)
            return mapping[0];

        int val = 0, radix = 1;

        while(num)
        {
            int digit = num % 10;
            val += mapping[digit] * radix;
            radix *= 10;
            num /= 10;
        }

        return val;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int, int>> numValPairs;

        for (int i = 0; i < n; i++)
        {
            int val = getNumVal(mapping, nums[i]);
            numValPairs.emplace_back(val, i);
        }

        sort(numValPairs.begin(), numValPairs.end());

        vector<int> sorted;

        for (auto &[val, index] : numValPairs)
            sorted.emplace_back(nums[index]);

        return sorted;
    }
};