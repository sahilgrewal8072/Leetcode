class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int power) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
    
        int score_gain = 0;
        int left = 0;
        int right = n-1;
        int mx = 0;
        while(left <= right){
            while(left < n && power - arr[left] >= 0 ){
                    score_gain++;
                    power -= arr[left];
                    left++;
                    mx = max(mx, score_gain);
            }
            
            if(right >= 0 && score_gain > 0){
                score_gain--;
                power += arr[right];
                right--;
            }else if(score_gain == 0){
                break;
            }
        }
        return mx;
    }
};