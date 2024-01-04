class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int, int> hashMap;
        for(auto it: nums) {
            hashMap[it]++;
        }

        int res = 0;
        for(auto it: hashMap) {        
            int num = it.second;
            int way = INT_MAX;
            cout<<it.first<<" "<<it.second;

            if(num%2==0)   way = min(way, num/2);
            cout<<" "<<way;
            if(num%3==0)   way = min(way, num/3);
            cout<<" "<<way;
            int curr = 0;
            while(num >= 3) {
                num -= 3;
                curr++;

                if(num%2==0)
                    way = min(way, curr+(num/2));
            }
            cout<<" "<<way;
            cout<<endl;
            // cout<<it.first<<" "<<it.second<<" "<<way<<endl;
            if(way == INT_MAX)
                return -1; 
            else
                res += way;
                                       
        }
        return res;
    }
};