class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int pos = -1;
        int neg = -1;

        for(int i=0; i<n; i++) {
            if(nums[i] < 0) {
                neg = i;
                break;
            }
        }
        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                pos = i;
                break;
            }
        }

        for(int i=0; i<n; i+=2) {
            res[i] = nums[pos++];
            res[i+1] = nums[neg++];

            while( (pos < n) && !(nums[pos] > 0) ) { pos++; }
            while( (neg < n) && !(nums[neg] < 0) ) { neg++; }
        }

        return res;
    }
};