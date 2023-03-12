// Problem Link :- https://www.codingninjas.com/codestudio/problems/rotate-array_1230543

// Time Complexity :- O(n)
// Space Complexity :- O(n)

#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<int> vec(n);

    for (auto &it : vec)
        cin >> it;

    int k;
    cin >> k;

    reverse(vec.begin(), vec.end());
    reverse(vec.begin(), vec.begin() + n - k);
    reverse(vec.begin() + n - k, vec.end());

    for (auto &it : vec)
        cout << it << " ";

    return 0;
}


#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<int> vec(n);

    for (auto &it : vec)
        cin >> it;

    vector<int> vec2(n);

    int k;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        vec2[(i + n - k) % n] = vec[i];
    }

    for (auto &it : vec2)
        cout << it << " ";

    return 0;
}
