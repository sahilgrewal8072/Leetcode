unordered_map<int, string> mp({{2,"abc"},{3,"def"},{4,"ghi"},
    {5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}});

class Solution {
    
public:
    
    void solve(int ind, string temp,  string &s, int n, vector<string> &ans){
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        
        int x = mp[s[ind] - '0'].length();
        for(int i=0; i<x; i++){
            temp += mp[s[ind] - '0'].at(i);
            solve(ind + 1, temp, s, n, ans);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0)return {};
        vector<string> ans;
        solve(0, "", digits, n, ans);
        return ans;
    }
};