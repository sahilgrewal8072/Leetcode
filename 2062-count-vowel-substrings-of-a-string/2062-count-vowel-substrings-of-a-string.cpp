class Solution {
    private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    int atmostK(string word, int k, int n){
        unordered_map<char,int> mp;
        int right = 0;
        int left = 0;
        int count = 0;
        for(right = 0; right < n; right++){
            if(!isVowel(word[right])){
                mp.clear();
                left = right + 1;
                continue;
            }
            mp[word[right]]++;
            
            while(mp.size() > k){
                mp[word[left]]--;
                if(mp[word[left]] == 0){
                    mp.erase(word[left]);
                }
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
    
public:
    int countVowelSubstrings(string word) {
        int n = word.length();
         int x = atmostK(word, 5, n);
        int y = atmostK(word, 4, n);
        return  x - y;
    }
};