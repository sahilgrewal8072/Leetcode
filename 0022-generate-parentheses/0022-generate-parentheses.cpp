class Solution {
    private:
    void solve(int n, int open, int close, string curr, vector<string> &ans){
        if(n == 0){
            ans.push_back(curr);
            return;
        }
        
        if(open > 0){
            curr += '(';
            solve(n - 1, open - 1, close, curr, ans);
            curr.pop_back();    
        }
        
        if(open < close){
            curr += ')';
            solve(n - 1, open, close - 1, curr, ans);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(2*n, n, n, "", ans);
        return ans;
    }
};