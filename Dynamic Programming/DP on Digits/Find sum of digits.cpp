// Reference Link :- https://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/

// Solved by Recursion + Math
// Time Complexity :- O(log10(n))
// Space Complexity :- O(log10(n))

#include <bits/stdc++.h>
using namespace std;

int finddigitsum (int n, vector<int> &radix)
{
    if (n < 10)
        return n * (n + 1)/2;
        
    int d = log10(n);
    int p = pow(10, d);
    int msd = n/p;
    
    return msd * radix[d] + (msd * (msd - 1)/2) * p + msd * (1 + n % p) + finddigitsum(n % p, radix);
}

int main()
{
    int n;
    cin >> n;
    
    int d = log10(n);
    vector<int> radix (d + 1);
    radix[0] = 0, radix[1] = 45;
    
    for (int i = 2; i <= d; i++)
    {
        radix[i] = radix[i - 1] * 10 + 45 * pow(10, i - 1);
    }
    
    cout << finddigitsum (n, radix);
    
    return 0;
}