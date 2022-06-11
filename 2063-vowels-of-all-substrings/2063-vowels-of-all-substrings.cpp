class Solution {
    
    private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
public:
    long long countVowels(string word) {
        long long int n = word.length();
        long long int count = 0;
        for(long long int i=0; i<n; i++){
            if(isVowel(word[i])){
                count += (i+1)*(n-i);
            }
        }
        return count;
    }
};