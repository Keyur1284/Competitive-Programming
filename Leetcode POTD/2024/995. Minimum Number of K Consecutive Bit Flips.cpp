// Problem Link :- https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/

// Solved using vector
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();
        vector<bool> flipped(n, false);
        int validFlipsFromPastWindow = 0, flipCount = 0;

        for (int i = 0; i < n; i++) 
        {
            if (i >= k) 
            {
                validFlipsFromPastWindow ^= flipped[i - k];
            }

            if (validFlipsFromPastWindow == nums[i]) 
            {    
                if (i + k - 1 >= n)
                    return -1;

                validFlipsFromPastWindow ^= 1;
                flipped[i] = true;
                flipCount++;
            }
        }

        return flipCount;
    }
};



// Solved using deque
// Time Complexity :- O(n)
// Space Complexity :- O(k)

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        deque<int> flipQueue;
        int flipped = 0, result = 0;

        for (int i = 0; i < n; i++) 
        {
            if (i >= k) 
            {
                flipped ^= flipQueue.front();
                flipQueue.pop_front();
            }

            if (flipped == nums[i]) 
            {
                if (i + k - 1 >= n)
                    return -1;

                flipQueue.push_back(1);
                flipped ^= 1;
                result++;
            } 
        
            else
                flipQueue.push_back(0);
        }

        return result;
    }
};



// Solved by modifying the input array
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();
        int flipped = 0, flipCount = 0;

        for (int i = 0; i < n; i++) 
        {
            if (i >= k && nums[i - k] == 2) 
                flipped ^= 1;

            if (flipped == nums[i]) 
            {    
                if (i + k - 1 >= n)
                    return -1;

                flipped ^= 1;
                nums[i] = 2;
                flipCount++;
            }
        }

        return flipCount;
    }
};