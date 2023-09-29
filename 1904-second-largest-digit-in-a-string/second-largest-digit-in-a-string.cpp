class Solution {
public:
    int secondHighest(string s) {
        int largest01 = -1;
        int largest02 = -1;
        int n = s.size();

        for(int i=0; i<n; i++) {
            if(s[i] >= '0' && s[i]<= '9') {
                if(s[i]-'0' > largest01) {
                    largest02 = largest01;
                    largest01 = s[i] - '0';
                } else if( s[i]-'0' > largest02 && s[i]-'0' != largest01) {
                    largest02 = s[i] - '0';
                }

            }
        }
        return largest02;
        return (largest01==largest02)? -1 : largest02;
    }
};