class Solution {
    public String reverseWords(String s) {
        // Stringbulder s = new StringBuilder("");
        int len = s.length();
        int end = len - 1;
        StringBuilder temp = new StringBuilder("");
        StringBuilder final_ans =  new StringBuilder("");
        for(int i = len - 1; i >= 0; i--){
            if(s.charAt(i) == ' '){
                if(temp.length() == 0)continue;
                temp.reverse();
                final_ans.append(temp);
                final_ans.append(" ");
                temp.setLength(0);
                end = i-1;
            }else{
                temp.append(s.charAt(i));
            }
        }
        if(s.charAt(0) == ' ')return final_ans.toString().trim();
        // final_ans.append(" ");
        final_ans.append(s.substring(0, end+1));
        return final_ans.toString().trim();
    }
    
}