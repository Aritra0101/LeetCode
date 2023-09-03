class Solution {
    public boolean validPartition(int[] nums) {
        int n = nums.length;
        boolean dp1 = true;
        boolean dp2 = false;
        boolean dp3 = nums[0] == nums[1];

        for(int i=2; i<n; i++) {
            boolean temp = false;

            if(dp2 && nums[i-1] == nums[i])
                temp = true;
            else if(dp1 && nums[i-2] == nums[i-1] && nums[i-1] == nums[i])
                temp = true;
            else if(dp1 && nums[i]-nums[i-1]==1 && nums[i-1]-nums[i-2]==1)
                temp = true;

            dp1=dp2;
            dp2=dp3;
            dp3=temp;
        }

        return dp3;
    }
}