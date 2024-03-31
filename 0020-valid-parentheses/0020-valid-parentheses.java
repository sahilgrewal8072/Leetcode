class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        int n = s.length();
        if(n%2 != 0)return false;
        for(int i = 0; i<n; i++){
            if(s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '['){
                st.push(s.charAt(i));
            }else if(st.size() > 0){
                if(st.peek() == '('){
                    if(s.charAt(i) == ')')
                        st.pop();
                    else
                        return false;
                }else if(st.peek() == '{'){
                    if(s.charAt(i) == '}')
                        st.pop();
                    else
                        return false;
                }else if(st.peek() == '['){
                    if(s.charAt(i) == ']')
                        st.pop();
                    else
                        return false;
                }
            }else{
                return false;
            }
        }
        
        return (st.size() == 0) ? true : false;
    }
}