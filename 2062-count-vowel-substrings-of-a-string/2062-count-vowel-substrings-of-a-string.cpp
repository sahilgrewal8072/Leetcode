class Solution {
    private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
public:
    int countVowelSubstrings(string word) {
        set<char> st;
        int n = word.length();
        if(n < 5)return 0;
        int count = 0;
        for(int i=0; i<n; i++){
            st.clear();
            for(int j=i; j<n; j++){
                if(!isVowel(word[j]))break;
                st.insert(word[j]);
                if(st.size() == 5)count++;
            }
        }
        return count;
    }
};