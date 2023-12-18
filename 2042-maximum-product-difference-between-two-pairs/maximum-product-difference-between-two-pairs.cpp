class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        
        vector<int> myArr(nums.begin(), nums.end());
        sort(myArr.begin(), myArr.end());

        int n = nums.size();
        int res = (myArr[n-1]*myArr[n-2]) - (myArr[0]*myArr[1]);
        return res;
    }
};