class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        int res = 0;
        
        for(char p = 'a'; p <= 'z'; p++){
            for(char q = 'a'; q <= 'z'; q++){
                if(p == q)continue;
                int p_count = 0;
                int q_count = 0;
                bool q_detect = false;
                for(int i=0; i<n; i++){
                    if(p == s[i])p_count++;
                    if(q == s[i])q_count++;
                    
                    if(q_count > 0){
                        res = max(res, p_count - q_count);
                    }else if(q_count == 0 && q_detect == true){
                        res = max(res, p_count - 1);
                    }
                    
                    if(q_count > p_count){
                        q_count = p_count = 0;
                        q_detect = true;
                    }
                }
            }
        }
       return res; 
    }
};