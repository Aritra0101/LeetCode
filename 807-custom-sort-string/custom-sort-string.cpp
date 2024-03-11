class Solution {
public:
    string customSortString(string order, string s) {
        int hash[26] = { 0 };

        for(char ch: s) {
            hash[ch - 'a']++;
        }

        string res = "";

        for(char ch: order) {
            if(hash[ch - 'a']) {
                for(int i=0; i < hash[ch - 'a']; i++) {
                    res += ch;
                }
                hash[ch - 'a'] = 0;
            }
        }

        for(int i=0; i<26; i++) {
            if(hash[i]) {
                for(int j=0; j < hash[i]; j++) {
                    res += ('a' + i);
                }
            }
        }

        return res;
    }
};