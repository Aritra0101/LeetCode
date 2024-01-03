class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> res(2);
        res[0] = -1;
        res[1] = -1;

        int one;
        int i=0;
        for(auto row: mat) {
            one = 0;
            for(int ele: row) {
                if(ele) {
                    one++;
                }
            }
            if(one > res[1]) {
                res[0] = i;
                res[1] = one;
            }
            i++;
        }

        return res;
    }
};