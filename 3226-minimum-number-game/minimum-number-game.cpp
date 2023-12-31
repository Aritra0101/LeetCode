class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {

        vector<int> res(nums.begin(), nums.end());
        sort(res.begin(), res.end());

        int n = res.size();
        for(int i=0; i<n; i+=2) {
            swap(res[i], res[i+1]);
        }

        return res;
    }
};