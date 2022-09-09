class Solution {
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1]  > b[1];
        }
        return a[0] < b[0];
    }
    
public:
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int n = prop.size();
        sort(prop.begin(), prop.end(), cmp);
        
        int ans = 0;
        int mx = prop[n-1][1];
        for(int i=n-2; i>=0; i--){
            if(prop[i][1] < mx){
                ans++;
            }else if(prop[i][1] > mx){
                mx = prop[i][1];
            }
        }
        return ans;
    }
};