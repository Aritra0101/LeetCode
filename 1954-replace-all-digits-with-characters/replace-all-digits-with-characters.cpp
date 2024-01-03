class Solution {
private:
    char shift(char ch, int x) {
        for(int i=0; i<x; i++) {
            ch++;
        }
        return ch;
    }
public:
    string replaceDigits(string s) {
        int n = s.size();

        for(int i=1; i<n; i+=2) {
            s[i] = shift(s[i-1], s[i]-'0');
        }

        return s;
    }
};