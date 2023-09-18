class Solution {
private: 
    void merge(vector<int>& arr, int beg, int mid, int end) {
        int n1 = mid-beg+1;
        int n2 = end-mid;
        vector arr1(arr.begin()+beg, arr.begin()+mid+1);
        vector arr2(arr.begin()+mid+1, arr.begin()+end+1);

        // cout<<n1<<"-"<<arr1.size()<<" - "<<n2<<"-"<<arr2.size()<<endl;
        // for(auto it: arr1)
        //     cout<<it<<" ";
        // cout<<endl;
        // for(auto it: arr2)
        //     cout<<it<<" ";
        // cout<<endl;
        // cout<<endl;

        // sort(arr1.begin(), arr1.end());
        // sort(arr2.begin(), arr2.end());

        int i=0, j=0, k=beg;
        while(i<n1 && j<n2) {
            if(arr1[i] < arr2[j]) {
                arr[k++] = arr1[i++];
            } else if(arr1[i] > arr2[j]) {
                arr[k++] = arr2[j++];
            } else {
                arr[k++] = arr1[i++];
                arr[k++] = arr2[j++];
            }
        }
        while(i<n1) {
            arr[k++] = arr1[i++];
        }
        while(j<n2) {
            arr[k++] = arr2[j++];
        }
        
        arr1.clear();
        arr2.clear();
    }
    
    void mergeSort(vector<int>& arr, int beg, int end) {
        int n = arr.size();
        if(beg < end) {
            int mid = beg + (end-beg)/2;
            // cout<<beg<<" "<<mid<<" "<<end<<endl;
            mergeSort(arr, beg, mid);
            mergeSort(arr, mid+1, end);
            merge(arr, beg, mid, end);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};