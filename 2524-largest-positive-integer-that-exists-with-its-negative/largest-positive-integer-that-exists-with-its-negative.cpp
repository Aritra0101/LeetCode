class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res = -1;
        int hashMap[2001] = {0};

        for(int n: nums) {
            hashMap[n+1000] = 11;

            if( hashMap[(-1 * n ) +1000] ) {
                res = max(res, abs(n));
            }
        }

        return res;
    }
};