class SnapshotArray {

    map<int,map<int,int>> snapShot;
    int snapCount = 0;
public:
    SnapshotArray(int length) {

        for(int i = 0; i<length; i++)
        {
            map<int,int> mp;
            mp[0] = 0;

            snapShot[i] = mp;
        }
        
    }
    
    void set(int index, int val) {

        snapShot[index][snapCount] = val;
        
    }
    
    int snap() {

       return snapCount++;
        
    }
    
    int get(int index, int snap_id) {

        auto it = snapShot[index].upper_bound(snap_id);
        it--;


        return it->second;
        
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */