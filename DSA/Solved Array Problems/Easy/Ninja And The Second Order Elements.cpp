// Problem Link :- https://www.codingninjas.com/codestudio/problems/ninja-and-the-second-order-elements_6581960

int secLargest (vector<int> &a, int n)
{
    int largest = a[0];
    int seclargest = INT_MIN;

    for (auto &it : a)
    {
        if (it > largest)
        {
            seclargest = largest;
            largest = it;
        }

        else if (it > seclargest && it != largest)
            seclargest = it;
    }
    
    return seclargest;
}

int secSmallest (vector<int> &a, int n)
{
    int smallest = a[0];
    int secsmallest = INT_MAX;

    for (auto &it : a)
    {
        if (it < smallest)
        {
            secsmallest = smallest;
            smallest = it;
        }

        else if (it < secsmallest && it != smallest)
            secsmallest = it;
    }
    
    return secsmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    
    vector<int> ans(2);
    
    ans[0] = secLargest(a, n);
    ans[1] = secSmallest(a, n);

    return ans;
}
