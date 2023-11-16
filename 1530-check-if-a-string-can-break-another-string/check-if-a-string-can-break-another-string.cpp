class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        string str1 = s1;
        string str2 = s2;

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        cout<<str1<<" "<<str2;

        int n = s1.size();

        if(str1[0] >= str2[0]) {
            int i;
            for(i=0; i<n; i++) {
                if(str1[i] < str2[i]) {
                    break;
                }
            }
            if(i==n)
                return true;
        }

        if(str1[0] <= str2[0]) {
            int i;
            for(i=0; i<n; i++) {
                if(str1[i] > str2[i]) {
                    break;
                }
            }
            if(i==n)
                return true;
        } 

        return false;
        return 11;
    }
};