// Reference Link :- https://www.geeksforgeeks.org/count-numbers-from-1-to-n-that-have-4-as-a-a-digit/

// Solved by Recursion + Math
// Time Complexity :- O(log10(n))
// Space Complexity :- O(log10(n))

#include <bits/stdc++.h>
using namespace std;

int finddigitshavingx (int n, int x, vector<int> &radix)
{
    if (n < x)
        return 0;
        
    int d = log10(n);
    int p = pow(10, d);
    int msd = n/p;
    
    if (msd == x)
        return msd * radix[d] + n % p + 1;
        
    else if (msd > x)
        return (msd - 1) * radix[d] + p + finddigitshavingx(n % p, x, radix);
        
    else
        return msd * radix[d] + finddigitshavingx(n % p, x, radix);
}

int main()
{
    int n, x;
    cin >> n >> x;
    
    int d = log10(n);
    
    vector<int> radix(d + 1);
    radix[0] = 0, radix[1] = 1;
    
    for (int i = 2; i <= d; i++)
    {
        radix[i] = radix[i - 1] * 9 + pow(10, i - 1);
    }
    
    cout << finddigitshavingx(n, x, radix);

    return 0;
}