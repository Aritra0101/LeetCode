class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hashMap_s2t;
        unordered_map<char,char> hashMap_t2s;
        int n = s.size();

        for(int i=0; i<n; i++) {
            if(hashMap_s2t.find(s[i]) == hashMap_s2t.end()) {
                hashMap_s2t[s[i]] = t[i];
            } else {
                if(hashMap_s2t[s[i]] == t[i])
                    continue;
                else
                    return false;
            }

            if(hashMap_t2s.find(t[i]) == hashMap_t2s.end()) {
                hashMap_t2s[t[i]] = s[i];
            } else {
                if(hashMap_t2s[t[i]] == s[i])
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         int a[256]={0};
//         int b[256]={0};
//     for(int i=0;i<s.size();i++){
//          if( a[s[i]]!= b[t[i]]){
//             return false;
//         }
//         a[s[i]]=i+1;
//         b[t[i]]=i+1;
       
//     }
//     return true;
//     }
// };