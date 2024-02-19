class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n==1 || n==2)
            return true;
        if(n%2 != 0 || n==0)
            return false;
        
        return isPowerOfTwo(n/2);


        // if(n == 0)
        // return false;

        // if (floor(log2(n))==ceil(log2(n)))
        // return true;
        // else
        // return false;
    }
};