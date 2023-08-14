// Problem Link :- https://practice.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

// Solved by using priority_queue   (TLE on GFG, AC on Coding Ninja)
// Time Complexity :- O(nlogn + klogn)
// Space Complexity :- O(n)

class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int K){
      
        int n = stations.size();
        vector<int> placed(n - 1, 0);
        priority_queue<pair<double, int>> pq;
        
        for (int i = 0; i < n - 1; i++)
        {
            double diff = stations[i + 1] - stations[i];
            pq.emplace(diff, i);
        }
        
        for (int k = 1; k <= K; k++)
        {
            auto it = pq.top();
            pq.pop();
            
            int index = it.second;
            placed[index]++;
            
            double diff = stations[index + 1] - stations[index];
            double newDiff = diff/(placed[index] + 1);
            pq.emplace(newDiff, index);
        }
        
        return pq.top().first;
    }
};



// Solved by Binary Search
// Time Complexity :- O(nlog(maxDiff))
// Space Complexity :- O(1)

class Solution {
  public:
    
    bool check (double mid, vector<int> &stations, int k)
    {
        int n = stations.size();
        
        int count = 0;

        for (int i = 0; i < n - 1; i++) 
        {
            count += (stations[i + 1] - stations[i]) / mid;
            
            if (count > k)
                return false;
        }
        
        return true;
    }
  
    double findSmallestMaxDist(vector<int> &stations, int k){
      
        int n = stations.size();
        double low = 0.0, high = 0.0, mid, ans;
        
        for (int i = 0; i < n - 1; i++) 
        {
            double diff = stations[i + 1] - stations[i];
            high = max(high, diff);
        }
        
        while (high - low > 1e-6)
        {
            mid = (low + high)/2.0;
            
            if (check(mid, stations, k))
            {
                ans = mid;
                high = mid;
            }
            
            else
                low = mid;
        }
        
        return round(high * 100)/100;   // we can return ans also
    }
};