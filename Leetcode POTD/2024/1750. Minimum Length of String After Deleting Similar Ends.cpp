// Problem Link :- https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

// Solved by two pointer approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.length(), left = 0, right = n - 1;

        while (left < right && s[left] == s[right])
        {
            while (left + 1 < right && s[left] == s[left + 1])
                left++;

            while (right - 1 > left && s[right] == s[right - 1])
                right--;

            left++, right--;
        }

        return right - left + 1;
    }
};



class Solution {
public:
    int minimumLength(string s) {
        
        int n = s.length(), left = 0, right = n - 1;

        while (left < right && s[left] == s[right])
        {
            char k = s[left];

            while (left <= right && s[left] == k)
                left++;

            while (right > left && s[right] == k)
                right--;
        }

        return right - left + 1;
    }
};