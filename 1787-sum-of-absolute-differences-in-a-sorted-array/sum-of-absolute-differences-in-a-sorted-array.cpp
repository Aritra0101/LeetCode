class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n);
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            preSum[i] = sum;
        }

        vector<int> res(n);
        int sum2 = 0;
        for(int i=0; i<n; i++) {
            res[i] = ((nums[i] * i) - sum2) + ((sum - sum2) - (nums[i] * (n-i)));
            sum2 += nums[i];
        }
        return res;
    }
};