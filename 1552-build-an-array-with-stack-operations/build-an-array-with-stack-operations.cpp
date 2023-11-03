class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int nn = target.size();
        int m = 0;
        
        for(int i=1; i<=n && m<nn; i++) {
            if( target[m] == i ) {
                res.emplace_back("Push");
                m++;
            } else {
                res.emplace_back("Push");
                res.emplace_back("Pop");
            }
        }

        return res;
    }
};