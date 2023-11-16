class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> myArr;
        int n = nums.size();
        myArr.emplace_back(nums[0]);
        for(int i=0, j=0; i<n; i++) {
            if(myArr[j] != nums[i]) {
                myArr.emplace_back( nums[i] );
                j++;
            }
        }
        n = myArr.size();
        int res = 0;
        for(int i=1; i<n-1; i++) {
            if((myArr[i] > myArr[i-1]) && (myArr[i] > myArr[i+1])) {
                res++;
            } else if((myArr[i] < myArr[i-1]) && (myArr[i] < myArr[i+1])) {
                res++;
            }
        }
        return res;
    }
};