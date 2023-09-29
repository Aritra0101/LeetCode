class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        int i=0;
        while(i<n) {
            // get 1
            while(i<n && nums[i] != 1) {
                i++;
            }

            for(int j=1; j<=k && i+j<n; j++) {
                if(nums[i+j])
                    return false;
            }
            i++;
        }
        return true;
    }
};