// Problem Link :- https://leetcode.com/problems/ugly-number-ii/

// Solved using set
// Time Complexity :- O(nlogm)
// Space Complexity :- O(m)

class Solution {
public:
    int nthUglyNumber(int n) {
        
        long num = 1;
        set<long> st;
        st.emplace(num);

        while (n--)
        {
            num = *st.begin();
            st.erase(num);
            
            st.emplace(2 * num);
            st.emplace(3 * num);
            st.emplace(5 * num);
        }

        return num;
    }
};



// Solved by Dynamic Programming
// Time Complexity :- O(n)
// Space Complexity :- O(n)

class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> ugly(n);
        ugly[0] = 1;
        
        for (int i = 1, p2 = 0, p3 = 0, p5 = 0; i < n; i++)
        {
            int mini = min({2 * ugly[p2], 3 * ugly[p3], 5 * ugly[p5]});
            ugly[i] = mini;

            if (mini == 2 * ugly[p2])
                p2++;

            if (mini == 3 * ugly[p3])
                p3++;

            if (mini == 5 * ugly[p5])
                p5++;
        }

        return ugly[n - 1];
    }
};



// Solved using binary search
// Time Complexity :- O(log2(1e18) * log3(1e18) * log5(1e18))
// Space Complexity :- O(1)

class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<long> pow2 = {1};

        for (int i = 1; i <= 40; i++)
        {
            pow2.emplace_back(pow2.back() << 1);
        }

        long low = 1, high = 1e18, mid, ans;

        while (low <= high)
        {
            mid = (low + high) >> 1;

            int cnt = 0; 
 
            for (long i = 1; i <= mid; i *= 5)
            {
                for (long j = 1; j * i <= mid; j *= 3)
                {
                    cnt += upper_bound(pow2.begin(), pow2.end(), mid / (i * j)) - pow2.begin();
                }
            }

            if (cnt < n)
                low = mid + 1;
        
            else
            {
                high = mid - 1;
                ans = mid;
            }
        }

        return ans;
    }
};