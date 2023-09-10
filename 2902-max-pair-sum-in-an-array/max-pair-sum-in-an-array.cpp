class Solution {
private:
    int getMaxDigit(int num) {
        int maxi = -1;
        while(num>0) {
            maxi = max(maxi, num%10);
            num /= 10;
        }
        maxi = max(maxi, num);
        return maxi;
    }
public:
    int maxSum(vector<int>& nums) {
        int res = INT_MIN;
        int hashMap[10] = {0};
        int maxDigit = -1;

        for(int n: nums) {
            maxDigit = getMaxDigit(n);
            if(hashMap[maxDigit] == 0) {
                hashMap[maxDigit] = n;
            } else {
                res = max(res, hashMap[maxDigit] + n);
                hashMap[maxDigit] = max(hashMap[maxDigit], n);
            }
        }

        return (res==INT_MIN) ? -1 : res;
    }
};