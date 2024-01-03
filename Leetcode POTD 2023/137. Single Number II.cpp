// Problem Link :- https://leetcode.com/problems/single-number-ii/

// Solved by bit-masking
// Reference Solution :- https://leetcode.com/problems/single-number-ii/solutions/43295/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers/
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int x2 = 0, x1 = 0, mask = 0;

        for (auto &it : nums)
        {
            x2 ^= (x1 & it);
            x1 ^= it;

            mask = ~(x2 & x1);

            x2 &= mask;
            x1 &= mask;            
        }

        return x1;
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ones = 0, twos = 0;

        for (auto &it : nums)
        {
            ones = ((ones ^ it) & ~twos);
            twos = ((twos ^ it) & ~ones);
        }

        return ones;
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;

        for (int bit = 0; bit < 32; bit++)
        {
            int contribute = 0;

            for (auto &it : nums)
            {
                if (it & (1 << bit))
                    contribute++;
            }

            contribute %= 3;

            if (contribute)
                ans |= (contribute << bit);
        }

        return ans;
    }
};