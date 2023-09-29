class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOne = 0;
        int n = s.size();
        for(char ch: s)
            if(ch == '1')
                countOne++;

        string res = "";
        for(int i=countOne-1; i>=1; i--) {
            res += '1';
        }
        for(int i=n-countOne; i>=1; i--) {
            res += '0';
        }
        res += '1';

        return res;
    }
};