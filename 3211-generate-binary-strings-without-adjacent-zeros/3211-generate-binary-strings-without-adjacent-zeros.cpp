class Solution {
public:
    vector<string> validStrings(int n) {
        //using power set method
        int limit = (1 << n);
        vector<string> ans;

        for(int i = 0; i < limit; i++){
            string tmp = "";
            bool isValid = true;
            for(int j = n-1; j >= 0; --j){
                tmp += (i & (1 << j)) ? "1" : "0";
            }
            
            //checking if tmp is valid or not
            for(int k = 1; k < n; k++){
                if(tmp[k-1] == '0' && tmp[k] == '0'){
                    isValid = false;
                    break;
                }
            }
            
            if(isValid){
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};