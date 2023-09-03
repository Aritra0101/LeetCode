class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        map<int, int> hashMap;

        for(auto it: nums) {
            if( hashMap.find(it) != hashMap.end() )
                continue;
            else {
                if( hashMap.find(it-diff) == hashMap.end() )
                    hashMap[it] = 1;
                else 
                    hashMap[it] = hashMap[it-diff]+1;
            }
        }

        int ans = 0;
        for(const auto& [key, val] : hashMap) {
            // cout<<key<<"  "<<val<<endl;
            if(val >= 3)
                ans++;
        }
        return ans;
    }
};