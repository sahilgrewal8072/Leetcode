class Solution {
public:
    string decodeCiphertext(string encoded, int rows) {
        int n = encoded.length();
        int col = n/rows;
        string ans = "";
        for(int i=0; i<col; i++){
            for(int j = i; j<n; j+=(col+1)){
                ans += encoded[j];
            }
        }
        
        while(ans.back() == ' ')ans.pop_back();
        return ans;
    }
};