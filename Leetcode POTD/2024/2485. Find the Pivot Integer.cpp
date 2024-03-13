// Problem Link :- https://leetcode.com/problems/find-the-pivot-integer/

// Solved by Math
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int pivotInteger(int n) {
        
        int totalSum = n * (n + 1)/2;

        for (int pivot = 1; pivot <= n; pivot++)
        {
            int pivotSum = pivot * (pivot + 1)/2;
            int remSum = totalSum - pivotSum + pivot;

            if (pivotSum == remSum)
                return pivot;
        }

        return -1;
    }
};



// Solved by two pointers
// Time Complexity :- O(n)
// Space Complexity :- O(1) 

class Solution {
public:
    int pivotInteger(int n) {
        
        int totalSum = n * (n + 1)/2;
        int leftSum = 0;
        int rightSum = totalSum;
        
        for (int pivot = 1; pivot <= n; pivot++)
        {
            leftSum += pivot;
            
            if (leftSum == rightSum)
                return pivot;
            
            rightSum -= pivot;
        }

        return -1;
    }
};



class Solution {
public:
    int pivotInteger(int n) {
        
        int leftValue = 1, rightValue = n;
        int sumLeft = leftValue, sumRight = rightValue;

        if (n == 1) 
            return n;
        
        while (leftValue < rightValue) 
        {
            if (sumLeft < sumRight) 
                sumLeft += ++leftValue;

            else 
                sumRight += --rightValue;

            if (sumLeft == sumRight && leftValue + 1 == rightValue - 1) 
                return leftValue + 1;
        }

        return -1;
    }
};



// Solved by Binary Search
// Time Complexity :- O(logn)
// Space Complexity :- O(1)

class Solution {
public:
    int pivotInteger(int n) {
        
        int left = 1, right = n;
        
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            int pivotSum = mid * (mid + 1)/2;
            int remSum = n * (n + 1)/2 - pivotSum + mid;
            
            if (pivotSum == remSum)
                return mid;
            
            else if (pivotSum < remSum)
                left = mid + 1;
            
            else
                right = mid - 1;
        }    
    }
};



class Solution {
public:
    int pivotInteger(int n) {

        int left = 1, right = n;
        int totalSum = n * (n + 1) / 2;

        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (mid * mid == totalSum)
                return mid;

            else if (mid * mid < totalSum)
                left = mid + 1;

            else
                right = mid - 1;
        }

        return -1;
    }
};



// Solved by Pre-computation
// Time Complexity :- O(1000)
// Space Complexity :- O(1000)

const int maxValue = 1000;
int precompute[maxValue + 1] = {0};

class Solution {
public:
    int pivotInteger(int n) {

        if (precompute[1] == 0) 
        {
            for (int i = 1, j = 1; i <= maxValue; ++i) 
            {
                int sum = i * (i + 1) / 2;


                while (j * j < sum)
                    ++j;

                precompute[i] = j * j == sum ? j : -1;
            }
        }

        return precompute[n];
    }
};



// Solved by sqrt function
// Time Complexity :- O(1)
// Space Complexity :- O(1)

class Solution {
public:
    int pivotInteger(int n) {

        const int sum = n * (n + 1) / 2;
        const int pivot = sqrt(sum);

        return pivot * pivot == sum ? pivot : -1;
    }
};