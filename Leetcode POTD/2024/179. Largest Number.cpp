// Problem Link :- https://leetcode.com/problems/largest-number/

// Solved by Sorting with Custom Comparator
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:

    static bool comp(const string &a, const string &b)
    {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        
        int n = nums.size();
        vector<string> numStrings(n);

        for (int i = 0; i < n; i++)
        {
            numStrings[i] = to_string(nums[i]);
        }

        sort(numStrings.begin(), numStrings.end(), comp);

        if (numStrings[0] == "0")
            return "0";

        string largestNum;

        for (auto &numStr : numStrings)
            largestNum += numStr;

        return largestNum;
    }
};