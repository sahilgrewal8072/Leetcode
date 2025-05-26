// class Solution {
//     private:
//     int solve(int x, int y, vector<vector<int>> &dp, int m, int n){
//         if(x == m-1 && y == n-1){
//             return 1;
//         }
//         if(x >= m || y >= n)return 0;
//         cout<<x<<" "<<y<<endl;
//         if(dp[x][y] != -1)return dp[x][y];
//         int down = solve(x, y + 1, dp, m, n);
//         int right = solve(x + 1, y, dp, m, n);
        
//         return dp[x][y] = down + right;
//     }
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int> (n, 0));
//         // return solve(0, 0, dp, m, n);
        
//         for(int x = m-1; x >= 0; x--){
//             for(int y = n-1; y >= 0; y--){
//                 if(x == m-1 && y == n-1){
//                     dp[x][y] = 1;
//                 }else{
//                     int down = y + 1 < n ?dp[x][y + 1] : 0;
//                     int right = x+1 < m ?dp[x+1][y] : 0;
//                     dp[x][y] = down + right;
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for(int i = m+n-2, j = 1; i >= max(m, n); i--, j++) 
            ans = (ans * i) / j;
        return ans;
    }
};