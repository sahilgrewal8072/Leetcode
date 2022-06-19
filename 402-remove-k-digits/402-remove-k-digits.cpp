class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k)return "0";
        stack<int> st;
        for(int i=0; i<n; i++){
            while(k > 0 && (!st.empty() && st.top() > num[i])){
                st.pop();
                k--;
            }
            st.push(num[i] - 0);
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
      
        reverse(ans.begin(), ans.end());
        int i=0;
        
        //removal of leading zeros
        for(i=0; i<ans.length(); i++){
            if(ans[i] != '0')break;
        }
        
        // If there is still chance for removal i.e k > 0
        while(k-- && !ans.empty()){
            ans.pop_back();
        }
        
        if(ans.length() == 1 && ans[0] == '0' || ans.length() == i)return "0";
        
        return ans.substr(i, ans.length());
    }
};