// Problem Link :- https://leetcode.com/problems/sequential-digits/

// Solved by Recursive Approach
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:

    vector<int> nums;

    vector<int> sequentialDigits(int low, int high) {
        
        function<void(int, int)> solve = [&](int digit, int num) -> void
        {
            if (low <= num && num <= high)
                nums.emplace_back(num);

            if (num > high || digit > 9)
                return;

            solve(digit + 1, num * 10 + digit);
        };

        for (int digit = 1; digit <= 9; digit++)
            solve(digit, 0);

        sort(nums.begin(), nums.end());
        return nums;
    }
};



// Solved by Iterative Approach
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
  
        vector<int> nums;
  
        for (int digit = 1; digit <= 9; digit++) 
        {                
            for (int num = digit, j = digit + 1; j <= 9; j++) 
            {
                num = num * 10 + j;
            
                if (num >= low && num <= high) 
                    nums.emplace_back(num);

                else if (num > high)
                    break;
            }
        }

        sort(nums.begin(), nums.end());
        return nums;
    }
};



class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> nums;
        queue<int> BFS;

        for (int i = 1; i <= 9; i++)
            BFS.emplace(i);

        while (!BFS.empty())
        {
            int num = BFS.front();
            BFS.pop();

            if (num >= low && num <= high)
                nums.emplace_back(num);

            if (num > high)
                continue;

            int lastDigit = num % 10;

            if (lastDigit < 9)
                BFS.emplace(num * 10 + lastDigit + 1);
        }

        return nums;
    }    
};