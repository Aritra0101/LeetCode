class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int n = k;
        int res = 0;
        int pick;

        pick = min(n, numOnes);
        res += (pick * 1);
        n -= pick;

        pick = min(n, numZeros);
        res += (pick * 0);
        n -= pick;

        pick = min(n, numNegOnes);
        res += (pick * (-1));
        n -= pick;



        return res;
    }
};