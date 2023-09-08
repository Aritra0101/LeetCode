class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int* hash = new int[n];
        memset(hash, 0, n*sizeof(int));

        for(auto it: nums)
            if(it < n)
                hash[it]++;
            else
                return false;

        for(int i=1; i<n-1; i++) 
            if(hash[i] < 1 || hash[i] > 1)
                return false;

        if(hash[n-1] == 2)
            return true;
        return false;
    }
};