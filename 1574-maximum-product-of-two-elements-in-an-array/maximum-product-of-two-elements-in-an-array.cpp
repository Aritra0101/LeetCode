class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int max1 = nums[0], max2 = nums[1];
        if(nums[0] < nums[1])
            swap(max1, max2);

        for(int i=2; i<n; i++) {
            if(nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            } else if(nums[i] > max2) {
                max2 = nums[i];
            }
        }
        return (max1-1)*(max2-1);

        // auto m1 = 0, m2 = 0;
	    // for (auto n: nums) {
        //     if(n > m1) {
        //         m2 = m1;
        //         m1 = n;
        //     }
        //     else if(n > m2)
        //         m2 = n;
	    // }
	    // return (m1 - 1) * (m2 - 1);
    }
};