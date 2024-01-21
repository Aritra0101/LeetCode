class Solution {
private:
    //MEMORIZATION
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        if(n<0) {
            return 0;
        }
        if(n == 0) {
            return nums[n];
        }
        if(dp[n] != -1)
            return dp[n];

        int take = nums[n] + solve(nums, n-2, dp);
        int notTake = solve(nums, n-1, dp);

        return dp[n] = max(take, notTake);
    }

    // RECURSION
    int solve01(vector<int>& nums, int n) {
        if(n<0) {
            return 0;
        }
        if(n == 0) {
            return nums[n];
        }

        int take = nums[n] + solve01(nums, n-2);
        int notTake = solve01(nums, n-1);

        return max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // return solve01(nums, n-1); // RECURSION

        // vector<int> dp(n, -1);
        // return solve(nums, n-1, dp); // MEMORIZATION

        // vector<int> dp(n);
        // int take, notTake;
        // dp[0] = nums[0];
        // for(int i=1; i<n; i++) {
        //     take = (i<2) ? (nums[i]) : (nums[i] + dp[i-2]);
        //     notTake = dp[i-1];
        //     dp[i] = max(take, notTake);
        // }
        // return dp[n-1];

        // vector<int> dp(n+1);
        // dp[0] = 0;
        // dp[1] = nums[0];
        // for(int i=2; i<=n; i++) {
        //     dp[i] = max(nums[i-1]+dp[i-2], dp[i-1]);
        // }
        // return dp[n];

        int prev2=0, prev1=nums[0], curr;
        for(int i=1; i<n; i++) {
            curr = max(nums[i]+prev2, prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};