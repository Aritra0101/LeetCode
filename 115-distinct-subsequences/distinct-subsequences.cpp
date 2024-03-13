class Solution {
private:
    int solve01(string s, string t, int n1, int n2) {
        if(n2 < 0) {
            return 1;
        }
        if(n1 < 0) {
            return 0;
        }

        if(s[n1] == t[n2]) {
            return  solve01(s, t, n1-1, n2-1) +  solve01(s, t, n1-1, n2);
        } else {
            return  solve01(s, t, n1-1, n2);
        }
    }

    int solve02(string s, string t, int n1, int n2, vector<vector<int>>& dp) {
        if(n2 < 0) {
            return 1;
        }
        if(n1 < 0) {
            return 0;
        }

        if(dp[n1][n2] != -1) {
            return dp[n1][n2];
        }

        if(s[n1] == t[n2]) {
            return  dp[n1][n2] = (solve02(s, t, n1-1, n2-1, dp) +  solve02(s, t, n1-1, n2, dp));
        } else {
            return  dp[n1][n2] = solve02(s, t, n1-1, n2, dp);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();

        // return solve01(s,t, n1-1, n2-1);

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        return solve02(s,t, n1-1, n2-1, dp);

        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        // for(int i=0; i<=n1; i++) {
        //     dp[i][0] = 1;
        // }

        // for(int i=1; i<=n1; i++) {
        //     for(int j=1; j<=n2; j++) {
        //         if(s[i-1] == t[j-1]) {
        //             dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        //         } else {
        //             dp[i][j] = dp[i-1][j-1];
        //         }
        //     }
        // }

        // return dp[n1][n2];
    }
};