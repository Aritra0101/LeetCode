class Solution {
private:
    // MEMORIZATION 
    // int solve(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>>& dp) {
    //     if(j<0 || j>n)
    //         return INT_MAX;
    //     if(i==n)
    //         return matrix[i][j];
    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     int choice01 = solve(matrix, n, i+1, j-1, dp);
    //     int choice02 = solve(matrix, n, i+1, j, dp);
    //     int choice03 = solve(matrix, n, i+1, j+1, dp);

    //     dp[i][j] = matrix[i][j] + min(choice01, min(choice02, choice03));

    //     return dp[i][j];
    // }

    // RECURSION
    // int solve01(vector<vector<int>>& matrix, int n, int i, int j) {
    //     if(j<0 || j>n)
    //         return INT_MAX;
    //     if(i==n)
    //         return matrix[i][j];

    //     int choice01 = solve01(matrix, n, i+1, j-1);
    //     int choice02 = solve01(matrix, n, i+1, j);
    //     int choice03 = solve01(matrix, n, i+1, j+1);

    //     return matrix[i][j] + min(choice01, min(choice02, choice03));
    // }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // int ans = INT_MAX;
        // for(int j=0; j<n; j++) {
        //     // ans = min(ans, solve01(matrix, n-1, 0, j));
        //     ans = min(ans, solve(matrix, n-1, 0, j, dp));
        // }
        // return ans;

        // dp[0] = matrix[0];
        // for(int i=1; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         int mini = INT_MAX;
        //         for(int k=max(0,j-1); k<=min(n-1, j+1); k++ ) {
        //             mini = min(mini, dp[i-1][k]);
        //         }
        //         dp[i][j] = mini + matrix[i][j];
        //     }
        // }
        // return *min_element( dp[n-1].begin(), dp[n-1].end() );

        vector<int> prev(matrix[0].begin(), matrix[0].end());
        vector<int> curr(n);
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                int mini = INT_MAX;
                for(int k=max(0,j-1); k<=min(n-1, j+1); k++ ) {
                    mini = min(mini, prev[k]);
                }
                curr[j] = mini + matrix[i][j];
            }
            prev = curr;
        }
        return *min_element( prev.begin(), prev.end() );
    }
};