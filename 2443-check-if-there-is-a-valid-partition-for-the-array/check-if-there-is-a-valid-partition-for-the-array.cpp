class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1, false);
        bool option1, option2, option3;

        dp[0] = true;
        dp[2] = nums[0] == nums[1];
        for(int i=3; i<=n; i++) {
            option1 = dp[i-2] && nums[i-2] == nums[i-1];
            option2 = dp[i-3] && nums[i-3] == nums[i-2] && nums[i-2] == nums[i-1];
            option3 = dp[i-3] && nums[i-1] - nums[i-2] == 1 && nums[i-2] - nums[i-3] == 1;
            dp[i] = option1 || option2 || option3;
        }

        return dp[n];
        return 11;
    }
};