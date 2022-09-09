class Solution {
    // Dp + limited DFS
    private:
    unordered_set<string> visited;
    int bracketsToRemove(string &s, int &n){
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i] != '(' && s[i] != ')')continue;
            if(s[i] == '('){
                st.push(s[i]);
            }else if(!st.empty()){
                if(st.top() == '('){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
    
    
    bool isValid(string &s){
        int n = s.length();
        return (bracketsToRemove(s, n) == 0) ? true : false;
    }
    
    void print_pattern(int mx_remove, int &n, string curr, unordered_set<string> &ans){
        if(mx_remove == 0){
            if(isValid(curr)){  
                ans.insert(curr);
            }
            return;
        }
        
        int len = curr.length();
        for(int i=0; i<len; i++){
            if(curr[i] != '(' && curr[i] != ')')continue;
            string left = curr.substr(0, i);
            string right = curr.substr(i+1);
            if(visited.count(left + right) > 0)continue;
            visited.insert(curr);
            print_pattern(mx_remove-1, len, left + right, ans);
        }
        
        return;
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> stt;
        vector<string> ans;
        int n = s.length();
        int mx_remove = bracketsToRemove(s, n);
        if(mx_remove == 0){
            return {s};
        }
        print_pattern(mx_remove, n, s, stt);
        for(auto it : stt){
            ans.push_back(it);
        }
        if(ans.size() == 0){
            return {""};
        }
        return ans;
    }
};