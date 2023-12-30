class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int hashAlpha[26] = {0};

        for(string str: words) {
            for(char ch: str) {
                hashAlpha[ch - 'a']++;
            }
        }

        int n = words.size();
        for(int i=0; i<26; i++) {
            if(hashAlpha[i] % n != 0) {
                return false;
            }
        }

        return true;
    }
};