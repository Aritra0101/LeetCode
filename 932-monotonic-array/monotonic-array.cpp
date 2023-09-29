class Solution {
private:
    bool check_monotone_increasing(vector<int>& nums, int n) {
        for(int i=1; i<n; i++) {
            if(nums[i] < nums[i-1])
                return false;
        }
        return true;
    }

    bool check_monotone_decreasing(vector<int>& nums, int n) {
        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1])
                return false;
        }
        return true;
    }

public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
            return true;

        if(nums[0] < nums[n-1])
            return check_monotone_increasing(nums, n);
        else
            return check_monotone_decreasing(nums, n);
    }
};