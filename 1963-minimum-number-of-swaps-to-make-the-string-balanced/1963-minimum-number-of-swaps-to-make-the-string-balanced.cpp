class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int stack_size = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '['){
                stack_size++;
            }else{
                if(stack_size > 0){
                    stack_size--;
                }
            }
        }
        
        if(stack_size&1){
            return (stack_size + 1)/2;
        }
        return stack_size/2;
    }
};