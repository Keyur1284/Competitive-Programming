// Problem Link :- https://leetcode.com/problems/lru-cache/

// Solved using list and unordered_map
// Time Complexity :- O(n)
// Space Complexity :- O(capacity)

class LRUCache {
public:

    int maxSize;
    list<pair<int, int>> lp;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

    LRUCache(int capacity) {
        
        maxSize = capacity;
    }
    
    int get(int key) {
        
        if (mp.find(key) == mp.end())
            return -1;

        int val = mp[key]->second;
        lp.erase(mp[key]);
        lp.push_front({key, val});
        mp[key] = lp.begin();

        return val;
        
    }
    
    void put(int key, int value) {
        
        if (mp.find(key) != mp.end())
            lp.erase(mp[key]);

        else if (lp.size() == maxSize)
        {
            mp.erase(lp.back().first);
            lp.pop_back();
        }

        lp.push_front({key, value});
        mp[key] = lp.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */