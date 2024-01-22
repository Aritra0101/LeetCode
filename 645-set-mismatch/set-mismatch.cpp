class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2, -1);
        unordered_map<int, int> hash;

        for(auto it: nums) {
            hash[it]++;
            if(hash[it] == 2) {
                ans[0] = it;
                // break;
            }
        }
        cout<<endl;
        for(auto it: hash) {
            cout<<it.first<<"   "<<it.second<<endl;
        }
        cout<<endl;
        for(int i=1; i<=n; i++) {
            if(hash[i] == 0) {
                ans[1] = i;
                break;
            }
        }

        return ans;
    }
};