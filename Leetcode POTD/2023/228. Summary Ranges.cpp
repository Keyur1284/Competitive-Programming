// Problem Link :- https://leetcode.com/problems/summary-ranges/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int n = nums.size();
        vector<string> range;

        if (n == 0)
            return range;

        string start = to_string(nums[0]), end = start;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - 1 == nums[i - 1])
                end = to_string (nums[i]);
            
            else
            {
                if (start == end)
                    range.emplace_back(start);

                else
                    range.emplace_back(start + "->" + end);

                start = to_string (nums[i]);
                end = start;
            }
        }

        if (start == end)
            range.emplace_back(start);

        else
            range.emplace_back(start + "->" + end);

        return range;
    }
};



class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        int n = nums.size();
        vector<string> range;

        for (int i = 0; i < n; i++)
        {
            int start = nums[i];

            while (i + 1 < n && nums[i] + 1 == nums[i + 1])
                i++;

            if (start == nums[i])
                range.emplace_back(to_string(start));

            else
                range.emplace_back(to_string(start) + "->" + to_string(nums[i]));
        }

        return range;
    }
};