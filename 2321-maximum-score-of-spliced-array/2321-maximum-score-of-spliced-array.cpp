class Solution {
public:
    int kadane(vector<int> &receive, vector<int> &send, int n){
        int balance = 0;
        int mx = 0;
        int sum = 0;
        for(int i=0; i<n; i++){
            balance += send[i] - receive[i];
            sum += receive[i];
            if(balance < 0)balance = 0;
            mx = max(mx, balance);
        }
        return sum + mx;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        return max(kadane(nums1, nums2, n), kadane(nums2, nums1, n));
    }
};