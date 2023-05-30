// Problem Link :- https://leetcode.com/problems/design-hashset/

// Time Complexity :- O(N)
// Space Complexity :- O(N)

// Solved using Vector

class MyHashSet {
public:

    vector<bool> hash;

    MyHashSet() {
        
        hash.resize(1e6 + 1, false);
    }
    
    void add(int key) {
        
        hash[key] = true;
    }
    
    void remove(int key) {
        
        hash[key] = false;
    }
    
    bool contains(int key) {
        
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */



// Solved using unordered_map

class MyHashSet {
public:

    unordered_map<int, int> mp;

    MyHashSet() {
        
        mp.clear();
    }
    
    void add(int key) {
        
        mp[key]++;
    }
    
    void remove(int key) {
        
        if (mp.find(key) != mp.end())
            mp.erase(key);
    }
    
    bool contains(int key) {
        
        return (mp.find(key) != mp.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */