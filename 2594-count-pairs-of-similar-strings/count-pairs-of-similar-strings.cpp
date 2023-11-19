class Solution {
private:
    string getKey(string str) {
        int hash[26] = {0};
        for(char ch: str) {
            hash[ch - 'a']++;
        }
        string res = "";
        for(int i=0; i<26; i++) {
            if(hash[i] > 0) {
                res += ('a'+i);
            }
        }
        return res;
    }
public:
    int similarPairs(vector<string>& words) {
        unordered_map<string, int> hashMap;
        int res = 0;
        string key;
        for(string str: words) {
            key = getKey(str);

            if(hashMap[key]) {
                res += hashMap[key];
                hashMap[key] += 1;
            } else {
                hashMap[key] = 1;
            }
        }

        return res;
    }
};