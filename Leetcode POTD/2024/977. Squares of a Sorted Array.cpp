// Problem Link :- https://leetcode.com/problems/squares-of-a-sorted-array/

// Solved by squaring and sorting
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> squares;

        for (auto &it : nums)
            squares.emplace_back(it * it);

        sort(squares.begin(), squares.end());

        return squares;
    }
};



// Solved by two pointer approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> squares(n);
        
        int left = 0, right = n - 1, index = n - 1;
        
        while (left <= right) 
        {
            if (abs(nums[left]) > abs(nums[right])) 
            {
                squares[index--] = nums[left] * nums[left];
                left++;
            } 
            
            else 
            {
                squares[index--] = nums[right] * nums[right];
                right--;
            }
        }
        
        return squares;
    }
};



class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size(), negInd = -1, posInd = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < 0)
            {
                negInd = i;
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                posInd = i;
                break;
            }
        }

        vector<int> squares;

        while (negInd >= 0 || (posInd != -1 && posInd < n))
        {
            int neg = 1e9, pos = 1e9;

            if (negInd >= 0)
                neg = nums[negInd] * nums[negInd];

            if (posInd != -1 && posInd < n)
                pos = nums[posInd] * nums[posInd];

            if (neg <= pos)
            {
                squares.emplace_back(neg);
                negInd--;
            }

            else
            {
                squares.emplace_back(pos);
                posInd++;
            }
        }

        return squares;
    }
};