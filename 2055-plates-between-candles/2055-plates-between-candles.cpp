class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> prev(n, n), nxt(n, n), prefixSum(n, 0);
        for(int i=0; i<n; i++){
            if(i == 0){
                if(s[i] == '|')prev[i] = i;
                else
                prefixSum[i] = 1;
            }else{
                if(s[i] == '|'){
                    prev[i] = i;
                    prefixSum[i] = prefixSum[i-1];
                }else{
                    prev[i] = prev[i-1];
                    prefixSum[i] = 1 + prefixSum[i-1];
                }
            }
        }
        
        for(int i = n-1; i>=0; i--){
            if(i == n-1){
                if(s[i] == '|'){
                    nxt[i] = i;
                }
            }else{
                if(s[i] == '|'){
                    nxt[i] = i;
                }else{
                    nxt[i] = nxt[i+1];
                }
            }   
        }
        
        vector<int> ans;
        for(auto it : queries){
            int low = it[0];
            int high = it[1];
            int i = nxt[low];
            int j = prev[high];
            if(i>=j || i == n || j == n)ans.push_back(0);
            else
                ans.push_back((prefixSum[j] - prefixSum[i]));
        }
        return ans;
    }
};