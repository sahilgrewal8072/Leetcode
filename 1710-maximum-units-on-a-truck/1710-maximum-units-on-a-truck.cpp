class Solution {
public:
    
     static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int limit = 0;
        int ans = 0;
        int i = 0;
        int n = boxTypes.size();
        for(i=0; i<n; i++){
            if(limit + boxTypes[i][0] <= truckSize){
                limit += boxTypes[i][0];
                ans += (boxTypes[i][1]*boxTypes[i][0]);
            }else{
                int fact = max(0, truckSize - limit);
                ans += (fact*boxTypes[i][1]);
                break;
            }
        }
        // for(auto it : boxTypes){
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        return ans;
    }
};