class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n%3 != 0) {
            return res;
        }
        sort( nums.begin(), nums.end() );
        for(int i=0; i<n-2; i+=3) {
            if((nums[i+2] - nums[i]) > k) {
                res.clear();
                return res;
            } else {
                res.emplace_back( vector<int>(nums.begin()+i, nums.begin()+i+3) );
            }
        }

        return res;
    }
};