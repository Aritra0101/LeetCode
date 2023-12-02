class Solution {
private:
    bool isGoodString(string str, int* hash) {
        int hashMap[26] = {0};
        for(char ch: str) {
            hashMap[ch - 'a']++;
        }

        for(int i=0; i<26; i++) {
            if(hashMap[i] > hash[i]) {
                return false;
            }
        }
        return true;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        int hash[26] = {0};
        for(char ch: chars) {
            hash[ch-'a']++;
        }

        int res = 0;
        for(string str: words) {
            if( isGoodString(str, hash) ) {
                res += str.size();
            }
        }
        return res;
    }
};