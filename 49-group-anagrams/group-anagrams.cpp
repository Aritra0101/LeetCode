class Solution {
private:
    string genKey(string s) {
        int hash[26] = {0};
        string res = "";

        for(char ch: s)
            hash[ch - 'a']++;
        
        for(int n: hash)
            res += n;

        return res;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hashMap;
        vector<vector<string>> res;

        string key;
        for(string str:strs) {
            key = genKey(str);
            hashMap[key].push_back(str);
        }

        for(const auto& [key, vec]: hashMap)
            res.emplace_back(vec);
        return res;        
    }
};



// class Solution {
//  public:
//   vector<vector<string>> groupAnagrams(vector<string>& strs) {
//     vector<vector<string>> ans;
//     unordered_map<string, vector<string>> keyToAnagrams;

//     for (const string& str : strs) {
//       string key = str;
//       sort(key.begin(), key.end());
//       keyToAnagrams[key].push_back(str);
//     }

//     for (const auto& [_, anagrams] : keyToAnagrams)
//       ans.push_back(anagrams);

//     return ans;
//   }
// };