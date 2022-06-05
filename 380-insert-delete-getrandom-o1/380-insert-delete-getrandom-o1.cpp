class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> arr;
    int len;
    RandomizedSet() {
        mp.clear();
        len  = 0;
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()){
            return false;
        }else{
            arr.push_back(val);
            mp[val] = len;
            len++;
        } 
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }else{
            int ind = mp[val];
            arr[ind] = arr[len-1];
            mp[arr[ind]] = mp[val];
            mp.erase(val);
            arr.pop_back();
            len--;
        }
        return true;
    }
    
    int getRandom() {
        return arr[rand()%len];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */