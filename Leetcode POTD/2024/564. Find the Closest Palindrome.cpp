// Problem Link :- https://leetcode.com/problems/find-the-closest-palindrome/

// Solved by Maths
// Time Complexity :- O(n)  n = no of digits in the number
// Space Complexity :- O(n)

class Solution {
public:
    
    long buildPalindrome(long left, bool even) 
    {    
        long res = left;
        
        if (!even) 
            left /= 10;

        while (left) 
        {
            res = res * 10 + left % 10;
            left /= 10;
        }

        return res;
    }

    string nearestPalindromic(string n) {
        
        int len = n.length();
        long firstHalf = stol(n.substr(0, (len + 1)/2));
       
        vector<long> possibilities;
        possibilities.emplace_back(buildPalindrome(firstHalf, len % 2 == 0));
        possibilities.emplace_back(buildPalindrome(firstHalf + 1, len % 2 == 0));
        possibilities.emplace_back(buildPalindrome(firstHalf - 1, len % 2 == 0));
        possibilities.emplace_back((long)pow(10, len - 1) - 1);
        possibilities.emplace_back((long)pow(10, len) + 1);

        long minDiff = LONG_MAX, res = 0, nl = stol(n);
        
        for (auto cand : possibilities) 
        {
            if (cand == nl) 
                continue;
            
            long diff = abs(cand - nl);
            
            if (diff < minDiff) 
            {
                minDiff = abs(cand - nl);
                res = cand;
            } 
            
            else if (diff == minDiff)
                res = min(res, cand);
        }

        return to_string(res);
    }
};



// Solved by Binary Search
// Time Complexity :- O(nlogm)  n = no of digits in the number, m = the number
// Space Complexity :- O(n)

class Solution {
public:

    long long convert(long long num) 
    {
        string s = to_string(num);
        int n = s.length();
        int l = (n - 1) / 2, r = n / 2;
        
        while (l >= 0) 
            s[r++] = s[l--];
     
        return stoll(s);
    }

    long long previousPalindrome(long long num) 
    {    
        long long low = 0, high = num, ans = INT_MIN;
        
        while (low <= high) 
        {
            long long mid = (low + high) >> 1;
            long long palin = convert(mid);
            
            if (palin < num) 
            {
                ans = palin;
                low = mid + 1;
            } 

            else
                high = mid - 1;
        }

        return ans;
    }

    long long nextPalindrome(long long num) 
    {    
        long long low = num, high = 1e18, ans = INT_MIN;
        
        while (low <= high) 
        {
            long long mid = (low + high) >> 1;
            long long palin = convert(mid);
            
            if (palin > num) 
            {
                ans = palin;
                high = mid - 1;
            } 
            
            else
                low = mid + 1;
        }

        return ans;
    }

    string nearestPalindromic(string n) {
        
        int len = n.length();
        long long num = stoll(n);
        long long prev = previousPalindrome(num);
        long long next = nextPalindrome(num);

        return (abs(next - num) < abs(prev - num)) ? to_string(next) : to_string(prev);
    }
};