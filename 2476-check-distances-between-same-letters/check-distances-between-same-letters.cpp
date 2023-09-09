class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        for(int i=0; i<n; i++) {
            if((i-1-distance[s[i]-'a']>=0 && s[i] == s[i-1-distance[s[i]-'a']]) || (i+1+distance[s[i]-'a']<n && s[i] == s[i+1+distance[s[i]-'a']])) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};