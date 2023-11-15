class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int hashMap[1001] = {0};
        int n = arr.size();

        for(int i=0; i<n; i++) {
            hashMap[ target[i] ]++;
            hashMap[ arr[i] ]--;
        }

        for(int i=0; i<1001; i++) {
            if(hashMap[i] != 0)
                return false;
        }
        return true;
    }
};