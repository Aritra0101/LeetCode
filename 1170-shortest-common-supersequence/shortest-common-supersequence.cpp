class Solution {
private:
    string genLCS(vector<vector<int>>& dp, int n1, int n2, string& str1, string& str2) {
        if(n1==0 || n2==0) {
            return "";
        }

        if(str1[n1-1] == str2[n2-1]) {
            return genLCS(dp, n1-1, n2-1, str1, str2) + str1[n1-1];
        } else {
            if( dp[n1-1][n2] == dp[n1][n2] ) {
                return genLCS(dp, n1-1, n2, str1, str2);
            } else {
                return genLCS(dp, n1, n2-1, str1, str2);
            }
        }

    }

    string genRes(vector<vector<int>>& dp, int n1, int n2, string& str1, string& str2) {
        if(n1==0) {
            return str2.substr(0, n2);
        }
        if(n2 == 0) {
            return str1.substr(0, n1);
        }

        if(str1[n1-1] == str2[n2-1]) {
            return genRes(dp, n1-1, n2-1, str1, str2) + str1[n1-1];
        } else {
            if( dp[n1-1][n2] == dp[n1][n2] ) {
                return genRes(dp, n1-1, n2, str1, str2) + str1[n1 - 1];
            } else {
                return genRes(dp, n1, n2-1, str1, str2) + str2[n2 - 1];
            }
        }

    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        vector< vector<int> > dp(n1+1, vector<int>(n2+1, 0));

        for(int i=1; i<=n1; i++) {
            for(int j=1; j<=n2; j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // string lcs = genLCS(dp, n1, n2, str1, str2);

        string res = genRes(dp, n1, n2, str1, str2);

        return res;;
    }
};