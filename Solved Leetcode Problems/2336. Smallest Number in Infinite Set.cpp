// Problem Link :- https://leetcode.com/problems/smallest-number-in-infinite-set/

// Time Complexity :- O(nlogn)
// Space Complexity :- O(n)

class SmallestInfiniteSet {
public:
    set<int> st;

    void make ()
    {
        for (int i = 1; i <= 1000; i++)
            st.emplace(i);
    }
    
    SmallestInfiniteSet() {
        
        make();
    }
    
    int popSmallest() {
        
        int num = *st.begin();
        st.erase(num);

        return num;
    }
    
    void addBack(int num) {
        
        st.emplace(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */


class SmallestInfiniteSet {
public:
    set<int> addedNums;
    int curr;
    
    SmallestInfiniteSet() {
        
        curr = 1;
    }
    
    int popSmallest() {
        
        int num;

        if (!addedNums.empty())
        {
            num = *addedNums.begin();
            addedNums.erase(num);
        }

        else
        {
            num = curr;
            curr++;
        }

        return num;
    }
    
    void addBack(int num) {
        
        if (curr > num)
            addedNums.emplace(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */