class Solution {
    private:
    // Time complexity raat lena iske 
    void solve(int ind, int open, int close, string &curr, vector<string> &ans, int n){
        if(ind >= 2*n){
            ans.push_back(curr);
            return;
        }
        
        if(open < n){
            curr.push_back('(');
            solve(ind + 1, open + 1, close, curr, ans, n);
            curr.pop_back();
        }
        
        if(close < open){
            curr.push_back(')');
            solve(ind + 1, open, close+1, curr, ans, n);
            curr.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        solve(0, 0, 0, curr, ans, n);
        return ans;
    }
};