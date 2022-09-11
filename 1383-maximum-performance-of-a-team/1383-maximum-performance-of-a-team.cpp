class Solution {
public:
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({efficiency[i], speed[i]});
        }
        
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long mx = 0;
        long sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i].second;
            pq.push(arr[i].second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            
            mx = max(mx, (sum*arr[i].first));
        }
        return mx%mod;
    }
};