class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s = "";
        for(int i = 0; i < strs.size(); i++){
            for(int j=0; j < strs[i].length(); j++){
                if(strs[i][j] == '/'){
                    s += "//";
                }else{
                    s += strs[i][j];
                }
            }
            s += "/:";
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = s.length();
        vector<string> ans;
        string currStr = "";
        for(int i = 0; i < n; i++){

            if(i < n-1 && s[i] == '/' && s[i+1] == '/'){
                currStr += '/';
                i += 1;
            }else if(i < n-1 && s[i] == '/' && s[i+1] == ':'){
                ans.push_back(currStr);
                currStr.clear();
                i += 1;
            }else{
                currStr += s[i];
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));