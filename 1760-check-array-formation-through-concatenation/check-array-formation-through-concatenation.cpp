class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, vector<int>> hashMap;
        int nn=0;
        for(auto it: pieces) {
            hashMap[it[0]] = it;
            nn += it.size();
        }

        int n = arr.size();
        if(n!=nn)
            return false;

        for(const auto& [key, arr]: hashMap) {
            cout<<key<<" -->  ";
            for(auto it: arr) {
                cout<<it<<" ";
            }
            cout<<endl;
        }

        int key;
        for(int i=0; i<n; i++) {
            key = arr[i]; 
            if(hashMap.find(key) == hashMap.end()) {
                return false;
            }
            else {
                int nnn = hashMap[key].size();
                for(int j=0; j<nnn; j++) {
                    if(arr[i+j] == hashMap[key][j])
                        continue;
                    else
                        return false;
                }
                i += nnn-1;
            }
        }
        return true;
    }
};