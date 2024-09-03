// Problem Link :- https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

// Solved by Bruteforce Approach
// Time Complexity :- O(k * n)
// Space Complexity :- O(n)

class Solution {
public:
    int getLucky(string s, int k) {

        string numericString = "";
        
        for (auto &ch : s)
            numericString += to_string(ch - 'a' + 1);

        while (k--) 
        {
            int digitSum = 0;
            
            for (char digit : numericString)
                digitSum += digit - '0';
            
            numericString = to_string(digitSum);
        }

        return stoi(numericString);
    }
};



// Solved by Optimized Approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int getLucky(string s, int k) {

        int currentNumber = 0;
        
        for (auto &ch : s) 
        {
            int position = ch - 'a' + 1;
            
            while (position > 0) 
            {
                currentNumber += position % 10;
                position /= 10;
            }
        }

        for (int i = 1; i < k; i++) 
        {
            int digitSum = 0;

            while (currentNumber > 0) 
            {
                digitSum += currentNumber % 10;
                currentNumber /= 10;
            }
            
            currentNumber = digitSum;
        }

        return currentNumber;
    }
};