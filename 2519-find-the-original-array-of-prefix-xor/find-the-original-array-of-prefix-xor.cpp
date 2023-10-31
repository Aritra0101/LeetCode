class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.begin(), pref.end());
        int n = pref.size();
        int xxor = pref[0];

        for(int i=1; i<n; i++) {
            res[i] = (xxor ^ pref[i]);
            xxor = xxor ^ res[i];
        }

        return res;
    }
};