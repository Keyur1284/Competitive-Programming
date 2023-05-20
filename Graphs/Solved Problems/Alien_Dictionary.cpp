// Problem Link :- https://practice.geeksforgeeks.org/problems/alien-dictionary/1

// Time Complexity :- O(N * L)  N is the number of words ,  L length of the max length word
// Space Complexity :- O(K)

// Solved by TopoSort(BFS)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K], indegree(K, 0);
        
        for (int i = 0; i < N - 1; i++)
        {
            string s = dict[i];
            string t = dict[i + 1];
            
            int len = min(s.size(), t.size());
            
            for (int j = 0; j < len; j++)
            {
                if (s[j] != t[j])
                {
                    adj[s[j] - 'a'].emplace_back(t[j] - 'a');
                    indegree[t[j] - 'a']++;
                    
                    break;
                }
            }
        }
        
        queue<int> q;
        string ans = "";
        
        for (int i = 0; i < K; i++)
        {
            if (indegree[i] == 0)
                q.emplace(i);
        }
            
        while (!q.empty())
        {
            int ascii = q.front();
            q.pop();
            ans += (ascii + 'a');
            
            for (auto &it : adj[ascii])
            {
                indegree[it]--;
                
                if (indegree[it] == 0)
                    q.emplace(it);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends



// Solved by TopoSort(DFS)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    void TopoSortDFS (int letter, vector<bool> &vis, stack<int> &st, vector<int> adj[])
    {
        vis[letter] = true;
        
        for (auto &it : adj[letter])
        {
            if (!vis[it])
                TopoSortDFS (it, vis, st, adj);
        }
        
        st.emplace(letter);
    }
    
    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K], indegree(K, 0);
        
        for (int i = 0; i < N - 1; i++)
        {
            string s = dict[i];
            string t = dict[i + 1];
            
            int len = min(s.size(), t.size());
            
            for (int j = 0; j < len; j++)
            {
                if (s[j] != t[j])
                {
                    adj[s[j] - 'a'].emplace_back(t[j] - 'a');
                    indegree[t[j] - 'a']++;
                    
                    break;
                }
            }
        }
        
        vector<bool> vis (K, false);
        stack<int> st;
        
        for (int i = 0; i < K; i++)
        {
            if (!vis[i])
                TopoSortDFS (i, vis, st, adj);
        }
        
        string ans = "";
        
        while (!st.empty())
        {
            ans += (st.top() + 'a');
            st.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends