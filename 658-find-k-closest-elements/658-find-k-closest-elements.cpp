class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        priority_queue<int>pq1;
        vector<int> ans;
        int i;
        int n = arr.size();
        for(i=0; i<n; i++){
            pq.push({abs(arr[i]-x), arr[i]});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            pq1.push(pq.top().second);
            pq.pop();
        }
        while(!pq1.empty()){
            ans.push_back(pq1.top());
            pq1.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};