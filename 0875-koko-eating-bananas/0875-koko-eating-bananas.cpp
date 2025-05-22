class Solution {
    
    private:
    bool isSatisfy(int k, vector<int> &piles, int n, int h){
        int count = 0;
        for(int i = 0; i<n; i++){
            count += ceil((double)piles[i]/(double)k);
            if(count > h)return false;
        }
        return true;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int ans = -1;
        int high = -1;
        for(int i = 0; i < n; i++){
            high = max(high,piles[i]);
        }
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isSatisfy(mid, piles, n, h)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};