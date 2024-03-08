class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int hash[101] = { 0 };

        int maxFreq = 0;
        int res = 0;
        for(int n: nums) {
            hash[n]++;

            if(hash[n] > maxFreq) {
                maxFreq = hash[n];
                res = maxFreq;
            } else if(hash[n] == maxFreq) {
                res += maxFreq;
            }
        }

        return res;

        
    }
};