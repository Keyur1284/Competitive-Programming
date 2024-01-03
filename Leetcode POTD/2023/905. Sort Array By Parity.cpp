// Problem Link :- https://leetcode.com/problems/sort-array-by-parity/

// Solved by two pointer approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> sorted = nums;
        int left = 0, right = n - 1;

        while (left < right)
        {
            if (sorted[left] % 2 == 1 && sorted[right] % 2 == 0)
                swap(sorted[left++], sorted[right--]);

            else if (sorted[left] % 2 == 0 && sorted[right] % 2 == 0)
                left++;

            else if (sorted[left] % 2 == 1 && sorted[right] % 2 == 1)
                right--;

            else if (sorted[left] % 2 == 0 && sorted[right] % 2 == 1)
                left++, right--;
        }

        return sorted;
    }
};



// Solved by using comparator
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return a % 2 < b % 2;
        });

        return nums;
    }
};