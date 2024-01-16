// Problem Link :- https://leetcode.com/problems/insert-delete-getrandom-o1/

// Solved using unordered_map and vector
// Time Complexity :- O(1)
// Space Complexity :- O(n)

class RandomizedSet {
public:

    unordered_map<int, int> mp;
    vector<int> vec;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if (mp.find(val) != mp.end())
            return false;

        mp[val] = vec.size();
        vec.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
    
        if(mp.find(val) == mp.end())
            return false;

        int index = mp[val], n = vec.size();
        
        mp[vec[n - 1]] = index;
        swap(vec[index], vec[n - 1]);
        vec.pop_back();
        
        mp.erase(val);
        return true;
    }

    int getRandom() {
    
        int index = rand() % vec.size();
        return vec[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */



// Solved using unordered_set
// Time Complexity :- O(n) (for getRandom() function)
// Space Complexity :- O(n)

class RandomizedSet {
public:

    unordered_set<int> st;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if (st.find(val) != st.end())
            return false;

        st.emplace(val);
        return true;
    }
    
    bool remove(int val) {
        
        if (st.find(val) == st.end())
            return false;

        st.erase(val);
        return true;
    }
    
    int getRandom() {
        
        int index = rand() % st.size();
        auto it = st.begin();

        while(index--)
            it++;

        return *it;

        // We can also use this inbuilt function instead of while loop
        // return *next(st.begin(), index);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */