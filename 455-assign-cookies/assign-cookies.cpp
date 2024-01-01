class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gg=0, ss=0;
        int nG = g.size();
        int nS = s.size();

        int res = 0;
        while(gg<nG && ss<nS) {
            if(g[gg] <= s[ss]) {
                gg++;
                ss++;

                res++;
            } else {
                ss++;
            }
        }
        return res;
    }
};