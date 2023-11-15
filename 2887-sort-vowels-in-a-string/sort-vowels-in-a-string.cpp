class Solution {
private:
    bool isVowel(char c) {
    string str = "aeiouAEIOU";
    for(char ch: str)
        if(ch == c)
            return true;
    return false;
}
public:
    string sortVowels(string s) {
        string res = s;
        int n = s.size();
        vector<bool> vowelInd(n, false);
        vector<char> vowels;

        for(int i=0; i<n; i++) {
            if( isVowel(s[i]) ) {
                vowelInd[i] = true;
                vowels.emplace_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());
        int ind=0;
        for(int i=0; i<n; i++) {
            if(vowelInd[i]) {
                res[i] = vowels[ind++];
            }
        }

        return res;
    }
};