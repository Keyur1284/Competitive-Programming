// Problem Link :- https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

// Time Complexity :- (100000 * N)
// Space Complexity :- (100000 * N)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {

        int MOD = 100000;
        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> BFS;

        BFS.emplace(start, 0);
        dist[start] = 0;

        while (!BFS.empty())
        {
            auto node = BFS.front();
            int num = node.first;
            int steps = node.second;
            BFS.pop();

            for (auto &it : arr)
            {
                int temp = (it * num) % MOD;

                if (steps + 1 < dist[temp])
                {
                    dist[temp] = steps + 1;

                    if (temp == end)
                        return dist[temp];

                    BFS.emplace(temp, dist[temp]);
                }
            }
        }

        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        int MOD = 100000;
        vector<int> dist(100000, INT_MAX);
        queue<int> BFS;
        
        BFS.emplace(start);
        dist[start] = 0;
        
        while (!BFS.empty())
        {
            int num = BFS.front();
            BFS.pop();
            
            for (auto &it : arr)
            {
                int temp = (it * num) % MOD;
                
                if (dist[temp] == INT_MAX)
                {
                    dist[temp] = dist[num] + 1;
                    
                    if (temp == end)
                        return dist[temp];
                    
                    BFS.emplace(temp);
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends