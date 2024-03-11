class Solution {
private:
    int solve01(vector<int>& nums, int target, int i, int sum) {
        if(i < 0) {
            if(sum == target) {
                return 1;
            } else {
                return 0;
            }
        }

        int plus = solve01(nums, target, i-1, sum + nums[i]);
        int minus = solve01(nums, target, i-1, sum - nums[i]);

        return (plus + minus);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve01(nums, target, n-1, 0);

        
    }
};