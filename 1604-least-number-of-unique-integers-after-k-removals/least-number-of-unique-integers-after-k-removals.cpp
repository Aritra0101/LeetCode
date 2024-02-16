class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> hashMap;

        for(int n: arr) {
            hashMap[n]++;
        }

        if(k==0) {
            return hashMap.size();
        }

        int uniqueSize = hashMap.size();
        vector<pair<int,int>> freqVal(uniqueSize);
        int i = 0;
        for(auto it: hashMap) {
            freqVal[i++] = {it.second, it.first};
        }

        sort(freqVal.begin(), freqVal.end());

        for(int i=0; i<uniqueSize; i++) {
            k -= freqVal[i].first;

            if(k<=0) {
                return k==0? uniqueSize-i-1 : uniqueSize-i;
            }
        }

        return 0;
    }
};