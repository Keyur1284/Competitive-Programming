// Problem Link :- https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

// Solved by Sliding Window
// Time Complexity :- O(n)
// Space Complexity :- O(1) 

class Solution {
public:

    int slidingWindow (string &answerKey, int k, char val)
    {
        int n = answerKey.length(), maxLen = 0, flip = 0;

        for (int start = 0, end = 0; end < n; end++)
        {
            flip += (answerKey[end] == val);

            while (flip > k)
            {
                flip -= (answerKey[start++] == val);
            }

            int len = end - start + 1;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int trueLen = slidingWindow (answerKey, k, 'T');
        int falseLen = slidingWindow (answerKey, k, 'F');

        return max(trueLen, falseLen);
    }
};



class Solution {
public:

    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int n = answerKey.length();
        int trueLen = 0, falseLen = 0, maxLen = 0;

        for (int start = 0, end = 0; end < n; end++)
        {
            (answerKey[end] == 'T') ? trueLen++ : falseLen++;

            while (min(trueLen, falseLen) > k)
            {
                (answerKey[start++] == 'T') ? trueLen-- : falseLen--;
            }

            int len = trueLen + falseLen;
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};



// Solved by Binary Search + Sliding Window
// Time Complexity :- O(nlogn)
// Space Complexity :- O(1)

class Solution {
public:

    bool isValid (int mid, string &answerKey, int k)
    {
        int trueLen = 0, falseLen = 0, n = answerKey.length();

        for (int i = 0; i < mid; i++)
        {
            (answerKey[i] == 'T') ? trueLen++ : falseLen++;
        }

        if (min(trueLen, falseLen) <= k)
            return true;

        for (int i = mid; i < n; i++)
        {
            (answerKey[i] == 'T') ? trueLen++ : falseLen++;
            (answerKey[i - mid] == 'T') ? trueLen-- : falseLen--;

            if (min(trueLen, falseLen) <= k)
                return true;
        }

        return false;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int n = answerKey.length();
        int low = k, high = n, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (isValid(mid, answerKey, k))
                low = mid + 1;

            else
                high = mid - 1;
        }

        return high;
    }
};