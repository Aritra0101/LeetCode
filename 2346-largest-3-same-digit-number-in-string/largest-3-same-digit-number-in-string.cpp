class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        int n = num.size();

        for(int i=0; i<n-3+1; i++) {
            if(num[i] == num[i+1] && num[i] == num[i+2]) {
                if(res == "" || res[0] < num[i]) {
                    res = num.substr(i, 3);
                }
            }
        }
        return res;
    }
};