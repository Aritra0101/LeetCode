class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        vector<int> myArr(arr.begin(), arr.end());
        sort(myArr.begin(), myArr.end());
        int maxi = INT_MIN;
        myArr[0] = 1;
        int n = arr.size();
        maxi = myArr[0];
        for(int i=1; i<n; i++) {
            if( abs(myArr[i-1] - myArr[i]) <= 1) {
            } else {
                myArr[i] = myArr[i-1]+1;
            }

            maxi = max(maxi, myArr[i]);
        }
        return maxi;
    }
};