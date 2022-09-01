class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        sort(inter.begin(), inter.end());
       vector<vector<int>> st;
        st.push_back({inter[0][0], inter[0][1]});
        int j= 0;
        for(int i=1; i<n; i++){
            if(st[j][1] >= inter[i][0]){
                st[j][1] = max(inter[i][1], st[j][1]);
            }else{
                st.push_back(inter[i]);
                j++;
            }
        }
      
        return st;
    }
};