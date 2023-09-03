class Solution {
private:
    //Memorization
    // int solve(int m, int n, vector<vector<int>>& dp) {
    //     if(m<0 || n<0) {
    //         return 0;
    //     }
    //     if(m==0 && n==0) {
    //         return 1;
    //     }
    //     if(dp[m][n] != -1) {
    //         return dp[m][n];
    //     }

    //     return dp[m][n] = solve(m-1,n, dp) + solve(m, n-1, dp);
    // }

    //Recursing
    // int solve01(int m, int n) {
    //     if(m<0 || n<0) {
    //         return 0;
    //     }
    //     if(m==0 && n==0) {
    //         return 1;
    //     }

    //     return solve01(m-1,n) + solve01(m, n-1);
    // }

public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(m-1, n-1, dp);      //Memorization
        // return solve01(m-1, n-1);      //Recursing

        // Tabulation
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};