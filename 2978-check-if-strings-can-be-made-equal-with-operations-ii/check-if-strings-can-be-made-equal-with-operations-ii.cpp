class Solution {
public:
    // bool checkStrings(string s1, string s2) {
    //     int n = s1.size();
    //     bool isSwapped = false;
        
    //     // if(n==1)
    //     //     return s1==s2;
    //     // if(n==2)
    //     //     return s1==s2;
        
    //     for(int i=0; i<n-2; i++) {
    //         if(s1[i] != s2[i]) {
    //             isSwapped = false;
    //             // cout<<s1<<" "<<s2<<"  --->  ";
    //             for(int j=i+2; j<n; j+=2) {
    //                 // cout<<" "<<s1[j]<<" ";
    //                 if(s1[j] == s2[i]) {
    //                     isSwapped = true;
    //                     swap(s1[i], s1[j]);
    //                     break;
    //                 }
    //             }
    //             // cout<<s1<<" "<<s2<<endl;
                
    //             if(isSwapped == false) {
    //                 return false;
    //             }
    //         }
            
    //         if(s1==s2)
    //             return true;
    //     }
    //     return s1==s2;     
    // }

    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        int hashMap[2][26] = {0};
        
        for(int i=0; i<n; i++) {
            hashMap[i%2][ s1[i]-'a' ]++;
            hashMap[i%2][ s2[i]-'a' ]--;
        }

        for(int i=0; i<26; i++)
            if(hashMap[0][i]!=0 || hashMap[1][i]!=0)
                return false;
        
        return true;
    }

};