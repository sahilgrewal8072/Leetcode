class Solution {
    private:
    vector<int> hash_table(string &needle, int m){
        vector<int> hash(m, 0);
        int i=1, j=0; 
        while(i < m){
            if(needle[i] == needle[j]){
                hash[i++] = j+1;
                j++;
            }else{
                if(j != 0) j = hash[j-1];
                else
                    i++;
            }
        }
        return hash;
    }
    
public:
    int strStr(string s, string needle) {
        int n = s.length();
        int m = needle.length();
        if(m == 0)return 0;
        vector<int> hash = hash_table(needle, m);
        int i = 0, j = 0;
        while(i < n){
            if(s[i] == needle[j]){
                i++;
                j++;
                if(j == m)return i - m;
            }else{
                if(j) j = hash[j-1];
                else
                    i++;
            }
        }
        return -1;
    }
};