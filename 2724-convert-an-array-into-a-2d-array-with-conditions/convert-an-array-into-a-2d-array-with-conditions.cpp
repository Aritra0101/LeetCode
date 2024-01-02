class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        vector<vector<int>> res;

        for(int n: nums) {
            int row = hashMap[n]++;

            if(row < res.size()) {
                res[row].emplace_back(n);
            } else {
                vector<int> arr(1, n);
                res.emplace_back(arr);
            }
        }

        return res;
    }
};