class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int hashAlpha[26];
        memset(hashAlpha, -1, 26*sizeof(int));
        
        int res = -1;
        int ind = 0;
        for(char ch: s) {
            if(hashAlpha[ch - 'a'] == -1) {
                hashAlpha[ch - 'a'] = ind;
            } else {
                res = max(res, ind-hashAlpha[ch - 'a']-1);
                cout<<ch<<" "<<res<<endl;
                // hashAlpha[ch - 'a'] = ind;
            }

            ind++;
        }

        return res;
    }
};