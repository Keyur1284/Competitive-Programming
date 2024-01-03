// Problem Link :- https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

// Solved by Sorting based on arrival time
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
       
        int n = dist.size();
        vector<float> arrival;

        for (int i = 0; i < n; i++) 
        {
            arrival.emplace_back((float) dist[i] / speed[i]);
        }
        
        sort(arrival.begin(), arrival.end());
        int ans = 0;
        
        for (int i = 0; i < arrival.size(); i++) 
        {
            if (arrival[i] <= i)
                break;
            
            ans++;
        }
        
        return ans;
    }
};



// Solved using min heap
// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        int n = dist.size();
        priority_queue<float, vector<float>, greater<float>> pq;
        
        for (int i = 0; i < n; i++) 
        {
            pq.emplace((float) dist[i] / speed[i]);
        }

        int ans = 0;

        while (!pq.empty()) 
        {
            if (pq.top() <= ans)
                break;
            
            ans++;
            pq.pop();
        }
        
        return ans;
    }
};