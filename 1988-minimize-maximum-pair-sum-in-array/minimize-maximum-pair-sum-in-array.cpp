class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int> myNums(nums.begin(), nums.end());
        sort( myNums.begin(), myNums.end() );

        int n = nums.size();
        int ptr01=0, ptr02=n-1;
        int res = INT_MIN;
        while(ptr01 < ptr02) {
            res = max(res, myNums[ptr01]+myNums[ptr02]);
            ptr01++;
            ptr02--;
        }
        return res;
    }
};