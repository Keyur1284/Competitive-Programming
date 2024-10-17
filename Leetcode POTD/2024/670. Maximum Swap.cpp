// Problem Link :- https://leetcode.com/problems/maximum-swap/

// Solved by Brute Force Approach
// Time Complexity :- O(n^2)
// Space Complexity :- O(n)

class Solution {
public:
    int maximumSwap(int num) {

        string numStr = to_string(num);
        int n = numStr.size();
        int maxNum = num;

        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                swap(numStr[i], numStr[j]);
                maxNum = max(maxNum, stoi(numStr));
                swap(numStr[i], numStr[j]);
            }
        }

        return maxNum;
    }
};



// Solved by Greedy Approach
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int maximumSwap(int num) {
        
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> maxRightIndex(n);
        maxRightIndex[n - 1] = n - 1;
        
        for (int i = n - 2; i >= 0; --i) 
        {
            maxRightIndex[i] = (numStr[i] > numStr[maxRightIndex[i + 1]]) ? i : maxRightIndex[i + 1];
        }

        for (int i = 0; i < n; ++i) 
        {
            if (numStr[i] < numStr[maxRightIndex[i]]) 
            {
                swap(numStr[i], numStr[maxRightIndex[i]]);
                return stoi(numStr);
            }
        }

        return num;
    }
};



class Solution {
public:
    int maximumSwap(int num) {
        
        string numStr = to_string(num);
        int n = numStr.size();
        vector<int> lastSeen(10, -1);

        for (int i = 0; i < n; ++i) 
        {
            lastSeen[numStr[i] - '0'] = i;
        }
        
        for (int i = 0; i < n; i++) 
        {
            for (int d = 9; d > numStr[i] - '0'; d--) 
            {
                if (lastSeen[d] > i) 
                {
                    swap(numStr[i], numStr[lastSeen[d]]);
                    return stoi(numStr);
                }
            }
        }

        return num;
    }
};



class Solution {
public:
    int maximumSwap(int num) {
        
        string numStr = to_string(num);
        int n = numStr.size();
        int maxDigitIndex = -1, swapIdx1 = -1, swapIdx2 = -1;

        for (int i = n - 1; i >= 0; --i) 
        {
            if (maxDigitIndex == -1 || numStr[i] > numStr[maxDigitIndex])
                maxDigitIndex = i;
            
            else if (numStr[i] < numStr[maxDigitIndex]) 
            {
                swapIdx1 = i;
                swapIdx2 = maxDigitIndex;
            }
        }

        if (swapIdx1 != -1 && swapIdx2 != -1)
            swap(numStr[swapIdx1], numStr[swapIdx2]);

        return stoi(numStr);
    }
};