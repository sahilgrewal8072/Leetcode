class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mp;

    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        // string s = to_string(left) + '$' + to_string(right) + '$' + to_string(value);
        // if(mp2.find(s) != mp2.end())return mp2[s];
        vector<int> &arr = mp[value];
        int count = 0;
        int low = lower_bound(arr.begin(), arr.end(), left) - arr.begin();
        // if(low-1 >= 0 && arr[low-1] == left)count++;
        int high = upper_bound(arr.begin(), arr.end(), right) - arr.begin();
        count = high - low;
        // mp2[s] = count;
        return count;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */