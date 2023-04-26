// Problem Link :- https://leetcode.com/problems/add-digits/

// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int addDigits(int num) {
        
        int sum = 0;
        
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
            
            if(num == 0 && sum > 9)
            {
                num = sum;
                sum = 0;
            }
        }
        
        return sum;
    }
};

class Solution {
public:
    int addDigits(int num) {
    
        while (num >= 10)
        {
            int sum = 0;
            int temp = num;

            while (temp)
            {
                sum += temp % 10;
                temp /= 10;
            }

            num = sum;
        }

        return num;
    }
};

// Time Complexity :- O(1)
// Space Complexity :- O(1) 

class Solution {
public:
    int addDigits(int num) {
    
        if (num == 0)
            return 0;

        if (num % 9 == 0)
            return 9;

        return num % 9;
    }
};