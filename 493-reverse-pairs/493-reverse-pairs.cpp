class Solution {
    private:
    int merge(vector<int> &arr, int &s, int &e){
        int count = 0;
        int i = s;
        int mid = (s + e)/2;
        int j = mid + 1;
        for(int low = s; low <= mid; low++){
            while(j <= e && arr[low] > 1ll*2*arr[j]){
                j++;
            }
            count += (j - (mid + 1));
        }
        
        i = s;
        j = mid + 1;
        vector<int> temp;
        while(i <= mid && j <= e){
            if(arr[i] < arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                // count += (mid - i + 1);
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= e){
            temp.push_back(arr[j]);
            j++;
        }
        
        int k = 0;
        for(int ind = s; ind<=e; ind++){
            arr[ind] = temp[k];
            k++;
        }   
        return count;
    }
    
    
    int inversion_count(vector<int> &arr, int s, int e){
        if(s >= e)return 0;
        int mid = (s + e)/2;
        int c1 = inversion_count(arr, s, mid);
        int c2 = inversion_count(arr, mid + 1, e);
        int cross_count = merge(arr, s, e);
        return c1 + c2 + cross_count;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        int count = inversion_count(nums, 0, n-1);
        return count;
    }
};