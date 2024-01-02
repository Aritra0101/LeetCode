class Solution {
public:
    int maxScore(string s) {
        int res = -1;
        int n = s.size();
        int countOne = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '1')
                countOne++;
        }

        int left=0, right=countOne;
        for(int i=0; i<n-1; i++) {
            if(s[i] == '1') {
                right--;
            } else {
                left++;
            }
            res = max(res, left+right);
        }

        return res;
    }
};