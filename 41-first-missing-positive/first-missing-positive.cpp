class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> numsSet( nums.begin(), nums.end() );
        int n = nums.size();

        for(int i=1; i<=n+1; i++) {
            if(numsSet.find(i) == numsSet.end()) {
                return i;
            }
        }

        return 11;
    }
};