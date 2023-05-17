//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        
        int x = 1, y = 1;
        int left = 1, right = 1, up = 1, down = 1;
        
        for (auto &c : s)
        {
            if (c == 'L')
                left = min(left, --y);  
                
            else if (c == 'R')
                right = max(right, ++y);
                
            else if (c == 'D')
                down = min(down, --x);
                
            else
                up = max(up, ++x);
        }
        
            
        return (right - left <= m - 1 && up - down <= n - 1)? 1 : 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends