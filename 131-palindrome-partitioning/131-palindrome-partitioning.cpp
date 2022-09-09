class Solution {
    
    private:
    
    bool isPali(string &s, int start, int end, int n){
        while(start <= end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }
    
    void solve(int ind, string &s, int n, vector<vector<string>> &ans, vector<string> &curr){
        if(ind == n){
            ans.push_back(curr);
            return;
        }
        
        for(int i=ind; i<n; i++){
            if(isPali(s, ind, i, n)){
                curr.push_back(s.substr(ind, i - ind + 1));
                solve(i + 1, s, n, ans, curr);
                curr.pop_back();
            }
        }
        return;
    }
    
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> curr;
        solve(0, s, n, ans, curr);
        return ans;
    }
};