class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> hashMap;
        int n = dominoes.size();
        int res = 0;
        int key;
        for(const auto& it: dominoes) {
            if(it[0] > it[1]) {
                key = (it[1]*10)+it[0];
            } else {
                key = (it[0]*10)+it[1];
            }

            if(hashMap[key]) {
                res += hashMap[key];
                hashMap[key]++;
            } else {
                hashMap[key] = 1;
            }
        }
        return res;
    }
};