class Solution {
    public String removeOuterParentheses(String str) {
        Stack<Character> st = new Stack<>();
        StringBuilder s = new StringBuilder("");
        
        for(int i = 0; i<str.length(); i++){
            if(str.charAt(i) == '('){
                if(st.size() > 0){
                    s.append(str.charAt(i));
                }
                st.push(str.charAt(i));
            }else{
                st.pop();
                if(st.size() > 0){
                    s.append(str.charAt(i));
                }
            }
        }
        return s.toString();
    }
}