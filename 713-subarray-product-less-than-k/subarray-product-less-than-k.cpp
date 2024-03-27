class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;

        int n = nums.size();

        for(int i=0; i<n; i++) {
            int pro = 1;
            for(int j=i; j<n; j++) {
                pro *= nums[j];

                if(pro < k) res++;
                else break;
            }
        }

        return res;
    }
};