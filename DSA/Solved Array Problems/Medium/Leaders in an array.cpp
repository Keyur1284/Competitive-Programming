// Problem Link :- https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

// Time Complexity :- O(n)
// Space Complexity :- O(n)

//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        
        vector<int> maxi(n), ans;
        
        maxi[n - 1] = a[n - 1];
        ans.emplace_back(maxi[n - 1]);
        
        for (int i = n - 2; i >= 0; i--)
            maxi[i] = max(maxi[i + 1], a[i]);
            
        for (int i = n - 2; i >= 0; i--)
        {
            if (maxi[i] == a[i])
                ans.emplace_back(maxi[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends


//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        
        vector<int> ans;
        
        int maxi = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] >= maxi)
                ans.emplace_back(a[i]);
                
            maxi = max(maxi, a[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends