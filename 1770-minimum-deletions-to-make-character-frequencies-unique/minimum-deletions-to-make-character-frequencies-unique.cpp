class Solution {
public:
    int minDeletions(string s) {
        int hashAlpha[26] = {0};
        for(char ch: s)
            hashAlpha[ch-'a']++;

        for(auto it: hashAlpha)
            cout<<it<<" ";
        cout<<endl;
        sort(hashAlpha, hashAlpha+26);
        cout<<endl;
        for(auto it: hashAlpha)
            cout<<it<<" ";
        cout<<endl;

        int res=0, deleteCount;
        for(int i=26-1-1; i>=0; i--) {
            if(hashAlpha[i]!=0 && hashAlpha[i] >= hashAlpha[i+1]) {      
                deleteCount = (hashAlpha[i+1] - 1) < 0 ? 0 : (hashAlpha[i+1] - 1);
                res += hashAlpha[i] - deleteCount;
                hashAlpha[i] = hashAlpha[i+1] - 1;

            }
        }
        return res;
    }
};