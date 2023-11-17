class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int targetSize = (n/4) + 1;
        cout<<targetSize<<endl;
        int res = arr[0];
        int ele = arr[0];
        int count = 1;
        for(int i=1; i<n; i++) {
            if(ele == arr[i]) {
                count++;
            } else {
                if(count >= targetSize) {
                    return ele;
                }
                ele = arr[i];
                count = 1;
            }
        }
        return ele;
        return 11;
    }
};