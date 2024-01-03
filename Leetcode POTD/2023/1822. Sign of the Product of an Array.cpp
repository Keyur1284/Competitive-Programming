// Problem Link :- https://leetcode.com/problems/sign-of-the-product-of-an-array/

// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int sign = 1;

        for (auto &it : nums)
        {
            if (it == 0)
                return 0;

            if (it < 0)
                sign *= -1;
        }

        return sign;
    }
};


class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int neg = 0;

        for (auto &it : nums)
        {
            if (it == 0)
                return 0;

            if (it < 0)
                neg++;
        }

        return (neg % 2) ? -1 : 1;
    }
};