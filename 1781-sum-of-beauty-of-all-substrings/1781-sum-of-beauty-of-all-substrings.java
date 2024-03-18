class Solution {
    public int getMax(int[] hash){
        int mx = 0;
        for(int i = 0; i<26; i++){
            mx = Math.max(mx, hash[i]);
        }
        return mx;
    }
    
    public int getMin(int[] hash){
        int mn = Integer.MAX_VALUE;
        for(int i = 0; i<26; i++){
            if(hash[i] != 0)
            mn = Math.min(mn, hash[i]);
        }
        return mn;
    }
    
    public int beautySum(String s) {
        int n = s.length();
        int sum = 0;
        for(int i = 0; i<n; i++){
            int[] hash = new int[26];
            for(int j=i; j<n; j++){
                hash[s.charAt(j) - 'a']++;
                // find the max and min frequencey for the substring starting from i till j
                int beauty = getMax(hash) - getMin(hash);
                sum += beauty;
            }
            
        }
        return sum;
    }
}