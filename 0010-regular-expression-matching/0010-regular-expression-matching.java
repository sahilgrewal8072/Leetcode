class Solution {
    public boolean isMatch(String s, String p) {
        if (s == null || p == null) return false;
        
        // dp[i][j] represents if the first i characters in s match the first j characters in p
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        
        // Empty string and empty pattern match
        dp[0][0] = true;
        
        // Deals with patterns like "a*", ".*", etc. (matches empty string)
        for (int j = 1; j <= p.length(); j++) {
            if (p.charAt(j - 1) == '*' && dp[0][j - 2]) {
                dp[0][j] = true;
            }
        }
        
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                char sc = s.charAt(i - 1);
                char pc = p.charAt(j - 1);
                
                if (sc == pc || pc == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pc == '*') {
                    // Zero occurrence of preceding character or one or more occurrence
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s.charAt(i - 1) == p.charAt(j - 2) || p.charAt(j - 2) == '.'));
                }
            }
        }
        
        return dp[s.length()][p.length()];
    
    }
}