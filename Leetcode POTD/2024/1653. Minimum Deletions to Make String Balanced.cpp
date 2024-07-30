// Problem Link :- https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

// Solved by counting prefix 'b' and suffix 'a' 
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        vector<int> suffA(n, 0), prefB(n, 0);
        int aCount = 0, bCount = 0;

        for (int i = 0; i < n; i++) 
        {
            prefB[i] = bCount;
            bCount += (s[i] == 'b');
        }

        for (int i = n - 1; i >= 0; i--) 
        {
            suffA[i] = aCount;
            aCount += (s[i] == 'a');
        }

        int minDels = n;

        for (int i = 0; i < n; i++) 
        {
            minDels = min(minDels, suffA[i] + prefB[i]);
        }

        return minDels;
    }
};



// Solved in O(1) space complexity
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        int aCount = count(s.begin(), s.end(), 'a'), bCount = 0;
        int minDels = n;

        for (int i = 0; i < n; i++) 
        {
            aCount -= (s[i] == 'a');
            minDels = min(minDels, aCount + bCount);
            bCount += (s[i] == 'b');
        }

        return minDels;
    }
};



// Solved using Stack
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        stack<char> charStack;
        int deleteCount = 0;

        for (int i = 0; i < n; i++) 
        {
            if (!charStack.empty() && charStack.top() == 'b' && s[i] == 'a') 
            {
                charStack.pop();
                deleteCount++;
            } 
            
            else
                charStack.emplace(s[i]);
        }

        return deleteCount;
    }
};



// Solved by Tabulation Method
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        vector<int> dp(n + 1, 0);
        int bCount = 0;

        for (int i = 0; i < n; i++) 
        {
            if (s[i] == 'b') 
            {
                dp[i + 1] = dp[i];
                bCount++;
            } 

            else
                dp[i + 1] = min(dp[i] + 1, bCount);
        }

        return dp[n];
    }
};



// Solved by Tabulation Method (Space Optimized)
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        int minDels = 0, bCount = 0;

        for (int i = 0; i < n; i++) 
        {
            if (s[i] == 'b')
                bCount++;

            else
                minDels = min(minDels + 1, bCount);
        }

        return minDels;
    }
};