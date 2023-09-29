class Solution {
private:
    int countSetBits(int n) {
        int count = 0;
    
        while (n) {
            n &= (n - 1);
            count++;
        }
    
        return count;
    }
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {

        int res = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            // if(countSetBits(i) == k) {
            if(__builtin_popcount(i) == k) {
                res += nums[i];
            }
        }

        return res;
    }
};