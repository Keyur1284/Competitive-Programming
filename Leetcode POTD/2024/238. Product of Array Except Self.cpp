// Problem Link :- https://leetcode.com/problems/product-of-array-except-self/

// Solved using prefix and suffix product vector
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> leftProd(n), rightProd(n), prod(nums.size());
        leftProd[0] = rightProd[n - 1] = 1;

        for (int i = 1; i < n; i++)
            leftProd[i] = leftProd[i - 1] * nums[i - 1];
        
        for(int i = n - 2; i >= 0; i--)
            rightProd[i] = rightProd[i + 1] * nums[i + 1];

        for(int i = 0; i < n; i++)
            prod[i] = leftProd[i] * rightProd[i];
        
        return prod;
    }
};



// Solved using O(1) space
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prod(n, 1);
        int leftProd = 1, rightProd = 1;
        
        for(int i = 0; i < n; i++)
        {
            prod[i] *= leftProd;
            leftProd *= nums[i];
            
            prod[n - i - 1] *= rightProd;
            rightProd *= nums[n - i - 1];
        }
        
        return prod;
    }
};



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod = 1, zero = 0, n = nums.size();

        for (auto &it : nums)
        {
            if (it != 0)
                prod *= it;
            
            zero += (it == 0);
        }

        vector<int> product (n, 0);

        if (zero > 1)
            return product;

        for (int i = 0; i < n; i++)
        {
            if (zero)
            {
                if (nums[i] != 0)
                    continue;

                product[i] = prod;
            }

            else
                product[i] = prod/nums[i];
        }

        return product;
    }
};