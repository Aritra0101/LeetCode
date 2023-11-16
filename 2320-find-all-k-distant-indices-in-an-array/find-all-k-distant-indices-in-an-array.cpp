class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> res;
        int ind = 0;
        for(int i=0; i<n; i++) {
            if( nums[i] ==  key) {
                for(int j=max(ind, i-k); j<min(n, i+k+1); j++) {
                    res.emplace_back(j);
                }

                ind =min(n, i+k+1);
            }
        }

        return res;
    }
};