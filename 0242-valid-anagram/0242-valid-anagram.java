class Solution {
    public boolean isAnagram(String s, String t) {
        int[] mp1 = new int[26];
        int[] mp2 = new int[26];
        
        int n = s.length();
        if(n != t.length())return false;
        
        for(int i = 0; i<n; i++){
            mp1[(int)s.charAt(i) - 97]++;
            mp2[(int)t.charAt(i) - 97]++;
        }
        
        for(int i = 0; i<26; i++){
            if(mp1[i] != mp2[i])return false;
        }
        return true;
    }
}