class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int, vector<int>> map;
        int n = nums.size(), m;
        for(int i=0; i<n; i++) {
            m = nums[i].size();
            for(int j=0; j<m; j++) {
                map[i+j].emplace_back(nums[i][j]);
            }
        }

        vector<int> res;
        for(auto it: map) {
            // copy(it.second.begin(), it.second.end(), back_inserter(res));
            res.insert(res.end(), it.second.rbegin(), it.second.rend()); 
        }
        return res;
    }
};