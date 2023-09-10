class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if(n1!=n2)
            return false;
        
        for(int i=0; i<n1-2; i++) {
            if(s1[i] != s2[i]) {
                swap(s1[i], s1[i+2]);
            }
            
            if(s1==s2)
                return true;
        }
        
        return false;
    }
};