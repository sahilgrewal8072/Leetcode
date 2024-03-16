class Solution {
    public int maxDepth(String s) {
        int n = s.length();
        int mx = 0;
        Stack<Character> st = new Stack<>();
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == '('){
                st.push('(');
            }else if(s.charAt(i) == ')'){
                st.pop();
            }
            mx = Math.max(st.size(), mx);
        }
        return mx;
    }
}