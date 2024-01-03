// Problem Link :- https://leetcode.com/problems/kth-largest-element-in-a-stream/

// Time Complexity :- O((N + M)*logK)
// Space Complexity :- O(K)

class KthLargest {
public:

    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        
        K = k;
        
        for (auto &it : nums)
        {
            pq.emplace(it);

            if (pq.size() > K)
                pq.pop();
        }
    }
    
    int add(int val) {
        
        pq.emplace(val);

        if (pq.size() > K)
                pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */


class KthLargest {
public:

    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        
        K = k;
        
        for (auto &it : nums)
        {
            add(it);
        }
    }
    
    int add(int val) {
        
        pq.emplace(val);

        if (pq.size() > K)
                pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */