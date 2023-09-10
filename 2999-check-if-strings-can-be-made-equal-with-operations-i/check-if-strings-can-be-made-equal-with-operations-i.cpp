class Solution {
public:
    // bool canBeEqual(string s1, string s2) {
    //     int n1 = s1.size();
    //     int n2 = s2.size();
        
    //     if(n1!=n2)
    //         return false;
        
    //     for(int i=0; i<n1-2; i++) {
    //         if(s1[i] != s2[i]) {
    //             swap(s1[i], s1[i+2]);
    //         }
            
    //         if(s1==s2)
    //             return true;
    //     }
        
    //     return false;
    // }

    bool canBeEqual(string s1, string s2) {
        int hashMap[2][26] = {0};
        int n = 4;
        for(int i=0; i<n; i++) {
            hashMap[i%2][ s1[i]-'a' ]++;
            hashMap[i%2][ s2[i]-'a' ]--;
        }

        // for(int i=0; i<26; i++)
        //     cout<<hashMap[0][i];
        // cout<<endl;
        // for(int i=0; i<26; i++)
        //     cout<<hashMap[1][i];

        for(int i=0; i<26; i++)
            if(hashMap[0][i] != 0 || hashMap[1][i] != 0)
                return false;
        
        return true;
    }
};