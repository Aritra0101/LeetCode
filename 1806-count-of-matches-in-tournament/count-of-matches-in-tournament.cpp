class Solution {
public:
    int numberOfMatches(int n) {
        return (n-1);
    }
    // int numberOfMatches(int n) {
    //     int num=n, ans=0;
    //     if(n<=2) { return n/2; }
    //     while(num>=2) {
    //         ans += (num/2);
    //         if(num%2==0)    num/=2;
    //         else    num = (num/2)+1;
    //     }
    //     return ans;
    // }
};