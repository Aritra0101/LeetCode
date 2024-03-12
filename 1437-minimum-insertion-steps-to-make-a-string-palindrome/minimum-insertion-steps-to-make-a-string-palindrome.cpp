class Solution {
public:
    int minInsertions(string s) {
        string str01 = s;
        string str02 = s;
        reverse(str02.begin(), str02.end());

        int n = s.size();

        vector<vector<int>> dp(n+1, vector(n+1, 0));

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(str01[i-1] == str02[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
                }
            }
        }

        return n - dp[n][n];
    }
};