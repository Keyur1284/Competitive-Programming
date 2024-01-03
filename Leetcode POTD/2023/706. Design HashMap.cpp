// Problem Link :- https://leetcode.com/problems/design-hashmap/

// Solved using vector
// Time Complexity :- O(1)
// Space Complexity :- O(1e6)

class MyHashMap {
public:

    vector<int> map;

    MyHashMap() {
        
        map.assign(1e6 + 1, -1);
    }
    
    void put(int key, int value) {
        
        map[key] = value;
    }
    
    int get(int key) {
        
        return map[key];
    }
    
    void remove(int key) {
        
        map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */