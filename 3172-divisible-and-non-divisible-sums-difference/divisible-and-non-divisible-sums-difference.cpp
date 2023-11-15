class Solution {
public:
    // int differenceOfSums(int n, int m) {
    //     long num1 = 0;
    //     long num2 = 0;

    //     for(int i=1; i<=n; i++) {
    //         if(i % m == 0 ) {
    //             num2 += i;
    //         } else {
    //             num1 += i;
    //         }
    //     }

    //     return num1-num2;
    // }

    int differenceOfSums(int n, int m) {
        long num1 = (n * (n+1))/2;
        long num2 = 0;
        for(int i=m; i<=n; i+=m) {
            num2 += i;
        }
        num1 -= num2;
        return num1-num2;
    }
};