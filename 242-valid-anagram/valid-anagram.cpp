class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphaHash[26] = {0};

        for(auto it: s){
            alphaHash[it - 'a']++;
        }
        for(auto it: t){
            alphaHash[it - 'a']--;
        }

        for(auto it: alphaHash) {
            if(it != 0) {
                return false;
            }
        }
        return true;
    }
};