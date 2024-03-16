class Solution {
    public int myAtoi(String s) {
        int n = s.length();
        int result = 0;
        int sign = 1;
        
        int i = 0;
        while(i < n && s.charAt(i) == ' ')i++;
        if(i < n  && s.charAt(i) == '-'){
            i++;
            sign = -1;
        }else if(i < n && s.charAt(i) == '+'){
            sign = 1;
            i++;
        }
        while(i < n){
            
            if(s.charAt(i) >= '0' && s.charAt(i) <= '9'){
                int digit = s.charAt(i) - '0';
                // System.out.print(digit + " ");
                if(result > Integer.MAX_VALUE/10 || result == Integer.MAX_VALUE/10 && digit > Integer.MAX_VALUE%10)return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
                result = result*10 + digit;
            }else{
                break;
            }
            i++;
        }
        return sign*result;
    }
}