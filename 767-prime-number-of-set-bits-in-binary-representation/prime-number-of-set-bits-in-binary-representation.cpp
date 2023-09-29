class Solution {
bool isPrime(int n) {
    if(n<2)
        return false;
    for(int i=2; i*i<=n; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
public:
    int countPrimeSetBits(int left, int right) {
        int res=0, countBits;
        set<int> primes;

        for(int i=left; i<=right; i++) {
            countBits = __builtin_popcount(i);
            if( isPrime(countBits) )
                res++;
        }
        return res;
    }
};