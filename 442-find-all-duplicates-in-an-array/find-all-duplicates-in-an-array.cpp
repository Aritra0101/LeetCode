class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //unordered_map<int, int> hash;
        map<int, int> hash;
        vector<int> ans;

        for(auto it: nums) {
            if(hash[it]) {
                ans.emplace_back(it);
            } else {
                hash[it] = 1;
            }
        }

        return ans;
    }
};