class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> hashMap;

        if(n%k != 0)
            return false;

        for(int n: nums)
            hashMap[n]++;
        
        // for(const auto& [key, val]: hashMap)
        //     cout<<key<<" "<<val<<endl;

        while(1) {
            int start = hashMap.begin()->first;

            for(int i=0; i<k; i++) {
                if(hashMap[start+i] <= 0)
                    return false;

                hashMap[start+i]--;

                if(hashMap[start+i] == 0)
                    hashMap.erase(start+i);
            }

            if(hashMap.empty())
                break;
        }
        return true;;

    }
};