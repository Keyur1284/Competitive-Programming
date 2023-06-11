// Problem Link :- https://leetcode.com/problems/snapshot-array/

// Solved using vector of map

class SnapshotArray {
public:

    int snaps;
    vector<map<int, int>> snapshot;

    SnapshotArray(int length) {
        
        snapshot.assign (length, {{0, 0}});
        snaps = 0;
    }
    
    void set(int index, int val) {
        
        snapshot[index][snaps] = val;
    }
    
    int snap() {
        
        return (snaps++);
    }
    
    int get(int index, int snap_id) {
        
        auto it = snapshot[index].upper_bound(snap_id);
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */