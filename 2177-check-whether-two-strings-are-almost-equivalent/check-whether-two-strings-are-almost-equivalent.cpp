class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int hash01[26] = {0};
        int hash02[26] = {0};

        for(char ch : word1)
            hash01[ch - 'a']++;
        for(char ch : word2)
            hash02[ch - 'a']++;

        for(int i=0; i<26; i++)
            if( abs(hash01[i] - hash02[i]) > 3 )
                return false;
        return true;

        return 11;
    }
};