class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        int i=0;
        while(s[i] == '1')
            i++;
        
        for( ; i<n; i++)
            if(s[i] == '1')
                return false;
                
        return true;
    }
};