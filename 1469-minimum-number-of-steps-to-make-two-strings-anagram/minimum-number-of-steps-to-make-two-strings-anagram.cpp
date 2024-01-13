class Solution {
public:
    int minSteps(string s, string t) {

        int hash[26] = {0};

        for(char ch: s) {
            hash[ch - 'a']++;
        }
        for(char ch: t) {
            hash[ch - 'a']--;
        }

        int count = 0;
        for(int n: hash) {
            count += abs(n);
        }

        return (count/2);
        
    }
};