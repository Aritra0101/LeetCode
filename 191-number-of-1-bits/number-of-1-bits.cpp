class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        uint32_t num = n;
        while(num) {
            if(num & 1)
                ans++;
            num = num>>1;
        }
        return ans;
    }

    // int hammingWeight(uint32_t n) {
    //     int ans = 0;
    //     while(n>0) {
    //         // cout<<n<<endl;
    //         // if(n%10==1)
    //         //     ans++;
    //         // n/=10;
    //         if(n%2==1)
    //             ans++;
    //         n/=2;
    //     }
    //     return ans;
    // }
};