// Problem Link :- https://leetcode.com/problems/fair-distribution-of-cookies/

// Solved by Back-tracking
// Time Complexity :- O(k^n)
// Space Complexity :- O(n + k)

class Solution {
public:

    int solve (int index, int zeroes, int &n, vector<int> &obtained, vector<int>& cookies, int &k)
    {
        if (n - index < zeroes)
            return INT_MAX;

        if (index == n)
        {
            int unfairness = *max_element(obtained.begin(), obtained.end());
            return unfairness;
        }

        int minUnfair = INT_MAX;

        for (int i = 0; i < k; i++)
        {
            zeroes -= (obtained[i] == 0);
            obtained[i] += cookies[index];

            int unfairness = solve (index + 1, zeroes, n, obtained, cookies, k);
            minUnfair = min (minUnfair, unfairness);

            obtained[i] -= cookies[index];
            zeroes += (obtained[i] == 0);
        }

        return minUnfair;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        
        int n = cookies.size(), zeroes = k;
        vector<int> obtained(k, 0);

        return solve (0, zeroes, n, obtained, cookies, k);
    }
};



// Solved by generating all permutations + Binary Search
// Time Complexity :- O(n * logn + n! * n * log(sum))
// Space Complexity :- O(1)

class Solution {
public:

    bool check (int mid, vector<int>& cookies, int &k)
    {
        int students = 1;
        int cookie = 0;

        for (auto &it : cookies)
        {
            if (it > mid)
                return false;

            if (cookie + it > mid)
            {
                students++;
                cookie = it;
            }

            else
                cookie += it;

            if (students > k)
                return false;
        }

        return true;
    }

    int binarySearch (int &sum, vector<int>& cookies, int &k)
    {
        int low = 0, high = sum, mid;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (check(mid, cookies, k))
                high = mid - 1;
            
            else
                low = mid + 1;
        }

        return low;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        
        sort (cookies.begin(), cookies.end());
        int sum = accumulate (cookies.begin(), cookies.end(), 0);
        int minUnfair = INT_MAX;

        do 
        {
            int unfairness = binarySearch (sum, cookies, k);
            minUnfair = min (minUnfair, unfairness);

        } while (next_permutation(cookies.begin(), cookies.end()));

        return minUnfair;
    }
};