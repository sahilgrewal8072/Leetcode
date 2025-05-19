class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        for(int i = 0, j = n-1; i < j; j--, i++){
            while(i < j && !isalnum(s[i]))i++;
            while(i < j && !isalnum(s[j]))j--;
            if(tolower(s[i]) != tolower(s[j]))return false;
        }
        return true;
    }
};