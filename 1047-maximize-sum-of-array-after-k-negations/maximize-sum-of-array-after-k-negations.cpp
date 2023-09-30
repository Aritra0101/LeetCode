class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i;
        for(i=0; i<n && nums[i]<0 && k>0; i++) {
            nums[i] = -1 * nums[i];
            k--;
            cout<<i<<' ';
        }

        int mini = INT_MAX;
        if(k%2 == 0) {
            k=0;
            mini = 0;
        }
        else {
            if(i==0)
                mini = nums[i];
            else if(i==n)
                mini = nums[n-1];
            else
                mini = min(nums[i-1], nums[i]);
        }

        int res = 0;
        for(int n: nums)
            res += n;

        return res-mini-mini;


    }
};