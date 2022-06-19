class Solution {
public:
    string smallestSubsequence(string s) {
         int n = s.length();
        vector<int> visited(26, 0);
        vector<int> lastInd(26, 0);
        for(int i=0; i<n; i++){
            lastInd[s[i] - 'a'] = i;
        }
        stack<char> st;
        for(int i=0; i<n; i++){
            int curr = s[i] - 'a';
            if(visited[curr])continue;
            while(!st.empty() && st.top() > s[i] && lastInd[st.top() - 'a'] > i){
                visited[st.top() - 'a'] = 0;
                st.pop();
            }
           
                st.push(s[i]);
                visited[curr] = 1;   
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};