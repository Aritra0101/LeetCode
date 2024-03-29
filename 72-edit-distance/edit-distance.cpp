class Solution {
private:
    int solve01(string word1, string word2, int n1, int n2) {
        if(n1 < 0) {
            return n2 + 1;
        }
        if(n2 < 0) {
            return n1 + 1;
        }

        if(word1[n1] == word2[n2]) {
            return solve01(word1, word2, n1-1, n2-1);
        }

        int c1 = solve01(word1, word2, n1, n2-1) + 1; //insert
        int c2 = solve01(word1, word2, n1-1, n2) + 1; //delete
        int c3 = solve01(word1, word2, n1-1, n2-1) + 1; //replace

        return min(c1, min(c2, c3));
    }

    int solve02(string word1, string word2, int n1, int n2, vector<vector<int>>& dp) {
        if(n1 < 0) {
            return n2 + 1;
        }
        if(n2 < 0) {
            return n1 + 1;
        }

        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(word1[n1] == word2[n2]) {
            return dp[n1][n2] = solve02(word1, word2, n1-1, n2-1, dp);
        }

        int c1 = solve02(word1, word2, n1, n2-1, dp) + 1; //insert
        int c2 = solve02(word1, word2, n1-1, n2, dp) + 1; //delete
        int c3 = solve02(word1, word2, n1-1, n2-1, dp) + 1; //replace

        return dp[n1][n2] = min(c1, min(c2, c3));
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        if(n1==0) return n2; //insert all
        if(n2==0) return n1; //delete all

        // return solve01(word1, word2, n1-1, n2-1);

        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return solve02(word1, word2, n1-1, n2-1, dp);

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=0; i<=n1; i++) {
            dp[i][0] = i;
        }
        for(int j=0; j<=n2; j++) {
            dp[0][j] = j;
        }
        dp[0][0] = 0;
        for(int i=1; i<=n1; i++) {
            for(int j=1; j<=n2; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};