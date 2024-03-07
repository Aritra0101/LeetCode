class Solution {
private:
    bool solve01(int i, vector<int>& nums, int sum1, int sum2) {
        if(i < 0) {
            return sum1==sum2;
        }

        return solve01(i-1, nums, sum1+nums[i], sum2) || solve01(i-1, nums, sum1, sum2+nums[i]);
    }

    bool solve02(int i, vector<int>& nums, int sum1, int sum2, vector<vector<int>> dp) {
        if(i < 0) {
            return sum1==sum2;
        }
        if(dp[i][sum1] != -1) {
            return dp[i][sum1];
        }


        return dp[i][sum1] = solve01(i-1, nums, sum1+nums[i], sum2) || solve01(i-1, nums, sum1, sum2+nums[i]);
    }

public:
    bool canPartition(vector<int>& nums) {
        // int n = nums.size();
        // return solve01(n-1, nums, 0 ,0);

        // int n = nums.size();
        // int sum = 0;
        // for(int n: nums) {
        //     sum += n;
        // }
        // int size = sum/2;

        // if((size+size) != sum) {
        //     return false;
        // }

        // vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        // return solve02(n-1, nums, 0 ,0, dp);


        int n = nums.size();
        int sum = 0;
        for(int n: nums) {
            sum += n;
        }

        if(sum%2 == 1) {
            return false;
        }

        int target = sum/2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));

        for(int i=0; i<n; i++) {
            dp[i][0] = true;
        }

        if (nums[0] <= target)
            dp[0][nums[0]] = true;

        for(int i=1; i<n; i++) {
            for(int k=1; k<=target; k++) {
                bool notTaken = dp[i - 1][k];
                
                bool taken = false;
                if (nums[i] <= k)
                    taken = dp[i - 1][k - nums[i]];

                dp[i][k] = notTaken || taken;
            }
        }

        return dp[n - 1][target];    
    }
};