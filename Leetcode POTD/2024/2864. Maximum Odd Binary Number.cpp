// Problem Link :- https://leetcode.com/problems/maximum-odd-binary-number/

// Solved by traversing 
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int n = s.length(), count0 = 0, count1 = 0;

        for (auto &it : s)
            count0 += (it == '0');

        count1 = n - count0;

        string ans = string(count1 - 1, '1') + string(count0, '0') + '1';
        return ans;
    }
};



// Solved by two pointer approach
// Time Complexity :- O(n)
// Space Complexity :- O(1)

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        
        int n = s.length(), left = 0, right = n - 1;

        while (left <= right)
        {
            if (s[left] == '1')
                left++;

            else if (s[right] == '0')
                right--;

            else if (s[left] == '0' && s[right] == '1')
                swap(s[left++], s[right--]);
        }

        s[left - 1] = '0';
        s[n - 1] = '1';

        return s;
    }
};