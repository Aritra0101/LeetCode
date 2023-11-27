class Solution {
private:
    struct NODE {
        int leftFreq = 0;
        int rightFreq = 0;
        long long leftPreSum = 0;
        long long rightPreSum = 0;
    };
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, NODE> hashMap;

        for(int i=0; i<n; i++) {
            // hashMap[nums[i]].leftFreq = 0;
            // hashMap[nums[i]].leftPreSum = 0; 

            hashMap[ nums[i] ].rightFreq += 1;
            hashMap[ nums[i] ].rightPreSum += i;
        }

        vector<long long> res(n);
        for(int i=0; i<n; i++) {
            res[i] = ((hashMap[nums[i]].leftFreq * static_cast<long long>(i))-hashMap[nums[i]].leftPreSum) + (hashMap[nums[i]].rightPreSum - (hashMap[nums[i]].rightFreq * static_cast<long long>(i)));

            hashMap[nums[i]].leftFreq++;
            hashMap[nums[i]].rightFreq--;

            hashMap[nums[i]].leftPreSum += i;
            hashMap[nums[i]].rightPreSum -= i;
        }
        return res;

    }


    // vector<long long> distance(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<long long> arr(n);
        
    //     map<int, vector<int>> hashMap;
    //     for(int i=0; i<n; i++) {
    //         hashMap[ nums[i] ].emplace_back(i);
    //     }
    //     // freq, cur, total
    //     unordered_map<int, pair<pair<int, int>, pair<long long, long, long>> preSum;
    //     for(const auto& [key, vec]: hashMap) {
    //         preSum[key].first = hashMap[key].size();
    //     }

    //     // for (const auto& [key, vec] : hashMap) {
    //     //     cout << key << " --> ";
    //     //     for(auto it: vec)
    //     //         cout<<it<<" ";
    //     //     cout<<endl;
    //     // }

    //     for(int i=0; i<n; i++) {
    //         if( hashMap[ nums[i] ].size() == 1 ) {
    //             arr[i] = 0;
    //         } else {
    //             temp = 11;
    //             // for(auto it: hashMap[ nums[i] ])
    //             //     temp += abs(i-it);
    //             arr[i] = temp;
    //         }
    //     }

    //     return arr;
    // }
};