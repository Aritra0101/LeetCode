class Solution {
private:
    void rightShift(vector<int>& arr, int i, int n) {
        for(int j = n-1; j>i; j--) {
            arr[j] = arr[j-1];
        }
    }
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        auto beg = arr.begin();
        for(int i=0; i<n-1; i++) {
            if(arr[i] == 0) {
                rightShift(arr, i, n);
                arr[i+1] = 0;
                i++;
            }
        }
    }
};