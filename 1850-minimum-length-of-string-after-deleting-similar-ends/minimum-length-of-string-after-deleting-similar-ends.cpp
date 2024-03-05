class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();

        int start = 0;
        int end = n-1;

        while(start < end) {
             if(s[start] == s[end]) {
                while((start < (end-1)) && (s[start] == s[start+1])) {
                    start++;
                }
                while( ((start+1) < end) && (s[end-1] == s[end]) ) {
                end--;
                }
                start++;
                end--;
            } else {
                break;
            }
        }

        return end-start+1;
    }
};